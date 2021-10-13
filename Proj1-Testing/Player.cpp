#include <assert.h>
#include <math.h>
#include "Player.h"
#include "Game.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

namespace CONSTANTS 
{
	const float ROTATION_OFFSET{ 180.f };
	const float PI{ 3.14159265 };
	const float SCREEN_SIZE_X{ 1200.f };
	const float SCREEN_SIZE_Y{ 800.f };
	const float SCREEN_OFFSET{ 0.4f };
}

Player::Player(){}

void Player::Init(RenderWindow& window) 
{
	mousePos = Vector2f(Mouse::getPosition(window));
	pWindow = &window;
	if (!playerSprTex.loadFromFile("data/Player-Sprite-Test.png"))
		assert(false);
	playerSprTex.setSmooth(true);
	playerSpr.setTexture(playerSprTex);
	playerSpr.setScale(0.5, 0.5);
	IntRect texR(0, 0, 200, 200);
	playerSpr.setTextureRect(texR);
	playerSpr.setOrigin(texR.width / 2.f, texR.height / 2.f);
	playerSpr.setPosition(300, 300);

}

void Player::Move(float elapsed) 
{
	Vector2f pos = playerSpr.getPosition();
	FloatRect rect = playerSpr.getGlobalBounds();

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

	//Stop the sprite from exiting the screen
	if (pos.x < (rect.width * CONSTANTS::SCREEN_OFFSET))
	{
		pos.x = rect.width * CONSTANTS::SCREEN_OFFSET;
	}
	if (pos.x > (CONSTANTS::SCREEN_SIZE_X - rect.width * CONSTANTS::SCREEN_OFFSET))
	{
		pos.x = CONSTANTS::SCREEN_SIZE_X - rect.width * CONSTANTS::SCREEN_OFFSET;
	}
	if (pos.y > (CONSTANTS::SCREEN_SIZE_Y - rect.height * CONSTANTS::SCREEN_OFFSET))
	{
		pos.y = CONSTANTS::SCREEN_SIZE_Y - rect.height * CONSTANTS::SCREEN_OFFSET;
	}
	if (pos.y < (rect.height * CONSTANTS::SCREEN_OFFSET))
	{
		pos.y = rect.height * CONSTANTS::SCREEN_OFFSET;
	}

	playerSpr.setPosition(pos);
}

void Player::Update(float elapsed, RenderWindow& window)
{
	Aim(window);
	LookAtMouse(window);
	Move(elapsed);
}

void Player::Render()
{
	pWindow->draw(playerSpr);
}

void Player::Aim(RenderWindow& window) 
{
	mousePos = Vector2f(Mouse::getPosition(window));
	Vector2f aimDir = mousePos - playerSpr.getOrigin();
	aimDirNorm = aimDir / (static_cast<float> (sqrt( pow(aimDir.x, 2) + pow(aimDir.y, 2))));
}

void Player::LookAtMouse(RenderWindow& window)
{
	Vector2f pos = playerSpr.getPosition();
	mousePos = Vector2f(Mouse::getPosition(window));

	float dx = pos.x - mousePos.x;
	float dy = pos.y - mousePos.y;

	float rotation = (atan2(dy, dx)) * 180 / CONSTANTS::PI;

	playerSpr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
}

void Player::Shoot() 
{
	if (Mouse::isButtonPressed(Mouse::Left)) 
	{

	}
}