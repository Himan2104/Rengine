#include "TestState.hpp"
#include<Rengine/utility/Utility.hpp>
#include<Rengine/utility/Debug.hpp>

TestState::TestState()
{
}

TestState::~TestState()
{
}

void TestState::initialize()
{
	box.setSize(sf::Vector2f(400.0f, 400.0f));
	ren::util::centerOrigin(box);
	box.setPosition(960, 540);
	delayClock.restart().asSeconds();
}

void TestState::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
}

void TestState::update(float delTime)
{
	if ((int)box.getRotation() % 361 == 0) ren::Debug::log("Elapsed : " + std::to_string(delayClock.getElapsedTime().asSeconds()), ren::Debug::MessageType::INFO);
	box.rotate(0.1f);
}

void TestState::draw(sf::RenderTarget& renderer)
{
	renderer.draw(box);
}
