#pragma once

// Include files here.
// Add in all of the header files for each state that this state interacts with.
// This state will go to the title screen, so therefore needs to include the title screen.
#include "State.h"
#include "TitleScreenState.h"

// InitState IS A state therefore inherits from it.
class SplashScreenState : public State
{

public:
	// Methods.
	SplashScreenState(const State& current_state);
	~SplashScreenState();
	State* HandleInput();
	void Render();
	void Update(const sf::Time& deltaTime);
	bool explosionQue;
	int counter;
	sf::Sound explosionSound;
	sf::SoundBuffer explosionBuffer;
	sf::Text titleText;
	GameObject* eel;
	GameObject* eelTwo;
	GameObject* explosion;
	GameObject* explosionTwo;
	GameObject* object;
	GameObject* objectTwo;
};

