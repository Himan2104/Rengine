#include "Rengine/ui/Slider.hpp"

ren::ui::Slider::Slider(std::pair<float, float> range) : range(range)
{
	path.setSize({ this->range.second * 5.0f, 2.0f });
	knob.setSize({ 10.0f, 10.0f });
	adjustKnob();
	path.setFillColor(sf::Color(255, 255, 255, 100));
	knob.setFillColor(sf::Color::Magenta);
	isActive = false;

	currentValue = (knob.getPosition().x - path.getPosition().x) / 5.0f;
}

ren::ui::Slider::~Slider()
{
}

void ren::ui::Slider::setColor(sf::Color color)
{
	path.setFillColor(sf::Color(color.r, color.g, color.b, 100));
	knob.setFillColor(color);
}

void ren::ui::Slider::EventHandler(sf::Event e, const sf::RenderWindow& window)
{
	currentValue = (knob.getPosition().x - path.getPosition().x) / 5.0f;

	if (knob.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && 
		sf::Mouse::isButtonPressed(sf::Mouse::Left))
		isActive = true;
	else if (e.type == sf::Event::MouseButtonReleased)
		isActive = false;

	if (isActive && currentValue <= range.second + 10.0f && currentValue >= range.first - 10.0f)
	{
		if (e.type == sf::Event::MouseMoved)
		{
			knob.move(sf::Mouse::getPosition(window).x - (knob.getPosition().x + 5.0f) , 0.0f);
		}
	}
}

void ren::ui::Slider::setPosition(const sf::Vector2f& pos)
{
	path.setPosition(pos);
	adjustKnob();
}

float ren::ui::Slider::getCurrentValue()
{
	return currentValue;
}

sf::Vector2f ren::ui::Slider::getSize() const
{
	return path.getSize();
}

void ren::ui::Slider::render(sf::RenderTarget& renderTarget)
{
	renderTarget.draw(path);
	renderTarget.draw(knob);

}

void ren::ui::Slider::adjustKnob()
{
	knob.setPosition(path.getPosition().x + 1.0f, path.getPosition().y - knob.getSize().y/2.0f);
}
