#include <assert.h>
#include <math.h>
#include "Player.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf; 

void Bullet::Init() 
{
	alive = false;
}

void Bullet::Update(vector<Bullet>& bullets)
{
	//The bullet is moved in the direction of the normalized vector with it's velocity set
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].alive) 
		{
			bullets[i].bulletShape.move(bullets[i].currentVel);

			//If the bullet exits the screen we erase it to save on performance
			if (bullets[i].bulletShape.getPosition().x < 0 || bullets[i].bulletShape.getPosition().x > 1200
				|| bullets[i].bulletShape.getPosition().y < 0 || bullets[i].bulletShape.getPosition().y > 800)
			{
				bullets[i].alive = false;
			}
		}
	}
}

void Bullet::Render(RenderWindow& window, vector<Bullet>& bullets)
{
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].alive)
		{
			window.draw(bullets[i].bulletShape);
		}
	}
}

void Bullet::FireBullet(Vector2f& pos, Vector2f& aimDirNorm, vector<Bullet>& bullets)
{
	size_t idx = 0;
	bool found = false;
	while (idx < bullets.size() && !found)
	{
		if (!bullets[idx].alive)
			found = true;
		else
			++idx;
	}
	if (idx < bullets.size())
	{
		bullets[idx].alive = true;
		bullets[idx].currentVel = aimDirNorm * maxSpeed;
		bullets[idx].bulletShape.setPosition(pos);
	}
}