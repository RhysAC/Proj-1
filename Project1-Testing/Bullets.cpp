#include "SFML/Graphics.hpp"
#include "Bullets.h"

using namespace std;
using namespace sf;

void Bullets::InitBullet(RenderWindow& window, Player& player)
{
	mpWindow = &window;
	mPlayer = &player;
}

void Bullets::UpdateBullet(vector<Bullets>& bullets)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		Shoot(bullets);
	}

	if (isActive)
	{
		MoveBullet();
	}
}

void Bullets::RenderBullet()
{
	if (isActive)
	{
		mpWindow->draw(bulletShape);
	}
}

void Bullets::MoveBullet()
{
	bulletShape.move(currentVel);

	if (bulletShape.getPosition().x > 1200 || bulletShape.getPosition().x < 0)
	{
		isActive = false;
	}

	if (bulletShape.getPosition().y > 800 || bulletShape.getPosition().y < 0)
	{
		isActive = false;
	}
}

void Bullets::Shoot(vector<Bullets>& bullets)
{
	size_t idx = 0;
	bool found = false;
	while (idx < bullets.size() && !found)
	{
		if (!bullets[idx].isActive)
			found = true;
		else
			++idx;
	}
	if (idx < bullets.size())
	{

		bullets[idx].isActive = true;
		bullets[idx].currentVel = mPlayer->aimDirNorm * maxSpeed;
		bullets[idx].bulletShape.setPosition(mPlayer->playerSpr.getPosition());
	}
}
