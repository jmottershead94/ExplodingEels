#pragma once

// Include files here.
// Add in all of the header files for each state that this state interacts with.
#include "State.h"
#include "Level.h"
#include "HighScoreState.h"

// InitState IS A state therefore inherits from it.
class MenuState : public State
{

	public:
		// Methods.
		MenuState(const State& current_state);
		~MenuState();
		State* HandleInput();
		void Render();
		void Update(const sf::Time& deltaTime);

	private:
		// Attributes.
		sf::Text levelText, highScoreText, exitText;
		sf::RectangleShape levelButton, highScoreButton, exitButton;
};

