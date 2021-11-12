#include <assert.h>
#include <math.h>
#include "Bullet.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

void Bullet::Init() 
{
	if (!sprTex.loadFromFile("data/Bullet_Ui.png"))
		assert(false);
	sprTex.setSmooth(true);
	spr.setTexture(sprTex);
	spr.setScale(0.5, 0.5);
	IntRect texR(0, 0, 100, 100);
	spr.setTextureRect(texR);
	spr.setOrigin(50, 50);
}

void Bullet::Hit(GameObject& other)
{
	active = false;
	other.active = false;
}

void BulletMgr::Update()
{
	//The bullet is moved in the direction of the normalized vector with it's velocity set
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].active)
		{
			bullets[i].spr.move(bullets[i].currentVel);

			//If the bullet exits the screen we erase it to save on performance
			if (bullets[i].spr.getPosition().x < 0 || bullets[i].spr.getPosition().x > 1200
				|| bullets[i].spr.getPosition().y < 0 || bullets[i].spr.getPosition().y > 800)
			{
				bullets[i].active = false;
			}
		}
	}
}

void BulletMgr::Render(RenderWindow& window)
{
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].active)
		{
			window.draw(bullets[i].spr);
		}
	}
}