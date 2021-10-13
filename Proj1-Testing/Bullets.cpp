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

}

void Bullets::RenderBullet()
{
	mpWindow->draw(bulletShape);
}

void Bullets::MoveBullet() 
{
	
}
