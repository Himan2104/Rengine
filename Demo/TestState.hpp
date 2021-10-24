#pragma once
#include<Rengine/core/State.hpp>

class TestState: public State
{
public:
	TestState();
	~TestState();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& renderer) override;

private:
	sf::RectangleShape box;

	sf::Clock delayClock;
};

