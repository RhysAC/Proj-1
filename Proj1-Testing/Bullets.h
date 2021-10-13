#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

using namespace std;
using namespace sf;

class Bullets
{
public:
	Bullets(float radius = 5.f)
		: currentVel(0.f, 0.f), maxSpeed(15.f)
	{
		this->bulletShape.setFillColor(Color::Yellow);
		this->bulletShape.setRadius(radius);
	};

	void InitBullet(RenderWindow& window, Player& player);
	void UpdateBullet();
	void RenderBullet();	
	void MoveBullet();

	CircleShape bulletShape;
	Vector2f currentVel;
	float maxSpeed;

private:
	RenderWindow* mpWindow = nullptr;
	Player* mPlayer = nullptr;
};

