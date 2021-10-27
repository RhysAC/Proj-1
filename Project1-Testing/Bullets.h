#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

using namespace std;
using namespace sf;

class Bullets
{
public:
	//All temporary , to be replaced with a sprite. Default constructor may be replaced with an Init function
	Bullets(float radius = 5.f)
		: currentVel(0.f, 0.f), maxSpeed(30.f)
	{
		this->bulletShape.setFillColor(Color::Yellow);
		this->bulletShape.setRadius(radius);
	};

	CircleShape bulletShape;
	Vector2f currentVel;
	float maxSpeed;
};

