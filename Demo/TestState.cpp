#include "TestState.hpp"
#include<Rengine/utility/Misc.hpp>
#include<Rengine/utility/Debug.hpp>

TestState::TestState()
{
}

TestState::~TestState()
{
}

void TestState::initialize()
{
	ren::Debug::log("TestState Loaded!");
	box.setSize(sf::Vector2f(400.0f, 400.0f));
	ren::centerOrigin(box);
	box.setPosition(960, 540);
	delayClock.restart().asSeconds();
}

void TestState::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
}

void TestState::update(float delTime)
{	
	box.rotate(0.01f);
}

void TestState::draw(sf::RenderTarget& renderer)
{
	renderer.draw(box);
}
