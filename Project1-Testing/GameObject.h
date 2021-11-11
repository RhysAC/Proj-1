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

	void CheckCollision(std::vector<GameObject>& objects);

	virtual void Hit(GameObject& other) {};

	sf::Sprite spr;

	bool active;

private:

	sf::Texture spriteTex;

	bool colliding;

	float speed;
	float radius = 100.f;
};

