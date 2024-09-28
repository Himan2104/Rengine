#include "Rengine/ui/CheckBox.hpp"

ren::ui::CheckBox::CheckBox(sf::Font& font, std::string label, float scale)
{
	status = false;

	this->scale = scale;

	box.setSize(sf::Vector2f(10.0f * scale, 10.0f * scale));
	box.setOutlineThickness(2.0f * scale);
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Magenta);

	tick.setSize(sf::Vector2f(10.0f * scale,2.0f * scale));
	tick.setFillColor(sf::Color::Magenta);

	this->label.setFont(font);
	this->label.setString(label);
	this->label.setCharacterSize((unsigned int)(7 * scale));
	this->label.setFillColor(sf::Color::White);

	box.setOrigin(box.getGlobalBounds().width / 2.0f, box.getGlobalBounds().height / 2.0f);
	tick.setOrigin(tick.getGlobalBounds().width / 2.0f, tick.getGlobalBounds().height / 2.0f);
	this->label.setOrigin(this->label.getGlobalBounds().width / 2.0f, this->label.getGlobalBounds().height / 2.0f);

	tick.setRotation(45.0f);
}

ren::ui::CheckBox::~CheckBox()
{
}

bool ren::ui::CheckBox::getStatus()
{
	return status;
}

void ren::ui::CheckBox::EventHandler(sf::Event e, const sf::RenderWindow& window)
{
	if (e.type == sf::Event::MouseButtonPressed)
		if (box.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			status = !status;
}

void ren::ui::CheckBox::setPosition(const sf::Vector2f& pos)
{
	box.setPosition(pos);
	adjustPositions();
}

sf::Vector2f ren::ui::CheckBox::getSize() const
{
	return box.getSize();
}

void ren::ui::CheckBox::render(sf::RenderTarget& renderTarget)
{
	renderTarget.draw(box);
	if(status) renderTarget.draw(tick);
	renderTarget.draw(label);
}

void ren::ui::CheckBox::adjustPositions()
{
	label.setPosition(box.getPosition() + sf::Vector2f((box.getGlobalBounds().width + label.getGlobalBounds().width)/2.0f, -box.getGlobalBounds().width/4.0f));
	tick.setPosition(box.getPosition() - sf::Vector2f(2.0f * scale, 2.0f * scale));
}
