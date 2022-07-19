#pragma once
#include<Rengine/Core/State.hpp>

class TestState: public ren::State
{
public:
	TestState(ren::Environment* env);
	~TestState();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& renderer) override;

private:
	sf::Sprite logo;
	sf::Texture tex;
	sf::Shader hbloom, vbloom;

	sf::Clock delayClock;

	sf::Font font;
	sf::Text text;

	bool dir;

};

