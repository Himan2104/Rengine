#pragma once
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/Event.hpp>

#include"Rengine/Core/Environment.hpp"
#include"Rengine/Config.hpp"

namespace ren
{
	class REN_API Environment;
	class REN_API State
	{
	public:
		State(std::weak_ptr<ren::Environment> environment);
		virtual ~State() {}
		virtual void Initialize() = 0;
		virtual void EventHandler(sf::Event& event, const sf::RenderWindow& window) = 0;
		virtual void Update(float delTime) = 0;
		virtual void Render(sf::RenderTarget& target) = 0;

	protected:
		std::weak_ptr<ren::Environment> _global_env;
	};
}