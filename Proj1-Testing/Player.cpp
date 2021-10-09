#include <assert.h>
#include "Player.h"
#include "Game.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

namespace CONSTANTS 
{
	const float ROTATION_OFFSET{ 180.f };
	const float PI{ 3.14159265 };
}

Player::Player(){}

void Player::Init(RenderWindow& window) 
{
	pWindow = &window;
	if (!gunSpriteTex.loadFromFile("data/TankGun.png"))
		assert(false);
	gunSpriteTex.setSmooth(true);
	gunSprite.setTexture(gunSpriteTex);
	gunSprite.setScale(1.5, 1.5);
	IntRect texR(0, 0, 200, 200);
	gunSprite.setTextureRect(texR);
	gunSprite.setOrigin(texR.width / 2.f, texR.height / 2.f);
	gunSprite.setPosition(300, 300);

	if (!baseSpriteTex.loadFromFile("data/TankBase.png"))
		assert(false);
	baseSpriteTex.setSmooth(true);
	baseSprite.setTexture(baseSpriteTex);
	baseSprite.setScale(1.5, 1.5);
	IntRect baseTexR(0, 0, 200, 200);
	baseSprite.setTextureRect(baseTexR);
	baseSprite.setOrigin(baseTexR.width / 2.f, baseTexR.height / 2.f);
	baseSprite.setPosition(300, 300);

}

void Player::Move(float elapsed) 
{
	Vector2f pos = gunSprite.getPosition();

	if (Keyboard::isKeyPressed(Keyboard::W)) 
	{
		pos.y -= 200.f * elapsed;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		pos.x -= 200.f * elapsed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		pos.y += 200.f * elapsed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		pos.x += 200.f * elapsed;
	}

	baseSprite.setPosition(pos.x, pos.y + 15);
	gunSprite.setPosition(pos);
}

void Player::Update(float elapsed, RenderWindow& window)
{
	LookAtMouse(window);
	Move(elapsed);
}

void Player::Render()
{
	pWindow->draw(baseSprite);
	pWindow->draw(gunSprite);
}

void Player::LookAtMouse(RenderWindow& window)
{
	Vector2f pos = gunSprite.getPosition();
	Vector2i mousePos = Mouse::getPosition(window);

	float dx = pos.x - mousePos.x;
	float dy = pos.y - mousePos.y;

	float rotation = (atan2(dy, dx)) * 180 / CONSTANTS::PI;

	gunSprite.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
}