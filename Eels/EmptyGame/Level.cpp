/*
TODO:
text pop ups on collision
explosion sprite or animation uses inherited positions to make it appear in the right location
add vertical obstacles (behind other sprites)
fix so only lets to you toggle bools once
fix so escape doesnt effect other states if you press it in this one
fix repeating background so it isnt just a really long thing it just gets displaced and put back (two sprites?)
power up clears the screen
power up
*/

#include "Level.h"
#include "Application.h" 

//////////////////////////////////////////////////////////
//======================================================//
//					Constructor							//
//======================================================//
// This will initialise this state.						//
// Passing in the current state allows for				//
// communication between the states.					//
//////////////////////////////////////////////////////////
Level::Level(const State& currentState) : State(currentState)
{
	//red bar setup
	red.setPosition(10, 35);
	red.setFillColor(sf::Color::Red);
	red.setSize(sf::Vector2f(200.0f, 30.0f));
	red.setOutlineColor(sf::Color::Black);
	red.setOutlineThickness(2.0f);
	//green bar setup
	green.setPosition(10, 35);
	green.setFillColor(sf::Color::Green);

	//text setup
	SetText(250.0f, -3.0f, 30, distanceText);
	SetText(10.0f, -3.0f, 30, lifeText);
	SetText(350.0f, -3.0f, 30, scoreText);

	

	//sound setup
	SetSound(batteryBuffer, "batterysound.flac", 15.0f, batterySound);
	SetSound(sharkBuffer, "sharksound.flac", 15.0f, sharkSound);
	SetSound(diverBuffer, "diversound.flac", 15.0f, diverSound);

	//music setup
	if (gameMusic->openFromFile("MainGame.flac"))
	{
		gameMusic->setVolume(60.0f);
		gameMusic->setLoop(true);
		gameMusic->play();
	}
	

	//texture setup
	background.loadFromFile("background.png");
	//foreground.loadFromFile("foreground.png");
	//midground.loadFromFile("midground.png");
	light.loadFromFile("rays.png");
	background.setRepeated(true);
	//foreground.setRepeated(true);
	//midground.setRepeated(true);
	light.setRepeated(true);

	//sprite setup
	backSprite.setTexture(background);
	//midSprite.setTexture(midground);
	//foreSprite.setTexture(foreground);
	lightSprite.setTexture(light);
	backSprite.setPosition(0.0f, 0.0f);
	//midSprite.setPosition(0.0f, GROUNDHEIGHT - 80.0f);
	//foreSprite.setPosition(0.0f, GROUNDHEIGHT);
	lightSprite.setPosition(0.0f, 0.0f);
	backSprite.setTextureRect(sf::IntRect(0, 0, SCREENWIDTH * 200, 720));
	//midSprite.setTextureRect(sf::IntRect(0, 0, SCREENWIDTH * 50, 80));
	//foreSprite.setTextureRect(sf::IntRect(0, 0, SCREENWIDTH * 50, 80));
	lightSprite.setTextureRect(sf::IntRect(0, 0, SCREENWIDTH * 200, 720));

	srand(static_cast <unsigned>(time(NULL)));
	scrollX = 4.0f;
	maxObjects = 10;
	player = new Player(&spriteSheet);
	spawnDelay = 0;
	netCounter = 0;
	netDelay = rand() % 500 + 100;
	netX = rand() % 900 + 300;
	netY = rand() % 700 + 20;
	levelObjects.push_back(new GameObject(NET, float(netX), -100.0f, 1.5f, 1.5f, &spriteSheet));
	score = 0;
}

//////////////////////////////////////////////////////////
//======================================================//
//					Destructor							//
//======================================================//
// This will clean up any variables.					//
//////////////////////////////////////////////////////////
Level::~Level()
{
	//gameMusic.stop();
	/*for (int i = 0; i < levelObjects.size(); ++i)
	{
	delete levelObjects[i];
	levelObjects[i] = NULL;
	}

	levelObjects.clear();

	delete player;
	player = NULL;*/
}

