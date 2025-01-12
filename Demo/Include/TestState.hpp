#pragma once
#include<SFML/Graphics.hpp>
#include<Rengine/Core/Level.hpp>

class TestState: public Ren::Level
{
public:
	TestState();
	~TestState();

	void Initialize() override;
	void EventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void Update(float delTime) override;
	void Render(sf::RenderTarget& renderer) override;

private:
	sf::Sprite logo;
	sf::Texture tex;
	sf::Shader hbloom, vbloom, blur;

	sf::Clock delayClock;

	sf::Font font;
	sf::Text text;
	
	float br;

	bool dir;

};

