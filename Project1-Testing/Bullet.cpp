#include <assert.h>
#include <math.h>
#include "Player.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf; 

void BulletMgr::Update()
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

void BulletMgr::Render(RenderWindow& window)
{
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].alive)
		{
			window.draw(bullets[i].bulletShape);
		}
	}
}