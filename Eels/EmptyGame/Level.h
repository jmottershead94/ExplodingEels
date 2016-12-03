#pragma once

#include "State.h"
#include "GameObject.h"
#include <vector>
#include <ctime>
#include "Player.h"
#include "SplashScreenState.h"
#include "HighScoreState.h"

#include <SFML\Window\Keyboard.hpp>

#define GROUNDHEIGHT 640

using std::vector;
using sf::Keyboard;
class Level : public State
{
public:
	Level(const State& currentState);
	~Level();
	void Update(const sf::Time& deltaTime), Render();
private:

	State* HandleInput();
	Player* player;

	vector<GameObject*> levelObjects;
	sf::RectangleShape red, green;
	sf::Text distanceText, lifeText, scoreText;
	sf::Texture background/*, foreground, midground, */, light;
	sf::Sprite /*midSprite, foreSprite, */backSprite, lightSprite;
	sf::Sound batterySound, sharkSound, diverSound;
	sf::SoundBuffer sharkBuffer, batteryBuffer, diverBuffer;
	void HandleKeyInput(), randomise(), Randomise(), GenerateObjects(), ResetLevel(), UserInterface(), ResetCounter(), MoveObjects(), ObjectCollisions();
	bool mute = false, paused = false;
	float scrollX, randomiserY, randomiserX, randomiserG;
	unsigned int maxObjects;
	int netX, netY, netCounter, netDelay, spawnDelay;;
};

