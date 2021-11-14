#pragma once
#include "SFML/Graphics.hpp"
#include "Utils.h"
#include <string>

class GameObject
{
public:
	GameObject() {};

	void Init();

	void Update(std::vector<GameObject*>& objects);

	void Render();

	void CheckCollision(std::vector<GameObject*>& objects);

	virtual void Hit(GameObject& other) {
		speed = speed;
	};

	sf::Sprite spr;

	bool active = false;
	bool colliding = false;

	std::string tag; 
private:

	sf::Texture spriteTex;

	float speed;
	float radius = 20.f;
};

