#pragma once

// Include files here.
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <SFML/Audio.hpp>
#include <sfml\System.hpp>

class State
{

public:
	// Methods.

	// Pure virtual functions that every state MUST have.
	// Intended to be overwritten by the more specific states.

	// Handling input for reading input through states.
	virtual State* HandleInput() = 0;

	// Render for rendering any specific text/objects for that state.
	virtual void Render() = 0;

	// Used for updating any of the states.
	virtual void Update(const sf::Time& deltaTime) = 0;

	int id;
	std::string name;
	int score;
	bool newHighScore;
	void SaveToFile();

protected:
	// Attributes.
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text text;
	sf::Music* menuMusic, *gameMusic;
	sf::Texture spriteSheet;
	//sf::SoundBuffer menuBuffer, gameBuffer;
	void SetText(float x, float y, int size, sf::Text& text);
	void SetSound(sf::SoundBuffer& buffer, const std::string& filename, float volume, sf::Sound& sound);

};