//////////////////////////////////////////////////////////
//======================================================//
//					  UserInterface				     	//
//======================================================//
// This method will update all the UI elements			//
//////////////////////////////////////////////////////////
void Level::UserInterface()
{
	green.setSize(sf::Vector2f(float(player->life) * 2.0f, 30.0f));
	lifeText.setString("Life:\n \t\t\t" + std::to_string(int(player->life)));
	distanceText.setString("Distance:\n" + std::to_string(player->distance / 100) + " Metres");
	scoreText.setString("Score:\n" + std::to_string(player->score) + " Points");
}

State* Level::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		gameMusic->stop();
		return new MenuState(*this);
	}
	if (player->life == 0.0f)
	{
		//use game over method instead
		score = player->score;
		gameMusic->stop();
		return new HighScoreState(*this);
	}
	return NULL;
}

//////////////////////////////////////////////////////////
//======================================================//
//					  HandleKeyInput			     	//
//======================================================//
// This method will handle key-bind related input		//
// for thing such as puasing, quitting, muting etc.		//
//////////////////////////////////////////////////////////
void Level::HandleKeyInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		if (paused)
		{
			paused = false;
			//gameMusic.play(); 
		}
		else
		{
			paused = true;
			//gameMusic.pause();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		if (!mute)
		{
			//gameMusic.setVolume(0);
			mute = true;
		}
		else if (mute) {
			//gameMusic.setVolume(40);
			mute = false;
		}
	}
}


//////////////////////////////////////////////////////////
//======================================================//
//						Randomise					    //
//======================================================//
// This will randomise the randomiser variables when	//
// the function is called.								//
//////////////////////////////////////////////////////////
void Level::Randomise()
{
	randomiserY = static_cast <float> (rand() % (GROUNDHEIGHT - 64) + 64);
	randomiserX = static_cast <float> (rand() % 192);
	randomiserG = static_cast <float> (rand() % 100);
}


//////////////////////////////////////////////////////////
//======================================================//
//						  Update				     	//
//======================================================//
// This method will be called 60 times a second			//
// The code inside will update at the same rate.		//
//////////////////////////////////////////////////////////
void Level::Update(const sf::Time& deltaTime)
{

	HandleKeyInput();
	if (!paused)
	{

		UserInterface();
		netCounter++;
		for (unsigned int i = 0; i < levelObjects.size(); i++)
		{
			levelObjects[i]->Animate(0.005f);
		}

		scrollX += 0.0001f;
		MoveObjects();
		ObjectCollisions();
		GenerateObjects();
		player->Update(deltaTime);
	}
	else if (paused)
	{
	}
}


//////////////////////////////////////////////////////////
//======================================================//
//					  GenerateObjkects			     	//
//======================================================//
// This method will generate objects with slight random //
// -isation. It includes a spawn delay and object cap   //
//////////////////////////////////////////////////////////
void Level::GenerateObjects()
{
	if (levelObjects.size() < maxObjects && spawnDelay == 50)
	{
		Randomise();
		if (randomiserG <= 60)
		{
			levelObjects.push_back(new GameObject(BATTERY, SCREENWIDTH + randomiserX, GROUNDHEIGHT - randomiserY, 0.75f, 0.75f, &spriteSheet));
		}
		else if (randomiserG <= 80 && randomiserG > 60)
		{
			levelObjects.push_back(new GameObject(SHARK, SCREENWIDTH + randomiserX, GROUNDHEIGHT - randomiserY, 1.5f, 1.5f, &spriteSheet));
		}
		else
		{
			levelObjects.push_back(new GameObject(DIVER, SCREENWIDTH + randomiserX, GROUNDHEIGHT - randomiserY, 1.0f, 1.0f, &spriteSheet));
		}
		spawnDelay = 0;
	}
	else spawnDelay++;

}


