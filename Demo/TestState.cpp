#include "TestState.hpp"
#include<Rengine/Utility/Misc.hpp>
#include<Rengine/Utility/Debug.hpp>

TestState::TestState(std::weak_ptr<ren::Environment> env)
	:State(env)
{
}

TestState::~TestState()
{
}

void TestState::Initialize()
{
	ren::Debug::log("TestState Loaded!");
	tex.loadFromFile("assets/rengine.png");
	logo.setTexture(tex);

	ren::CenterOrigin(logo);
	logo.setPosition(960, 500);
	delayClock.restart().asSeconds();

	font.loadFromFile("C:/Windows/Fonts/consola.ttf");
	text.setFont(font);
	text.setString("RENGINE [v" + ren::GetEngineVersion() + "]");
	text.setCharacterSize(15.0f);
	ren::CenterOrigin(text);
	text.setPosition(960, 800);

	blur.loadFromFile("assets/shaders/blur.glsl", sf::Shader::Fragment);
	
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

	blur.setUniform("texture", sf::Shader::CurrentTexture);
	br = 0.001f;
	blur.setUniform("blur_radius", br);
}

void TestState::EventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) dir = !dir;
	
}

void TestState::Update(float delTime)
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) br -= 0.001f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) br += 0.001f;
	blur.setUniform("blur_radius", br);
}

void TestState::Render(sf::RenderTarget& renderer)
{
	if (dir)
	{
		renderer.draw(logo, &hbloom);
		renderer.draw(logo, &vbloom);
	}
	else renderer.draw(logo, &blur);
	renderer.draw(text);
}
