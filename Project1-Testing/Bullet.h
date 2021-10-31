#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{
public:
	Bullet(float radius = 5.f)
		: currentVel(0.f, 0.f), maxSpeed(30.f)
	{
		this->bulletShape.setFillColor(sf::Color::Yellow);
		this->bulletShape.setRadius(radius);
	};

	sf::CircleShape bulletShape;
	sf::Vector2f currentVel;
	float maxSpeed;
	bool alive = false;
};

class BulletMgr 
{
public:
	BulletMgr()
	{
		bullets.insert(bullets.begin(), 50, Bullet());
	};

	void Update();

	void Render(sf::RenderWindow& window);

	Bullet* NewBullet() 
	{
		size_t i = 0;
		while (i < bullets.size() && bullets[i].alive == true) ++i;
		if (i >= bullets.size())
			return nullptr;
		bullets[i].alive = true;
		return &bullets[i];
	}

	//A vector to be populated with bullets
	std::vector<Bullet> bullets;
};


