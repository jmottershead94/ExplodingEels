#include "GameObject.h"
#include "Application.h"
GameObject::GameObject(int ID, float x, float y, float width, float height, sf::Texture* texture)
{
	//Set Position and Dimentions
	setPosition(x, y);
	setScale(width, height);
	id = ID;
	animationFrameDuration = 0.1f;
	animationTime = 0.0f;
	doneAnimation = false;

	//Put textures in here
	switch (ID)
	{
	case PLAYER:
	{
		textureRect = { 0, 0, 128, 64 };
		setTextureRect(textureRect);
		numOfFrames = 4;
		break;
	}
	case BATTERY:
	{
		textureRect = { 0, 64, 128, 64 };
		setTextureRect(textureRect);
		//numOfFrames = 16;
		break;
	}
	case SHARK:
	{
		textureRect = { 0, 192, 128, 64 };
		setTextureRect(textureRect);
		numOfFrames = 4;
		break;
	}
	case DIVER:
	{
		textureRect = { 0, 256, 128, 64 };
		setTextureRect(textureRect);
		break;
	}
	case NET:
	{
		textureRect = { 0, 128, 128, 64 };
		setTextureRect(textureRect);
		break;
	}
	case EXPLOSION:
	{
		textureRect = { 0, 320, 32, 32 };
		setTextureRect(textureRect);
		numOfFrames = 16;
		break;
	}
	}
	texture->setSmooth(true);
	setTexture(*texture);
}

GameObject::~GameObject()
{
}

void GameObject::Animate(float ticks)
{
	animationTime += ticks;

	if (animationTime > animationFrameDuration)
	{
		animationTime -= animationFrameDuration;
		textureRect.left += textureRect.width;
		if (textureRect.left > (numOfFrames - 1) * textureRect.width)
		{
			doneAnimation = true;
			textureRect.left = 0;
		}
		setTextureRect(textureRect);
	}
}

void GameObject::Update()
{
}