#include "TestState.hpp"
#include<Rengine/Utility/Misc.hpp>
#include<Rengine/Utility/Debug.hpp>

TestState::TestState(ren::Environment* env)
	:State(env)
{
}

TestState::~TestState()
{
}

void TestState::initialize()
{
	ren::Debug::log("TestState Loaded!");
	tex.loadFromFile("assets/light.png");
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


	hbloom.loadFromFile("assets/shaders/hbloom.glsl", sf::Shader::Fragment /*"assets/shaders/gaussian_frag.glsl"*/);
	vbloom.loadFromFile("assets/shaders/vbloom.glsl", sf::Shader::Fragment /*"assets/shaders/gaussian_frag.glsl"*/);

	hbloom.setUniform("sourceTexture", sf::Shader::CurrentTexture);
	hbloom.setUniform("sigma", 4.0f);
	hbloom.setUniform("glowMultiplier", 10.0f);
	hbloom.setUniform("width", 100.0f);
	
	vbloom.setUniform("sourceTexture", sf::Shader::CurrentTexture);
	vbloom.setUniform("sigma", 4.0f);
	vbloom.setUniform("glowMultiplier", 10.0f);
	vbloom.setUniform("height", 100.0f);
	
}

void TestState::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) dir = !dir;
}

void TestState::update(float delTime)
{	
	//logo.rotate(sigma);
	//blur.setUniform("blur_radius", blurval);
	/*blur.setUniform("sigma", sigma);
	blur.setUniform("blurSize", bsize);*/
	

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) sigma += 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) sigma -= 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bsize += 0.1f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) bsize -= 0.1f;*/

	

	/*if (blurval <= 0.0f && !dir)
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
	}*/
}

void TestState::draw(sf::RenderTarget& renderer)
{
	if (dir)
	{
		renderer.draw(logo, &hbloom);
		renderer.draw(logo, &vbloom);
	}
	else renderer.draw(logo);
	renderer.draw(text);
}
