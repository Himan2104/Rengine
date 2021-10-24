#pragma once
#include<SFML/Graphics.hpp>
#include"Rengine/Config.hpp"

class REN_API State
{
public:
	State(){}
	virtual ~State(){}
	virtual void initialize() = 0;
	virtual void eventHandler(sf::Event& event, const sf::RenderWindow& window) = 0;
	virtual void update(float delTime) = 0;
	virtual void draw(sf::RenderTarget& target) = 0;
};
