#pragma once

// Include files here.
// Add in all of the header files for each state that this state interacts with.
#include "State.h"
#include "Player.h"
#include "MenuState.h"
#include <ctime>
#include <string>


struct PlayerScore
{
	sf::Text name, date, time, placeText, scoreText;
	int score;
	int place; //Place will be defined by array position
	PlayerScore(sf::Font& font)
	{
		name.setFont(font);
		scoreText.setFont(font);
		placeText.setFont(font);
		score = 0;
	}
};


// InitState IS A state therefore inherits from it.
class HighScoreState : public State
{
public:
	// Methods.
	HighScoreState(const State& current_state);
	~HighScoreState();
	State* HandleInput();
	void Render();
	void Update(const sf::Time& deltaTime);
	void AddScore();
private:
	sf::RectangleShape box;
	sf::Text number;
	sf::Event event;
	std::vector<PlayerScore> playerScores;
	sf::Text latestScore, typeName, nameText;
	int counter;
	sf::Text exitText;
	sf::RectangleShape exitButton;
	sf::RectangleShape highScoreBox;
};
