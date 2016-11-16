//Application.cpp

//Includes
#include "Application.h"

//Constructor
Application::Application() : window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Exploding Eels") // there are framerate issues when resizing the game window, fullscreen would be optimal                                      
{
	//Initialise everything
	currentState = new InitState(window);
}

//Handles keyboard input
bool Application::HandleInput()
{
	//Deal with window closing
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			return false;
		}
	}

	//If escape key pressed
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
	{
		//Exit application
		window.close();
		return false;
	}
	return true;
}

//Updates the game
void Application::Update(const sf::Time& dt)
{
	// Handling the state changes.
	// Gaining access to any new states.
	State* newState = currentState->HandleInput();

	// If the new state is NOT null.
	if (newState != NULL)
	{
		// Delete the current state.
		delete currentState;

		// Make the current state equal to the new one.
		currentState = newState;
	}

	// Updating the current state.
	currentState->Update(dt);
}

//Renders game to the window
void Application::Render(const float& normalisedLag)
{
	//Clear previous frame
	window.clear(sf::Color(24,169,211,255));
	
	//Draw everything
	currentState->Render();

	//Display the frame
	window.display();
}