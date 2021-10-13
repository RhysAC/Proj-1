#include "SFML/Graphics.hpp"
#include "Bullets.h"

using namespace std;
using namespace sf;

void Bullets::InitBullet(RenderWindow& window, Player& player)
{
	mpWindow = &window;
	mPlayer = &player;
}

void Bullets::UpdateBullet()
{
	Shoot();
	MoveBullet();
}

void Bullets::RenderBullet()
{
	mpWindow->draw(bulletShape);
}

void Bullets::MoveBullet() 
{
	bulletShape.move(currentVel);
}

void Bullets::Shoot()
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		bulletShape.setPosition(mPlayer->playerSpr.getPosition());
		currentVel = mPlayer->aimDirNorm * maxSpeed;
	}
}
