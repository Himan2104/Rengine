#pragma once

#include <Rengine/Editor/EditorWindow.hxx>
#include <imgui.h>

namespace Ren::Editor::IBEW
{

class ThemeEditor : public EditorWindow<"Theme Editor", ImGuiWindowFlags_AlwaysVerticalScrollbar>
{
public:
    void Render() override
    {
        ImGuiStyle& style = ImGui::GetStyle();

        // Style Properties Section
        if (ImGui::CollapsingHeader("Style Properties", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::SliderFloat("Alpha", &style.Alpha, 0.0f, 1.0f, "%.2f");
            ImGui::SliderFloat("Disabled Alpha", &style.DisabledAlpha, 0.0f, 1.0f, "%.2f");

            ImGui::SliderFloat2("Window Padding", (float*)&style.WindowPadding, 0.0f, 20.0f, "%.1f");
            ImGui::SliderFloat("Window Rounding", &style.WindowRounding, 0.0f, 12.0f, "%.1f");
            ImGui::SliderFloat("Window Border Size", &style.WindowBorderSize, 0.0f, 1.0f, "%.1f");
            ImGui::SliderFloat2("Window Min Size", (float*)&style.WindowMinSize, 1.0f, 100.0f, "%.1f");
            ImGui::SliderFloat2("Window Title Align", (float*)&style.WindowTitleAlign, 0.0f, 1.0f, "%.2f");

            // Window Menu Button Position
            const char* menuButtonItems[] = {"None", "Left", "Right"};
            int menuButtonCurrent         = (style.WindowMenuButtonPosition == ImGuiDir_None) ? 0
                        : (style.WindowMenuButtonPosition == ImGuiDir_Left)                   ? 1
                                                                                              : 2;
            if (ImGui::Combo("Window Menu Button Position", &menuButtonCurrent, menuButtonItems, 3))
            {
                style.WindowMenuButtonPosition = (menuButtonCurrent == 0) ? ImGuiDir_None
                    : (menuButtonCurrent == 1)                            ? ImGuiDir_Left
                                                                          : ImGuiDir_Right;
            }

            ImGui::SliderFloat("Child Rounding", &style.ChildRounding, 0.0f, 12.0f, "%.1f");
            ImGui::SliderFloat("Child Border Size", &style.ChildBorderSize, 0.0f, 1.0f, "%.1f");
            ImGui::SliderFloat("Popup Rounding", &style.PopupRounding, 0.0f, 12.0f, "%.1f");
            ImGui::SliderFloat("Popup Border Size", &style.PopupBorderSize, 0.0f, 1.0f, "%.1f");

            ImGui::SliderFloat2("Frame Padding", (float*)&style.FramePadding, 0.0f, 20.0f, "%.1f");
            ImGui::SliderFloat("Frame Rounding", &style.FrameRounding, 0.0f, 12.0f, "%.1f");
            ImGui::SliderFloat("Frame Border Size", &style.FrameBorderSize, 0.0f, 1.0f, "%.1f");

            ImGui::SliderFloat2("Item Spacing", (float*)&style.ItemSpacing, 0.0f, 20.0f, "%.1f");
            ImGui::SliderFloat2("Item Inner Spacing", (float*)&style.ItemInnerSpacing, 0.0f, 20.0f, "%.1f");
            ImGui::SliderFloat2("Cell Padding", (float*)&style.CellPadding, 0.0f, 20.0f, "%.1f");

            ImGui::SliderFloat("Indent Spacing", &style.IndentSpacing, 0.0f, 30.0f, "%.1f");
            ImGui::SliderFloat("Columns Min Spacing", &style.ColumnsMinSpacing, 0.0f, 20.0f, "%.1f");
            ImGui::SliderFloat("Scrollbar Size", &style.ScrollbarSize, 1.0f, 20.0f, "%.1f");
            ImGui::SliderFloat("Scrollbar Rounding", &style.ScrollbarRounding, 0.0f, 12.0f, "%.1f");
            ImGui::SliderFloat("Grab Min Size", &style.GrabMinSize, 1.0f, 20.0f, "%.1f");
            ImGui::SliderFloat("Grab Rounding", &style.GrabRounding, 0.0f, 12.0f, "%.1f");

            ImGui::SliderFloat("Tab Rounding", &style.TabRounding, 0.0f, 12.0f, "%.1f");
            ImGui::SliderFloat("Tab Border Size", &style.TabBorderSize, 0.0f, 1.0f, "%.1f");
            ImGui::SliderFloat("Tab Close Button Min Width", &style.TabMinWidthForCloseButton, 0.0f, 200.0f, "%.1f");

            // Color Button Position
            const char* colorButtonItems[] = {"Left", "Right"};
            int colorButtonCurrent         = (style.ColorButtonPosition == ImGuiDir_Left) ? 0 : 1;
            if (ImGui::Combo("Color Button Position", &colorButtonCurrent, colorButtonItems, 2))
            {
                style.ColorButtonPosition = (colorButtonCurrent == 0) ? ImGuiDir_Left : ImGuiDir_Right;
            }

            ImGui::SliderFloat2("Button Text Align", (float*)&style.ButtonTextAlign, 0.0f, 1.0f, "%.2f");
            ImGui::SliderFloat2("Selectable Text Align", (float*)&style.SelectableTextAlign, 0.0f, 1.0f, "%.2f");
        }

        ImGui::Separator();

        // Colors Section
        if (ImGui::CollapsingHeader("Colors", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::Text("Modify colors and see changes instantly:");

            // Helper lambda for color editing
            auto EditColor = [&](const char* label, ImGuiCol idx)
            {
                ImGui::ColorEdit4(label, (float*)&style.Colors[idx],
                                  ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
            };

            // Text Colors
            if (ImGui::TreeNode("Text"))
            {
                EditColor("Text", ImGuiCol_Text);
                EditColor("Text Disabled", ImGuiCol_TextDisabled);
                EditColor("Text Selected Bg", ImGuiCol_TextSelectedBg);
                ImGui::TreePop();
            }

            // Window Colors
            if (ImGui::TreeNode("Window"))
            {
                EditColor("Window Bg", ImGuiCol_WindowBg);
                EditColor("Child Bg", ImGuiCol_ChildBg);
                EditColor("Popup Bg", ImGuiCol_PopupBg);
                EditColor("Border", ImGuiCol_Border);
                EditColor("Border Shadow", ImGuiCol_BorderShadow);
                ImGui::TreePop();
            }

            // Frame Colors
            if (ImGui::TreeNode("Frame"))
            {
                EditColor("Frame Bg", ImGuiCol_FrameBg);
                EditColor("Frame Bg Hovered", ImGuiCol_FrameBgHovered);
                EditColor("Frame Bg Active", ImGuiCol_FrameBgActive);
                ImGui::TreePop();
            }

            // Title Colors
            if (ImGui::TreeNode("Title"))
            {
                EditColor("Title Bg", ImGuiCol_TitleBg);
                EditColor("Title Bg Active", ImGuiCol_TitleBgActive);
                EditColor("Title Bg Collapsed", ImGuiCol_TitleBgCollapsed);
                ImGui::TreePop();
            }

            // Menu Colors
            if (ImGui::TreeNode("Menu"))
            {
                EditColor("Menu Bar Bg", ImGuiCol_MenuBarBg);
                ImGui::TreePop();
            }

            // Scrollbar Colors
            if (ImGui::TreeNode("Scrollbar"))
            {
                EditColor("Scrollbar Bg", ImGuiCol_ScrollbarBg);
                EditColor("Scrollbar Grab", ImGuiCol_ScrollbarGrab);
                EditColor("Scrollbar Grab Hovered", ImGuiCol_ScrollbarGrabHovered);
                EditColor("Scrollbar Grab Active", ImGuiCol_ScrollbarGrabActive);
                ImGui::TreePop();
            }

            // Controls
            if (ImGui::TreeNode("Controls"))
            {
                EditColor("Check Mark", ImGuiCol_CheckMark);
                EditColor("Slider Grab", ImGuiCol_SliderGrab);
                EditColor("Slider Grab Active", ImGuiCol_SliderGrabActive);
                ImGui::TreePop();
            }

            // Button Colors
            if (ImGui::TreeNode("Button"))
            {
                EditColor("Button", ImGuiCol_Button);
                EditColor("Button Hovered", ImGuiCol_ButtonHovered);
                EditColor("Button Active", ImGuiCol_ButtonActive);
                ImGui::TreePop();
            }

            // Header Colors
            if (ImGui::TreeNode("Header"))
            {
                EditColor("Header", ImGuiCol_Header);
                EditColor("Header Hovered", ImGuiCol_HeaderHovered);
                EditColor("Header Active", ImGuiCol_HeaderActive);
                ImGui::TreePop();
            }

            // Separator Colors
            if (ImGui::TreeNode("Separator"))
            {
                EditColor("Separator", ImGuiCol_Separator);
                EditColor("Separator Hovered", ImGuiCol_SeparatorHovered);
                EditColor("Separator Active", ImGuiCol_SeparatorActive);
                ImGui::TreePop();
            }

            // Resize Grip Colors
            if (ImGui::TreeNode("Resize Grip"))
            {
                EditColor("Resize Grip", ImGuiCol_ResizeGrip);
                EditColor("Resize Grip Hovered", ImGuiCol_ResizeGripHovered);
                EditColor("Resize Grip Active", ImGuiCol_ResizeGripActive);
                ImGui::TreePop();
            }

            // Tab Colors
            if (ImGui::TreeNode("Tab"))
            {
                EditColor("Tab", ImGuiCol_Tab);
                EditColor("Tab Hovered", ImGuiCol_TabHovered);
                EditColor("Tab Active", ImGuiCol_TabActive);
                EditColor("Tab Unfocused", ImGuiCol_TabUnfocused);
                EditColor("Tab Unfocused Active", ImGuiCol_TabUnfocusedActive);
                ImGui::TreePop();
            }

            // Plot Colors
            if (ImGui::TreeNode("Plot"))
            {
                EditColor("Plot Lines", ImGuiCol_PlotLines);
                EditColor("Plot Lines Hovered", ImGuiCol_PlotLinesHovered);
                EditColor("Plot Histogram", ImGuiCol_PlotHistogram);
                EditColor("Plot Histogram Hovered", ImGuiCol_PlotHistogramHovered);
                ImGui::TreePop();
            }

            // Table Colors
            if (ImGui::TreeNode("Table"))
            {
                EditColor("Table Header Bg", ImGuiCol_TableHeaderBg);
                EditColor("Table Border Strong", ImGuiCol_TableBorderStrong);
                EditColor("Table Border Light", ImGuiCol_TableBorderLight);
                EditColor("Table Row Bg", ImGuiCol_TableRowBg);
                EditColor("Table Row Bg Alt", ImGuiCol_TableRowBgAlt);
                ImGui::TreePop();
            }

            // Misc Colors
            if (ImGui::TreeNode("Miscellaneous"))
            {
                EditColor("Drag Drop Target", ImGuiCol_DragDropTarget);
                EditColor("Nav Highlight", ImGuiCol_NavHighlight);
                EditColor("Nav Windowing Highlight", ImGuiCol_NavWindowingHighlight);
                EditColor("Nav Windowing Dim Bg", ImGuiCol_NavWindowingDimBg);
                EditColor("Modal Window Dim Bg", ImGuiCol_ModalWindowDimBg);
                ImGui::TreePop();
            }
        }

        ImGui::Separator();

        // Export/Import Section
        if (ImGui::CollapsingHeader("Export/Import"))
        {
            if (ImGui::Button("Copy Theme to Clipboard"))
            {
                // This would generate C++ code for the current theme
                // Implementation would depend on your clipboard handling
                ImGui::SetClipboardText("Theme copied! (Implementation needed)");
            }

            ImGui::SameLine();
            if (ImGui::Button("Reset to Default"))
            {
                ImGui::StyleColorsDark(&style); // or StyleColorsClassic/StyleColorsLight
            }
        }
    }
};
} // namespace Ren::Editor::IBEW
