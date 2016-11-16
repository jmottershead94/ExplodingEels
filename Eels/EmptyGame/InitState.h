#pragma once

// Include files here.
#include "State.h"
#include "SplashScreenState.h"

// InitState IS A state therefore inherits from it.
class InitState : public State
{

	public:
		// Methods.
		InitState(sf::RenderWindow& gameWindow);
		~InitState();
		State* HandleInput();
		void Render();
		void Update(const sf::Time& deltaTime);

};