//////////////////////////////////////////////////////////
//======================================================//
//						  MoveObjects				   	//
//======================================================//
// This method will scroll the game objects including	//
// the parallax sprites									//
//////////////////////////////////////////////////////////
void Level::MoveObjects()
{
	backSprite.move(-scrollX*0.6f, 0.0f);
	//midSprite.move(-scrollX*0.8f, 0.0f);
	//foreSprite.move(-scrollX*0.3f, 0.0f);
	//lightSprite.move(-scrollX*0.6f, 0.0f);

	for (unsigned int i = 0; i < levelObjects.size(); i++)
	{
		if (levelObjects[i]->id == NET && levelObjects[i]->getPosition().y < netY && netCounter > netDelay)
		{
			levelObjects[i]->move(0.0f, 2.3f);
		}
		if (levelObjects[i]->id != NET || netCounter > netDelay)
		{
			levelObjects[i]->move(-scrollX, 0);
		}
	}
}



//////////////////////////////////////////////////////////
//======================================================//
//					  ObjectCollisions			     	//
//======================================================//
// This method checks for collisions with objects.		//
// Different outcomes will happen based on different ID //
//////////////////////////////////////////////////////////
void Level::ObjectCollisions()
{
	for (unsigned int i = 0; i < levelObjects.size(); i++)
	{
		if (player->getGlobalBounds().intersects(levelObjects[i]->getGlobalBounds()))
		{
			if (levelObjects[i]->id == SHARK)
			{
				levelObjects.push_back(new GameObject(EXPLOSION, levelObjects[i]->getPosition().x, levelObjects[i]->getPosition().y, 4.0f, 4.0f, &spriteSheet));
				sharkSound.play();
				levelObjects.erase(levelObjects.begin() + i);
				player->life -= 20;
			}
			else if (levelObjects[i]->id == BATTERY)
			{
				levelObjects.push_back(new GameObject(EXPLOSION, levelObjects[i]->getPosition().x, levelObjects[i]->getPosition().y, 2.5f, 2.5f, &spriteSheet));
				batterySound.play();
				levelObjects.erase(levelObjects.begin() + i);
				player->life += 15;
			}
			else if (levelObjects[i]->id == DIVER)
			{
				levelObjects.push_back(new GameObject(EXPLOSION, levelObjects[i]->getPosition().x, levelObjects[i]->getPosition().y, 4.0f, 4.0f, &spriteSheet));
				diverSound.play();
				levelObjects.erase(levelObjects.begin() + i);
				player->score += 50;

			}
			else if (levelObjects[i]->id == NET)
			{
				levelObjects.push_back(new GameObject(EXPLOSION, levelObjects[i]->getPosition().x, levelObjects[i]->getPosition().y, 4.0f, 4.0f, &spriteSheet));
				player->life = 0.0f;
			}
		}
		else if (levelObjects[i]->getGlobalBounds().left < -128)
		{
			if (levelObjects[i]->id == NET)
			{
				netDelay = rand() % 2000 + 1000;
				netX = rand() % 900 + 300;
				netY = rand() % 700 + 20;
				levelObjects[i]->setPosition(float(netX), -100.0f);
			}
			else levelObjects.erase(levelObjects.begin() + i);
		}
	}
}



//////////////////////////////////////////////////////////
//======================================================//
//					  Render					     	//
//======================================================//
// This method will draw objects to the game window		//
//////////////////////////////////////////////////////////
void Level::Render()
{
	window->draw(backSprite);

	//window->draw(midSprite);
	//window->draw(foreSprite);
	//Renders level objects
	if (!levelObjects.empty())
	{
		for (unsigned int i = 0; i < levelObjects.size(); i++)
		{
			window->draw(*levelObjects[i]);
		}
	}

	//Renders player
	window->draw(*player);
	window->draw(lightSprite);
	//Renders UI elements

	window->draw(red);
	window->draw(green);
	window->draw(lifeText);
	window->draw(distanceText);
	window->draw(scoreText);

}



//////////////////////////////////////////////////////////
//======================================================//
//					    ResetLevel				     	//
//======================================================//
// Resets the level elements back to the beginning		//
//////////////////////////////////////////////////////////
void Level::ResetLevel()
{
	levelObjects.clear(); //clears all the objects of the levelObjects vector.
	player->Reset(); //executes the player object's Reset Method.
	spawnDelay = 0; //resets the delay back to 0.
}