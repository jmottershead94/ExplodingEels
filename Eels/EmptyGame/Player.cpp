#include "Player.h"
#include "Application.h"
#include "Level.h"
#include <iostream>
Player::Player(sf::Texture* texture) : GameObject(PLAYER, 64, SCREENHEIGHT * 0.3f, 1.0f, 1.0f, texture) // add playersize vector (sf::vector2i playersize ... ) and use .x .y etc.
{ 
	gravity = 0.3f;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	jumpSpeed = 5.2f;
	Reset();
	// modify above values to get the best jumping for the game, we'll see which is the most responsive and intuitive for the player (needs to be small distance otherwise they wil accidentally hit stufF)
}

Player::~Player()
{
}

void Player::Reset()
{
	//The position of the player will go here 
	score = 0;
	distance = 0;
	life = 100;
}

void Player::Update(const sf::Time& dt)
{
	HandleInput(dt);
	//GameObject::Update();
	GameObject::Animate(0.01f);
	if (life > 100)
		life = 100;
	else if (life > 0)
		life -= 0.05;
	else
		life = 0;
	distance += 5;
}
void Player::HandleInput(const sf::Time& dt)
{
	//Input just for the player here
	//if player position + player size (y axis) or velocity is 0, apply gravity
	//otherwise set it to the ground position and set the velocity to 0
	//if player position is below 0 (0 is top of screen, 720 is bottom), set him at 0 so he cant go further
	//if mouse button is pressed (use sf::mouse), set velocity (y axis) to the jump speed (has to be negative as the y axis starts from 0 at the top)
	//use the move() function to change the the players position in the y axis (it offsets)

	if (getPosition().y + 64 < SCREENHEIGHT || velocity.y < 0)
	{
		velocity.y += gravity;
	}
	else 
	{
		velocity.y = 0;
		setPosition(getPosition().x, SCREENHEIGHT - 64);
	}

	if (getPosition().y < 0) 
	{
		setPosition(getPosition().x, 0);
	}

	//PLAYER INPUT CHECK

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		velocity.y = -jumpSpeed;
	}

	//CHANGE PLAYER HEIGHT

	move(0, velocity.y);
}
