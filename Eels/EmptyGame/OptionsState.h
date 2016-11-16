#pragma once

// Include files here.
// Add in all of the header files for each state that this state interacts with.
#include "State.h"
#include "MenuState.h"

// InitState IS A state therefore inherits from it.
class OptionsState : public State
{

	public:
		// Methods.
		OptionsState(const State& current_state);
		~OptionsState();
		State* HandleInput();
		void Render();
		void Update(const sf::Time& deltaTime);

};

