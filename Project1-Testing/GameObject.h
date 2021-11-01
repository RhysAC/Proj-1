#pragma once
#include "SFML/Graphics.hpp"

class GameObject
{
public:
	GameObject() {};

	void Update();

	void Render();

private:
	sf::Sprite sprite;

	sf::Texture spriteTex;

	float speed;
};

