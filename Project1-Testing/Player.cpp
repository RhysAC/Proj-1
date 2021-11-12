#include <assert.h>
#include <math.h>
#include "Player.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

// A place to store constants needed throughout the player class
namespace CONSTANTS
{
	const float ROTATION_OFFSET{ 180.f };
	const float PI{ 3.14159265 };
	const float SCREEN_SIZE_X{ 1200.f };
	const float SCREEN_SIZE_Y{ 800.f };
	const float SCREEN_OFFSET{ 0.4f };
}

void Player::Init(RenderWindow& window)
{
	pWindow = &window;
	if (!sprTex.loadFromFile("data/Player-Sprite-Test.png"))
		assert(false);
	sprTex.setSmooth(true);
	spr.setTexture(sprTex);
	spr.setScale(0.5, 0.5);
	IntRect texR(0, 0, 200, 200);
	spr.setTextureRect(texR);
	spr.setOrigin(150, 150);
	spr.setPosition(300, 300);
	active = true;
	ammo = 7;
	tag = "Player";
}

void Player::Move(float elapsed)
{
	Vector2f pos = spr.getPosition();
	FloatRect rect = spr.getGlobalBounds();

	//Move the player sprite
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		pos.y -= playerSpeed * elapsed;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		pos.x -= playerSpeed * elapsed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		pos.y += playerSpeed * elapsed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		pos.x += playerSpeed * elapsed;
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

	spr.setPosition(pos);
}

void Player::FireBullet(Vector2f& pos, Vector2f& aimDirNorm, BulletMgr& bulletMgr)
{
	Bullet* b = bulletMgr.NewBullet();
	if (b)
	{
		b->active = true;
		b->spr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
		b->currentVel = aimDirNorm * b->maxSpeed;
		b->spr.setPosition(pos);
	}
}

void Player::Hit(GameObject& other) 
{

}

void Player::Update(float elapsed, RenderWindow& window, BulletMgr& bulletMgr)
{
	//We use this to establish a fire rate for the player
	timer += elapsed;
	mousePos = Vector2f(Mouse::getPosition(window));
	Vector2f pos = spr.getPosition();
	aimDirNorm = Getdirection(pos, mousePos);
	rotation = LookAt(pos, mousePos);
	spr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
	Move(elapsed);

	//If we choose to fire, set the bullet to the players position and add another one to the vector
	if (Mouse::isButtonPressed(Mouse::Left) && timer > fireRate && ammo > 0)
	{
		FireBullet(pos, aimDirNorm, bulletMgr);
		ammo--;
		timer = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::R)) 
	{
		ammo = 7;
	}
}

void Player::Render(RenderWindow& window)
{
	if(active)
	pWindow->draw(spr);
}
