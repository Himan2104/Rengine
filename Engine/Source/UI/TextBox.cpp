#include "Rengine/UI/TextBox.hpp"

ren::ui::TextBox::TextBox(sf::Vector2f size, std::string label)
{
	isActive = false;

	box.setSize(size);
	box.setOutlineThickness(3);
	box.setOrigin(size.x / 2.0f, size.y / 2.0f);
	this->label.setCharacterSize(int(size.y/2.0f));
	this->label.setString(label);
	adjustLabel();
	adjustInputText();

	box.setFillColor(sf::Color::Black);
	box.setOutlineColor(sf::Color::Magenta);
	this->label.setFillColor(sf::Color::Cyan);
	inputText.setFillColor(sf::Color::Cyan);

}

std::string ren::ui::TextBox::getInput()
{
	return str;
}

void ren::ui::TextBox::setFont(sf::Font& font)
{
	label.setFont(font);
	inputText.setFont(font);
}

void ren::ui::TextBox::setColor(sf::Color FillColor, sf::Color OutlineColor, sf::Color TextColor)
{
	box.setFillColor(FillColor);
	box.setOutlineColor(OutlineColor);
	this->label.setFillColor(TextColor);
	inputText.setFillColor(TextColor);
}

void ren::ui::TextBox::setPosition(const sf::Vector2f& pos)
{
	box.setPosition(pos);
	adjustLabel();
	adjustInputText();
}

sf::Vector2f ren::ui::TextBox::getSize() const
{
	return box.getPosition();
}

void ren::ui::TextBox::EventHandler(sf::Event e, const sf::RenderWindow& window)
{
	checkClick(e, window);
	if(e.type == sf::Event::TextEntered)
		if(isActive)
			if (e.text.unicode < 128)
			{
				if (e.text.unicode == 8 && !str.empty())
					str.pop_back();
				else if (inputText.getGlobalBounds().width < box.getGlobalBounds().width - (box.getOutlineThickness()*3.0f))
					str += static_cast<char>(e.text.unicode);
				inputText.setString(str);
				adjustInputText();	
			}
	if (e.type == sf::Event::KeyPressed) 
		if (e.key.code == sf::Keyboard::Enter)
			isActive = false;
}

void ren::ui::TextBox::render(sf::RenderTarget& renderTarget)
{
	adjustInputText();
	renderTarget.draw(box);
	renderTarget.draw(label);
	renderTarget.draw(inputText);
	 
}

ren::ui::TextBox::~TextBox()
{
}

void ren::ui::TextBox::checkClick(sf::Event e, const sf::RenderWindow& window)
{
	sf::Vector2f m_pos = sf::Vector2f(sf::Mouse::getPosition(window));
	if (e.type == sf::Event::MouseButtonPressed)
		if (e.mouseButton.button == sf::Mouse::Left)
			if (box.getGlobalBounds().contains(m_pos))
				isActive = true;
			else
				isActive = false;
}

void ren::ui::TextBox::adjustInputText()
{
	inputText.setCharacterSize(box.getGlobalBounds().height/2.0f);
	inputText.setOrigin(inputText.getGlobalBounds().width / 2.0f, inputText.getGlobalBounds().height / 2.0f);
	inputText.setPosition(box.getPosition() - sf::Vector2f(0.0f, inputText.getGlobalBounds().height / 10.0f));
}

void ren::ui::TextBox::adjustLabel()
{
	//label.setOrigin(0.0f, label.getGlobalBounds().top label.getGlobalBounds().height);
	label.setPosition(box.getGlobalBounds().left, box.getGlobalBounds().top - label.getCharacterSize());
}

