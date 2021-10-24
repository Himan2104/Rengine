//Class for utilizing Buttons 
#pragma once
#include<SFML/Graphics.hpp>
#include"guibase.hpp"
#include<memory>
#include<functional>

namespace ren
{
	namespace ui
	{
		class Button : public guibase
		{
		public:
			//Ctor : Takes a font, size of the button and text to be displayed on the Button 
			Button(sf::Font& font, sf::Vector2f size = sf::Vector2f(256.0f, 64.0f), std::string ButtonText = "NewButton");

			//Edit styling options for the text on the button (Bold, Italic, etc.)
			void setTextStyle(sf::Uint32 style);

			//check if clicked
			bool isClicked(const sf::RenderWindow& window);

			//Set the Color of the Button and the Text
			void setColor(sf::Color BoxColor, sf::Color TextColor);

			//Set the Position of the Button
			void setPosition(const sf::Vector2f& pos) override;

			//Getter for the size of the bounded box of the button
			sf::Vector2f getSize() const override;

			//Set the function to be executed when the button is clicked
			void setFunction(std::function<void(void)> ButtonFunction);

			//Render the button. Takes a render target (your window in simple terms)
			void render(sf::RenderTarget& renderTarget) override;

			//Handles the events (ButtonClick)
			void EventHandler(sf::Event e, const sf::RenderWindow& window) override;

			//Dtor
			~Button();

		private:
			sf::RectangleShape box;
			sf::Text text;

			std::function<void(void)> ButtonFunction;

			void adjustText();

		};
	}
}

