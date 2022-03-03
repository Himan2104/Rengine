#pragma once
#include<Rengine/Core/State.hpp>

class TestState: public ren::State
{
public:
	TestState();
	~TestState();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& renderer) override;

private:
	sf::Sprite logo;
	sf::Texture tex;
	sf::Shader blur;

	sf::Clock delayClock;

	sf::Font font;
	sf::Text text;

	float delayperjerk, timer, blurval, setblur;
	bool dir;

	float sigma, bsize;
};

