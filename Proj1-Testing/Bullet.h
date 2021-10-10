#pragma once
#include "SFML/Graphics.hpp"


using namespace std;
using namespace sf;

class Bullet
{
public:
	Bullet(float radius = 5.f) 
		: currentVel(0.f, 0.f), maxSpeed(15.f)
	{
		this->bulletShape.setRadius(radius);
		this->bulletShape.setFillColor(Color::Yellow);
	};

	void InitBullet();
	void UpdateBullet();
	void RenderBullet();

	vector<Bullet> bullets;
	CircleShape bulletShape;
	Vector2f currentVel;
	float maxSpeed;

};

