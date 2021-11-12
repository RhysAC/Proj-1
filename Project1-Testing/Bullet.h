#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Utils.h"

class Bullet : public GameObject
{
public:
	Bullet()
		: currentVel(0.f, 0.f), maxSpeed(30.f)
	{};

	void Init();
	void Hit(GameObject& other);
	sf::Texture sprTex;
	sf::Vector2f currentVel;
	float maxSpeed;
};

class BulletMgr
{
public:
	BulletMgr()
	{
		bullets.insert(bullets.begin(), 20, Bullet());

		for (size_t i = 0; i < bullets.size(); ++i)
			bullets[i].Init();
	};

	void Update();

	void Render(sf::RenderWindow& window);

	Bullet* NewBullet()
	{
		size_t i = 0;
		while (i < bullets.size() && bullets[i].active == true) ++i;
		if (i >= bullets.size())
			return nullptr;
		bullets[i].active = true;
		return &bullets[i];
	}

	//A vector to be populated with bullets
	std::vector<Bullet> bullets;
};


