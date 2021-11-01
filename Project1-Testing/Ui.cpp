#include <assert.h>
#include "Ui.h"

using namespace std;
using namespace sf;

namespace CONSTANTS 
{
	const float UI_SCREEN_OFFSET_X = 0.f;
	const float UI_SCREEN_OFFSET_Y = -40.f;
}

void Ui::Init(Texture& tex) 
{
	spriteTex = tex;
	sprite.setTexture(spriteTex);
}

void Ui::Update() 
{
	
}

void Ui::Render(RenderWindow& window) 
{
	window.draw(sprite);
}

void GunUi::Init(Texture& tex)
{
	active = true;
	spriteTex = tex;
	sprite.setTexture(spriteTex);
	sprite.setScale(0.5f, 0.5f);
	sprite.setPosition(CONSTANTS::UI_SCREEN_OFFSET_X, CONSTANTS::UI_SCREEN_OFFSET_Y);
}

void GunUi::UpdateMag(int ammo)
{
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		for (size_t ii = 0; ii < hudPos.size(); ++ii) 
		{
			//Go through the vector and update accordingly so that the bullets in the hud corrolate with the ammo count
			bullets[i].sprite.setPosition(hudPos[i].posX, hudPos[i].posY);

			if (ammo == 7)
				bullets[i].active = true;
			else
				bullets[i].active = false;
		}
	}
}

void GunUi::Render(RenderWindow& window)
{
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (active == true) 
		{
			window.draw(bullets[i].sprite);
		}
	}

	window.draw(sprite);
}