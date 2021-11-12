#pragma once
#include "SFML/Graphics.hpp"
#include "Utils.h"

class GameObject
{
public:
	GameObject() {};

	void Init();

	void Update(std::vector<GameObject>& objects);

	void Render();

	virtual void Hit(GameObject& other) {};

	sf::Sprite spr;

	bool active = false;

	bool colliding;

	float radius = 100.f;

private:

	sf::Texture spriteTex;

	float speed;
};

