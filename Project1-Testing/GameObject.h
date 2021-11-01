#pragma once
#include "SFML/Graphics.hpp"

class GameObject
{
public:
	GameObject() {};

	void Update() {};

	void Render() {};

private:
	sf::Sprite sprite;

	sf::Texture spriteTex;

	sf::Vector2f pos;

	float speed;
};

