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
	text.setPosition(sf::Vector2f((window->getSize().x * 0.3f), 75.0f));
	text.setString("Main Menu");
	text.setCharacterSize(200);
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	levelText.setFont(font);
	levelText.setString("Play Game");
	levelText.setPosition(sf::Vector2f(window->getSize().x * 0.455f, window->getSize().y * 0.715f));
	levelText.setColor(sf::Color::Black);
	levelText.setCharacterSize(48.0f);
	
	levelButton.setPosition(sf::Vector2f(((window->getSize().x * 0.5f) - 125.0f), window->getSize().y * 0.65f));
	levelButton.setSize(sf::Vector2f(250.0f, 150.0f));
	levelButton.setFillColor(sf::Color::Yellow);
	levelButton.setOutlineColor(sf::Color::White);
	levelButton.setOutlineThickness(5.0f);

	highScoreText.setFont(font);
	highScoreText.setString("High Scores");
	highScoreText.setPosition(sf::Vector2f(window->getSize().x * 0.095f, window->getSize().y * 0.715f));
	highScoreText.setColor(sf::Color::Black);
	highScoreText.setCharacterSize(48.0f);

	highScoreButton.setPosition(sf::Vector2f(((window->getSize().x * 0.15f) - 125.0f), window->getSize().y * 0.65f));
	highScoreButton.setSize(sf::Vector2f(250.0f, 150.0f));
	highScoreButton.setFillColor(sf::Color::Yellow);
	highScoreButton.setOutlineColor(sf::Color::White);
	highScoreButton.setOutlineThickness(5.0f);

	exitText.setFont(font);
	exitText.setString("Quit Game");
	exitText.setPosition(sf::Vector2f(window->getSize().x * 0.81f, window->getSize().y * 0.715f));
	exitText.setColor(sf::Color::Black);
	exitText.setCharacterSize(48.0f);

	exitButton.setPosition(sf::Vector2f(((window->getSize().x * 0.85f) - 125.0f), window->getSize().y * 0.65f));
	exitButton.setSize(sf::Vector2f(250.0f, 150.0f));
	exitButton.setFillColor(sf::Color::Yellow);
	exitButton.setOutlineColor(sf::Color::White);
	exitButton.setOutlineThickness(5.0f);

	menuMusic->play();
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
	//levelButton.
	sf::Vector2f mousePosition((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);
	sf::FloatRect mouseRect(mousePosition, sf::Vector2f(1.0f, 1.0f));
	// Handle any input here for changing states.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		// Return any new states here.
		// This function requires a state to be returned.
		menuMusic->stop();
		return new Level(*this);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		// Return any new states here.
		// This function requires a state to be returned.
		menuMusic->stop();
		return new HighScoreState(*this);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
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
	window->draw(levelButton);
	window->draw(levelText);
	window->draw(highScoreButton);
	window->draw(highScoreText);
	window->draw(exitButton);
	window->draw(exitText);

}

void MenuState::Update(const sf::Time& deltaTime)
{

}
