//Class for utilizing CheckBox
#pragma once
#include<SFML/Graphics.hpp>
#include"guibase.hpp"

namespace ren
{
	namespace ui
	{
		class CheckBox : public guibase
		{
		public:
			//Ctor : Takes the fontface, lavel and the scale of the box and label
			CheckBox(sf::Font& font, std::string label = "NoLabel", float scale = 1.0f);

			//Returns the status of the Check Box (true/false)
			bool getStatus();

			//Handles Events : Clicked
			void EventHandler(sf::Event e, const sf::RenderWindow& window) override;

			//Set position of the entire entity
			void setPosition(const sf::Vector2f& pos) override;

			//getter for the size of the bounding box
			sf::Vector2f getSize()const override;

			//Render the CheckBox. Takes a render target (your window in simple terms)
			void render(sf::RenderTarget& renderTarget) override;

			//Dtor
			~CheckBox();

		private:
			sf::RectangleShape box;
			sf::RectangleShape tick;
			sf::Text label;

			float scale;

			bool status;

			void adjustPositions();
		};
	}
}

