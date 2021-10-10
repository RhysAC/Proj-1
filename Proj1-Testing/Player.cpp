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
	if (!playerSprTex.loadFromFile("data/Player-Sprite-Test.png"))
		assert(false);
	playerSprTex.setSmooth(true);
	playerSpr.setTexture(playerSprTex);
	playerSpr.setScale(1, 1);
	IntRect texR(0, 0, 200, 200);
	playerSpr.setTextureRect(texR);
	playerSpr.setOrigin(texR.width / 2.f, texR.height / 2.f);
	playerSpr.setPosition(300, 300);

}

void Player::Move(float elapsed) 
{
	Vector2f pos = playerSpr.getPosition();

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

	playerSpr.setPosition(pos);
}

void Player::Update(float elapsed, RenderWindow& window)
{
	LookAtMouse(window);
	Move(elapsed);
}

void Player::Render()
{
	pWindow->draw(playerSpr);
}

void Player::LookAtMouse(RenderWindow& window)
{
	Vector2f pos = playerSpr.getPosition();
	Vector2i mousePos = Mouse::getPosition(window);

	float dx = pos.x - mousePos.x;
	float dy = pos.y - mousePos.y;

	float rotation = (atan2(dy, dx)) * 180 / CONSTANTS::PI;

	playerSpr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
}