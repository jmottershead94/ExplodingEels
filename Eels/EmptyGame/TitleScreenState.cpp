// Include header file here.
#include "TitleScreenState.h"

//////////////////////////////////////////////////////////
//======================================================//
//					Constructor							//
//======================================================//
// This will initialise this state.						//
// Passing in the current state allows for				//
// communication between the states.					//
//////////////////////////////////////////////////////////
TitleScreenState::TitleScreenState(const State& currentState) : State(currentState)
{

	std::cout << "Title screen state." << std::endl;

	// Set up a new text variable.
	// Set the font of the text that is going to be displayed.
	text.setFont(font);
	text.setString("The Title Screen State\n Left Mouse Button - Go To Main Menu");
	text.setCharacterSize(64);
	text.setColor(sf::Color::White);
	//text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

//////////////////////////////////////////////////////////
//======================================================//
//					Destructor							//
//======================================================//
// This will clean up any variables.					//
//////////////////////////////////////////////////////////
TitleScreenState::~TitleScreenState()
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
State* TitleScreenState::HandleInput()
{

	// Handle any input here for changing states.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// Return any new states here.
		// This function requires a state to be returned.
		return new MenuState(*this);
	}

	// Returns nothing because there has been no input from the player yet.
	return NULL;

}

void TitleScreenState::Render()
{

	// Draw your all of your sprites/gameobjects here.
	//window->draw("your game object here.");
	window->draw(text);

}

void TitleScreenState::Update(const sf::Time& deltaTime)
{

}