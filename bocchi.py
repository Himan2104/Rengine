import sys
import os
import re

from PySide6.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QFormLayout, QPushButton, QLineEdit, QFileDialog, QScrollArea,
    QCheckBox, QPlainTextEdit, QGroupBox, QComboBox, QMessageBox,
    QToolButton
)
from PySide6.QtCore import Qt, QProcess
from PySide6.QtGui import QIcon


class CollapsibleBox(QWidget):
    """
    A simple collapsible widget that uses a QToolButton as header (with an arrow)
    and a content area that can be expanded or collapsed.
    """
    def __init__(self, title="", parent=None):
        super().__init__(parent)
        self.toggle_button = QToolButton()
        self.toggle_button.setStyleSheet("QToolButton { border: none; }")
        self.toggle_button.setToolButtonStyle(Qt.ToolButtonTextBesideIcon)
        self.toggle_button.setText(title)
        self.toggle_button.setCheckable(True)
        self.toggle_button.setChecked(False)
        self.toggle_button.setArrowType(Qt.RightArrow)
        self.toggle_button.clicked.connect(self.on_toggle)

        self.content_area = QWidget()
        # Start collapsed.
        self.content_area.setMaximumHeight(0)
        self.content_area.setMinimumHeight(0)
        self.content_layout = QVBoxLayout()
        self.content_layout.setContentsMargins(20, 0, 0, 0)  # indent children
        self.content_area.setLayout(self.content_layout)

        main_layout = QVBoxLayout(self)
        main_layout.setContentsMargins(0, 0, 0, 0)
        main_layout.addWidget(self.toggle_button)
        main_layout.addWidget(self.content_area)

    def on_toggle(self, checked):
        if checked:
            self.toggle_button.setArrowType(Qt.DownArrow)
            self.content_area.setMaximumHeight(16777215)
        else:
            self.toggle_button.setArrowType(Qt.RightArrow)
            self.content_area.setMaximumHeight(0)

    def addWidget(self, widget):
        self.content_layout.addWidget(widget)


