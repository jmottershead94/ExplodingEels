// Include header file here.
#include "SplashScreenState.h"

//////////////////////////////////////////////////////////
//======================================================//
//					Constructor							//
//======================================================//
// This will initialise this state.						//
// Passing in the current state allows for				//
// communication between the states.					//
//////////////////////////////////////////////////////////
SplashScreenState::SplashScreenState(const State& currentState) : State(currentState)
{
	explosionQue = false;
	SetText(85.0f, 100.0f, 150, titleText);
	titleText.setString("Exploding Eels Entertainment");
	titleText.setStyle(sf::Text::Bold);
	spriteSheet.loadFromFile("spritesheet.png");
	eel = new GameObject(PLAYER, 0.0f, 500.0f, 1.0f, 1.0f, &spriteSheet);
	eelTwo = new GameObject(PLAYER, 1280.0f, 500.0f, -1.0f, 1.0f, &spriteSheet);
	explosion = new GameObject(EXPLOSION, 450.0f, 375.0f, 10.0f, 10.0f, &spriteSheet);
	explosionTwo = new GameObject(EXPLOSION, 600.0f, 375.0f, 10.0f, 10.0f, &spriteSheet);
	object = eel;
	objectTwo = eelTwo;
	counter = 0;
	SetSound(explosionBuffer, "explosion.wav", 50.0f, explosionSound);
}

//////////////////////////////////////////////////////////
//======================================================//
//					Destructor							//
//======================================================//
// This will clean up any variables.					//
//////////////////////////////////////////////////////////
SplashScreenState::~SplashScreenState()
{
}

//////////////////////////////////////////////////////////
//======================================================//
//					HandleInput							//
//======================================================//
// This function will handle all of the user input.		//
// This function also allows the states to change to	//
// each other, by return a pointer of state.			//
// If there is a state transition, it will be placed	//
// here.												//
//////////////////////////////////////////////////////////
State* SplashScreenState::HandleInput()
{

	/*if (eel->getPosition().x == 1280)
	{
	return new MenuState(*this);
	}*/
	if (explosionQue)
	{
		counter++;
		if (counter == 60)
		{
			return new MenuState(*this);
		}
	}

	// Returns nothing because there has been no input from the player yet.
	return NULL;

}

void SplashScreenState::Render()
{

	// Draw your all of your sprites/gameobjects here.
	//window->draw("your game object here.");
	window->draw(titleText);
	window->draw(*object);
	window->draw(*objectTwo);
}

void SplashScreenState::Update(const sf::Time& deltaTime)
{
	if (object->getPosition().x == 400)
	{
		explosionSound.play();
	}
	if (object->getPosition().x == 550)
	{
		explosionQue = true;
		object = explosion;
		objectTwo = explosionTwo;
	}
	if (!explosionQue)
	{
		objectTwo->move(-2.0f, 0.0f);
		object->move(2.0f, 0.0f);
	}
	object->Animate(0.005f);

	objectTwo->Animate(0.005f);

}