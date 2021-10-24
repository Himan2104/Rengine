//Class for utilizing TextBox
#pragma once
#include<SFML/Graphics.hpp>
#include"guibase.hpp"
#include<functional>
#include<iostream>
#include<stdlib.h>

namespace gui
{
	class TextBox : public guibase
	{
	public:
		//Ctor : Takes the size and the label of the text box
		TextBox(sf::Vector2f size = sf::Vector2f(128.0f, 32.0f), std::string label = "No Label");

		std::string getInput();

		//Set the font of the label and entered text
		void setFont(sf::Font& font);

		//Set the color of Outline, Box and the Text (label and input)
		void setColor(sf::Color FillColor = sf::Color::Black, sf::Color OutlineColor = sf::Color::Magenta, sf::Color TextColor = sf::Color::White);

		//Set the position of the entire Entity
		void setPosition(const sf::Vector2f& pos) override;

		//Getter for the size of bounding box of the element
		sf::Vector2f getSize() const override;

		//Handles Events : Clicked, TextEntered
		void EventHandler(sf::Event e, const sf::RenderWindow& window) override;

		//Render the TextBox. Takes a render target (your window in simple terms)
		void render(sf::RenderTarget& renderTarget) override;

		//Dtor
		~TextBox();

	private:
		sf::RectangleShape box;
		sf::Text label;

		std::string str;
		sf::Text inputText;

		bool isActive;

		void checkClick(sf::Event e, const sf::RenderWindow& window);
		void adjustInputText();
		void adjustLabel();

		
	};

}