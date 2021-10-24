#pragma once
#include<SFML/Graphics.hpp>
#include"guibase.hpp"
#include<iostream>

namespace gui
{
	class Slider : public guibase
	{
	public:
		Slider(std::pair<float, float> range = std::make_pair(0, 10));
		~Slider();

		void setColor(sf::Color color);

		void EventHandler(sf::Event e, const sf::RenderWindow& window) override;

		void setPosition(const sf::Vector2f& pos) override;

		float getCurrentValue();

		sf::Vector2f getSize() const override;

		void render(sf::RenderTarget& renderTarget) override;

	private:
		sf::RectangleShape knob, path;
		std::pair<float, float> range;

		float currentValue;

		bool isActive;

		void adjustKnob();
	};
}
