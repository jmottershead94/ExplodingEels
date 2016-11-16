#include "MenuState.h"

//////////////////////////////////////////////////////////
//======================================================//
//					Constructor							//
//======================================================//
// This will initialise this state.						//
// Passing in the current state allows for				//
// communication between the states.					//
//////////////////////////////////////////////////////////
MenuState::MenuState(const State& currentState) : State(currentState)
{

	std::cout << "Menu state." << std::endl;

	// Set up a new text variable.
	// Set the font of the text that is going to be displayed.
	text.setFont(font);
	text.setString("The Menu State");
	text.setCharacterSize(64);
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	levelText.setFont(font);
	levelText.setString("Press 1 - Play Game");
	levelText.setPosition(sf::Vector2f(0.0f, 100.0f));
	levelText.setColor(sf::Color::White);
	levelText.setCharacterSize(32.0f);
	
	highScoreText.setFont(font);
	highScoreText.setString("Press 2 - High Scores");
	highScoreText.setPosition(sf::Vector2f(0.0f, 200.0f));
	highScoreText.setColor(sf::Color::White);
	highScoreText.setCharacterSize(32.0f);

	exitText.setFont(font);
	exitText.setString("Press Esc - Quit Game");
	exitText.setPosition(sf::Vector2f(0.0f, 300.0f));
	exitText.setColor(sf::Color::White);
	exitText.setCharacterSize(32.0f);

}

//////////////////////////////////////////////////////////
//======================================================//
//					Destructor							//
//======================================================//
// This will clean up any variables.					//
//////////////////////////////////////////////////////////
MenuState::~MenuState()
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
State* MenuState::HandleInput()
{

	// Handle any input here for changing states.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		// Return any new states here.
		// This function requires a state to be returned.
		return new Level(*this);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		// Return any new states here.
		// This function requires a state to be returned.
		return new HighScoreState(*this);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		std::cout << "Closing the window." << std::endl;
		window->close();
	}

	// Returns nothing because there has been no input from the player yet.
	return NULL;

}

void MenuState::Render()
{

	// Draw your all of your sprites/gameobjects here.
	//window->draw("your game object here.");
	window->draw(text);
	window->draw(levelText);
	window->draw(highScoreText);
	window->draw(exitText);

}

void MenuState::Update(const sf::Time& deltaTime)
{

}
