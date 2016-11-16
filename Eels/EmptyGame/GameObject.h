#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

using sf::Sprite;
enum  OBJECTID{ PLAYER = 0, BATTERY, DIVER, SHARK, NET, EXPLOSION};

class GameObject : public Sprite
{
	public:
		GameObject(int ID, float x, float y, float width, float height, sf::Texture* texture);
		~GameObject();
		void Animate(float ticks);
		void Update();
		sf::IntRect textureRect;
		sf::FloatRect rect;
		int numOfFrames, id;
		bool doneAnimation;
		float animationFrameDuration, animationTime;
		
};

