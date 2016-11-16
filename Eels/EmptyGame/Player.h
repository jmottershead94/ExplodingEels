#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	public:
		Player(sf::Texture* texture);
		~Player();
		void Render();
		void Update(const sf::Time& dt);
		double life;
		int score;
		int distance;
		void Reset();
		
	private:
		void HandleInput(const sf::Time& dt);
		sf::Vector2f velocity;
		float gravity;
		float jumpSpeed;
		
		
};