def parse_cmake_options(project_dir):
    """
    Walk the project directory searching for CMakeLists.txt files. For each file,
    extract 'option(...)' relevant to CMake.

    The options are grouped by the folder in which the file is found.
    Returns a dict mapping group names to a list of option dicts:
        { "GroupName": [ { "name": ..., "description": ..., "default": True/False }, ... ] }
    """
    groups = {}
    for root, dirs, files in os.walk(project_dir):
        for file in files:
            if file.lower() == "cmakelists.txt":
                file_path = os.path.join(root, file)
                relative = os.path.relpath(root, project_dir)
                group_name = "Root" if relative == "." else relative
                try:
                    with open(file_path, "r") as f:
                        content = f.read()
                        # Match option(MY_OPTION "Description" ON/OFF)
                        pattern = r'option\s*\(\s*([A-Za-z0-9_]+)\s+"(.*?)"\s+(ON|OFF)\s*\)'
                        matches = re.findall(pattern, content, re.IGNORECASE)
                        for opt, desc, default in matches:
                            option_entry = {
                                "name": opt,
                                "description": desc,
                                "default": (default.upper() == "ON")
                            }
                            if group_name not in groups:
                                groups[group_name] = []
                            groups[group_name].append(option_entry)
                except Exception as e:
                    print(f"Error reading {file_path}: {e}")
    return groups


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("CMake GUI Build Tool")
        self.resize(800, 600)
        self.dark_mode = False

        # In-memory configuration storage.
        self.configurations = {}
        # Dictionary to hold QCheckBox widgets for CMake options.
        # Structure: { group_name: { option_name: QCheckBox, ... }, ... }
        self.cmake_option_widgets = {}

        self.init_ui()

    def init_ui(self):
        # Create central widget with a vertical layout.
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.main_layout = QVBoxLayout(self.central_widget)

        # --- Top bar with the dark/light toggle at the right ---
        top_bar = QHBoxLayout()
        top_bar.addStretch()
        self.theme_button = QToolButton()
        self.theme_button.setAutoRaise(True)
        self.theme_button.clicked.connect(self.toggle_theme)
        self.update_theme_icon()
        top_bar.addWidget(self.theme_button)
        self.main_layout.addLayout(top_bar)

        # --- Group: Project Directory ---
        proj_group = QGroupBox("Project Directory")
        proj_layout = QHBoxLayout()
        self.project_path_line_edit = QLineEdit()
        proj_layout.addWidget(self.project_path_line_edit)
        browse_proj_btn = QPushButton("Browse")
        browse_proj_btn.clicked.connect(self.browse_project_directory)
        proj_layout.addWidget(browse_proj_btn)
        scan_btn = QPushButton("Scan CMake Options")
        scan_btn.clicked.connect(self.scan_project)
        proj_layout.addWidget(scan_btn)
        proj_group.setLayout(proj_layout)
        self.main_layout.addWidget(proj_group)

        # --- Group: Configuration Management ---
        config_group = QGroupBox("Configuration Management")
        config_layout = QFormLayout()
        self.config_name_line_edit = QLineEdit()
        config_layout.addRow("Configuration Name:", self.config_name_line_edit)
        # Build Directory row with a Browse button.
        build_dir_layout = QHBoxLayout()
        self.build_dir_line_edit = QLineEdit()
        build_dir_layout.addWidget(self.build_dir_line_edit)
        browse_build_btn = QPushButton("Browse")
        browse_build_btn.clicked.connect(self.browse_build_directory)
        build_dir_layout.addWidget(browse_build_btn)
        config_layout.addRow("Build Directory:", build_dir_layout)
        self.flags_line_edit = QLineEdit()
        config_layout.addRow("CMake Flags:", self.flags_line_edit)
        self.custom_options_text_edit = QPlainTextEdit()
        config_layout.addRow("Custom CMake Options:", self.custom_options_text_edit)
        config_group.setLayout(config_layout)
        self.main_layout.addWidget(config_group)

        # --- Configuration actions: Save & Dropdown ---
        config_btn_layout = QHBoxLayout()
        save_config_btn = QPushButton("Save Configuration")
        save_config_btn.clicked.connect(self.save_configuration)
        config_btn_layout.addWidget(save_config_btn)
        self.config_combo_box = QComboBox()
        self.config_combo_box.currentTextChanged.connect(self.on_config_selection_changed)
        config_btn_layout.addWidget(self.config_combo_box)
        self.main_layout.addLayout(config_btn_layout)

        # --- Group: CMake Options with collapsible foldouts ---
        options_group = QGroupBox("CMake Options")
        options_layout = QVBoxLayout()
        self.options_scroll = QScrollArea()
        self.options_scroll.setWidgetResizable(True)
        self.options_container = QWidget()
        self.options_container_layout = QVBoxLayout(self.options_container)
        self.options_scroll.setWidget(self.options_container)
        options_layout.addWidget(self.options_scroll)
        options_group.setLayout(options_layout)
        self.main_layout.addWidget(options_group)

        # --- Build Section: Run Build button and log output ---
        build_section_layout = QVBoxLayout()
        self.build_button = QPushButton("Run Build")
        self.build_button.clicked.connect(self.run_build)
        build_section_layout.addWidget(self.build_button)
        self.log_text_edit = QPlainTextEdit()
        self.log_text_edit.setReadOnly(True)
        build_section_layout.addWidget(self.log_text_edit)
        self.main_layout.addLayout(build_section_layout)

    def update_theme_icon(self):
        # In light mode, display a moon (🌙) to hint "go dark".
        # In dark mode, display a sun (☀) to switch back to light.
        if self.dark_mode:
            self.theme_button.setText("☀")
        else:
            self.theme_button.setText("🌙")
        self.theme_button.setToolTip("Toggle Theme")

    def toggle_theme(self):
        self.dark_mode = not self.dark_mode
        if self.dark_mode:
            self.apply_dark_theme()
        else:
            self.apply_light_theme()
        self.update_theme_icon()

    def apply_dark_theme(self):
        dark_stylesheet = """
        QWidget {
            background-color: #2b2b2b;
            color: #f0f0f0;
        }
        QLineEdit, QTextEdit, QPlainTextEdit {
            background-color: #3c3c3c;
            color: #f0f0f0;
        }
        QPushButton, QToolButton {
            background-color: #3c3c3c;
            color: #f0f0f0;
            border: 1px solid #555;
            padding: 5px;
        }
        QComboBox {
            background-color: #3c3c3c;
            color: #f0f0f0;
        }
        """
        self.setStyleSheet(dark_stylesheet)

    def apply_light_theme(self):
        self.setStyleSheet("")

    def browse_project_directory(self):
        folder = QFileDialog.getExistingDirectory(self, "Select Project Directory", os.getcwd())
        if folder:
            self.project_path_line_edit.setText(folder)

    def browse_build_directory(self):
        folder = QFileDialog.getExistingDirectory(self, "Select Build Directory", os.getcwd())
        if folder:
            self.build_dir_line_edit.setText(folder)

    def scan_project(self):
        project_dir = self.project_path_line_edit.text().strip()
        if not os.path.isdir(project_dir):
            QMessageBox.warning(self, "Error", "Invalid project directory.")
            return
        groups = parse_cmake_options(project_dir)
        self.populate_options(groups)
        total_options = sum(len(v) for v in groups.values())
        self.append_log(f"Scanned project: found {total_options} CMake option(s).\n")

    def populate_options(self, groups):
        # Clear any existing content.
        for i in reversed(range(self.options_container_layout.count())):
            item = self.options_container_layout.takeAt(i)
            if item.widget():
                item.widget().deleteLater()
        self.cmake_option_widgets = {}

        # Create a collapsible box for each group.
        for group, options in groups.items():
            box = CollapsibleBox(title=group)
            self.cmake_option_widgets[group] = {}
            for option in options:
                cb = QCheckBox(f"{option['name']}: {option['description']}")
                cb.setChecked(option['default'])
                box.addWidget(cb)
                self.cmake_option_widgets[group][option['name']] = cb
            self.options_container_layout.addWidget(box)
        self.options_container_layout.addStretch()  # push content to the top

    def save_configuration(self):
        config_name = self.config_name_line_edit.text().strip()
        if not config_name:
            QMessageBox.warning(self, "Error", "Please enter a configuration name.")
            return

        config = {
            "build_dir": self.build_dir_line_edit.text().strip(),
            "flags": self.flags_line_edit.text().strip(),
            "custom_options": self.custom_options_text_edit.toPlainText().strip(),
            "cmake_options": {}
        }
        # Save the state of each checkbox.
        for group, opts in self.cmake_option_widgets.items():
            config["cmake_options"][group] = {}
            for opt, widget in opts.items():
                config["cmake_options"][group][opt] = widget.isChecked()
        self.configurations[config_name] = config
        if self.config_combo_box.findText(config_name) == -1:
            self.config_combo_box.addItem(config_name)
        QMessageBox.information(self, "Configuration Saved", f"Configuration '{config_name}' saved successfully.")

    def on_config_selection_changed(self, config_name):
        if not config_name:
            return
        config = self.configurations.get(config_name, {})
        if config:
            self.build_dir_line_edit.setText(config.get("build_dir", ""))
            self.flags_line_edit.setText(config.get("flags", ""))
            self.custom_options_text_edit.setPlainText(config.get("custom_options", ""))
            cmake_opts = config.get("cmake_options", {})
            for group, opts in cmake_opts.items():
                if group in self.cmake_option_widgets:
                    for opt, state in opts.items():
                        if opt in self.cmake_option_widgets[group]:
                            self.cmake_option_widgets[group][opt].setChecked(state)

    def append_log(self, text):
        """Append text to log and auto-scroll to the latest."""
        self.log_text_edit.appendPlainText(text)
        scrollBar = self.log_text_edit.verticalScrollBar()
        scrollBar.setValue(scrollBar.maximum())

    def run_build(self):
        config_name = self.config_combo_box.currentText()
        if config_name not in self.configurations:
            QMessageBox.warning(self, "Error", "No valid configuration selected.")
            return
        config = self.configurations[config_name]
        project_dir = self.project_path_line_edit.text().strip()
        if not os.path.isdir(project_dir):
            QMessageBox.warning(self, "Error", "Invalid project directory.")
            return
        build_dir = config.get("build_dir")
        if not build_dir:
            QMessageBox.warning(self, "Error", "Build directory not specified in configuration.")
            return
        if not os.path.exists(build_dir):
            try:
                os.makedirs(build_dir)
            except Exception as e:
                QMessageBox.critical(self, "Error", f"Failed to create build directory: {e}")
                return

        # Build the CMake configuration command.
        cmd = ["cmake", project_dir]
        if config.get("flags"):
            cmd.extend(config["flags"].split())
        if config.get("custom_options"):
            cmd.extend(config["custom_options"].split())
        # Append each CMake option from the checkboxes.
        for group, opts in self.cmake_option_widgets.items():
            for opt, widget in opts.items():
                value = "ON" if widget.isChecked() else "OFF"
                cmd.append(f"-D{opt}={value}")

        self.append_log("Running CMake configuration:")
        self.append_log(" ".join(cmd) + "\n")

        # Run the configuration step asynchronously using QProcess.
        self.config_process = QProcess(self)
        self.config_process.setProcessChannelMode(QProcess.MergedChannels)
        self.config_process.setWorkingDirectory(build_dir)
        self.config_process.readyReadStandardOutput.connect(self.handle_config_output)
        self.config_process.finished.connect(
            lambda exitCode, exitStatus: self.handle_config_finished(exitCode, exitStatus, build_dir)
        )
        self.config_process.start(cmd[0], cmd[1:])

    def handle_config_output(self):
        output = self.config_process.readAllStandardOutput().data().decode()
        self.append_log(output)

    def handle_config_finished(self, exitCode, exitStatus, build_dir):
        self.append_log(f"\nCMake configuration finished with exit code: {exitCode}\n")
        self.append_log("Starting Build Process:\n")
        build_cmd = ["cmake", "--build", "."]
        self.append_log(" ".join(build_cmd) + "\n")

        # Run the build asynchronously.
        self.build_process = QProcess(self)
        self.build_process.setProcessChannelMode(QProcess.MergedChannels)
        self.build_process.setWorkingDirectory(build_dir)
        self.build_process.readyReadStandardOutput.connect(self.handle_build_output)
        self.build_process.finished.connect(self.handle_build_finished)
        self.build_process.start(build_cmd[0], build_cmd[1:])

    def handle_build_output(self):
        output = self.build_process.readAllStandardOutput().data().decode()
        self.append_log(output)

    def handle_build_finished(self, exitCode, exitStatus):
        self.append_log(f"\nBuild finished with exit code: {exitCode}\n")


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
