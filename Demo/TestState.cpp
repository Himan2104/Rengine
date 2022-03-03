#include "TestState.hpp"
#include<Rengine/Utility/Misc.hpp>
#include<Rengine/Utility/Debug.hpp>

TestState::TestState()
{
}

TestState::~TestState()
{
}

void TestState::initialize()
{
	ren::Debug::log("TestState Loaded!");
	tex.loadFromFile("assets/rengine.png");
	logo.setTexture(tex);

	ren::centerOrigin(logo);
	logo.setPosition(960, 500);
	delayClock.restart().asSeconds();

	font.loadFromFile("C:/Windows/Fonts/consola.ttf");
	text.setFont(font);
	text.setString("RENGINE [v" + ren::getEngineVersion() + "]");
	text.setCharacterSize(15.0f);
	ren::centerOrigin(text);
	text.setPosition(960, 800);

	blur.loadFromFile("assets/shaders/blur.glsl", sf::Shader::Fragment);

	//blur.setUniform("blurSampler", sf::Shader::CurrentTexture);
	
	setblur = blurval = float(rand() % 100+50)/1000.0f;
	delayperjerk = float(rand() % 50 + 25) / 1000.0f;
	timer = 0.0f;
	dir = false;

	sigma = 0.05f;
	bsize = 0.001f;
}

void TestState::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
}

void TestState::update(float delTime)
{	
	logo.rotate(sigma);
	blur.setUniform("blur_radius", blurval);
	/*blur.setUniform("sigma", sigma);
	blur.setUniform("blurSize", bsize);*/
	

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) sigma += 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) sigma -= 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bsize += 0.1f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) bsize -= 0.1f;*/

	if (blurval <= 0.0f && !dir)
	{
		if (timer > delayperjerk)
		{
			timer = 0.0f;
			delayperjerk = float(rand() % 50 + 25) / 100.0f;
			setblur = float(rand() % 100 + 50) / 1000.0f;
			dir = true;
			sigma = -sigma;
		}
		timer += delTime;
	}
	else if (blurval >= setblur && dir)
	{
		if (timer > delayperjerk / 2.0f)
		{
			timer = 0.0f;
			dir = false;
			sigma = -sigma;
		}
		timer += delTime;
	}
	else
	{
		blurval = dir ? blurval += 0.1f * delTime : blurval -= 0.1f * delTime;
	}
}

void TestState::draw(sf::RenderTarget& renderer)
{
	renderer.draw(logo, &blur);
	//renderer.draw(logo);
	renderer.draw(text);
}
