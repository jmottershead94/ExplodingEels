// Including the header file here.
#include "InitState.h"

//////////////////////////////////////////////////////////
//======================================================//
//					Constructor							//
//======================================================//
// This will initialise this state.						//
// Each of the pointers for the entire state machine	//
// will be initialised here, by pointing to the			//
// variables from game class.							//
//////////////////////////////////////////////////////////
// PASS IN CLASSES HERE TO INITIALISE POINTERS IN THE BASE STATE CLASS.
InitState::InitState(sf::RenderWindow& gameWindow)
{

	std::cout << "Init state." << std::endl;

	// Setting up the pointer to the game render window.
	window = &gameWindow;
	
	if (!font.loadFromFile("font.ttf"))
	{
		// Error.
	}

}

//////////////////////////////////////////////////////////
//======================================================//
//					Destructor							//
//======================================================//
// This will clean up any variables.					//
//////////////////////////////////////////////////////////
InitState::~InitState()
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
State* InitState::HandleInput()
{

	//// Handle any input here for changing states.
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//{
	//	// Return any new states here.
	//	// This function requires a state to be returned.
	//	//return new SplashScreenState(*this);
	//}

	//return NULL;

	// Return a new state.
	return new SplashScreenState(*this);
	

}

//////////////////////////////////////////////////////////
//======================================================//
//						Render							//
//======================================================//
// Render will just draw everything that is in this 	//
// state.												//
//////////////////////////////////////////////////////////
void InitState::Render()
{

	// Draw your all of your sprites/gameobjects here.
	//window->draw("your game object here.");
	
}

//////////////////////////////////////////////////////////
//======================================================//
//						Update							//
//======================================================//
// This will provide a timer for this class.			//
//////////////////////////////////////////////////////////
void InitState::Update(const sf::Time& deltaTime)
{

}