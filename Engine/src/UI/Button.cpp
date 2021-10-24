#include "Rengine/ui/Button.hpp"

ren::ui::Button::Button(sf::Font& font, sf::Vector2f size, std::string ButtonText)
{ 
	box.setSize(size);
	text.setFont(font);
	text.setString(ButtonText);
	box.setOrigin(box.getGlobalBounds().width / 2.0f, box.getGlobalBounds().height / 2.0f);

	adjustText();

	box.setFillColor(sf::Color::Magenta);
	text.setFillColor(sf::Color::White);
}

void ren::ui::Button::setTextStyle(sf::Uint32 style)
{
	text.setStyle(style);
	adjustText();
}

void ren::ui::Button::setColor(sf::Color BoxColor, sf::Color TextColor)
{
	box.setFillColor(BoxColor);
	text.setFillColor(TextColor);
}

void ren::ui::Button::setPosition(const sf::Vector2f& pos)
{
	box.setPosition(pos);
	adjustText();
}

sf::Vector2f ren::ui::Button::getSize() const
{
	return box.getSize();
}

void ren::ui::Button::setFunction(std::function<void(void)> ButtonFunction)
{
	this->ButtonFunction = ButtonFunction;
}

void ren::ui::Button::render(sf::RenderTarget& renderTarget)
{
	renderTarget.draw(box);
	renderTarget.draw(text);
}

void ren::ui::Button::EventHandler(sf::Event e, const sf::RenderWindow& window)
{
	sf::Vector2f m_pos = sf::Vector2f(sf::Mouse::getPosition(window));

	if (e.type == sf::Event::MouseButtonPressed)
		if (e.mouseButton.button == sf::Mouse::Left)
			if (box.getGlobalBounds().contains(m_pos))
				ButtonFunction();
		
}

ren::ui::Button::~Button()
{
}

void ren::ui::Button::adjustText()
{
	text.setCharacterSize(int(box.getGlobalBounds().height / 2.0f));
	text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
	while (text.getGlobalBounds().left < box.getGlobalBounds().left
		|| text.getGlobalBounds().left + text.getGlobalBounds().width
		> box.getGlobalBounds().left + box.getGlobalBounds().width
		|| text.getGlobalBounds().top < box.getGlobalBounds().top
		|| text.getGlobalBounds().top + text.getGlobalBounds().height
		> box.getGlobalBounds().top + box.getGlobalBounds().height)
	{
		text.setCharacterSize(text.getCharacterSize() - 1);
		text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
		text.setPosition(box.getPosition() - sf::Vector2f(0.0f, text.getGlobalBounds().height/2.0f));
	}
}
