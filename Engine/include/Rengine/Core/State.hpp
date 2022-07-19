#pragma once
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/Event.hpp>

#include"Rengine/Core/Environment.hpp"
#include"Rengine/Config.hpp"

namespace ren
{
	class Environment;
	class REN_API State
	{
	public:
		constexpr State(ren::Environment* environment);
		virtual ~State() {}
		virtual void initialize() = 0;
		virtual void eventHandler(sf::Event& event, const sf::RenderWindow& window) = 0;
		virtual void update(float delTime) = 0;
		virtual void draw(sf::RenderTarget& target) = 0;

	protected:
		Environment* gEnv;
	};
}