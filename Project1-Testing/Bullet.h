#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{
public:
	//All temporary , to be replaced with a sprite. Default constructor may be replaced with an Init function
	Bullet(float radius = 5.f)
		: currentVel(0.f, 0.f), maxSpeed(30.f)
	{
		this->bulletShape.setFillColor(sf::Color::Yellow);
		this->bulletShape.setRadius(radius);
	};

	void Init();

	void Update(std::vector<Bullet>& bullets);

	void Render(sf::RenderWindow& window, std::vector<Bullet>& bullets);

	void FireBullet(sf::Vector2f& pos, sf::Vector2f& aimDirNorm, std::vector<Bullet>& bullets);

	sf::CircleShape bulletShape;
	sf::Vector2f currentVel;
	float maxSpeed;
	bool alive = false;
};

