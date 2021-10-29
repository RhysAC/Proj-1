#include <assert.h>
#include "Enemy.h"
#include "Utils.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

// A place to store constants needed throughout the Enemy class
namespace CONSTANTS
{
	const float ROTATION_OFFSET{ 180.f };
	const float SCREEN_SIZE_X{ 1200.f };
	const float SCREEN_SIZE_Y{ 800.f };
	const float SCREEN_OFFSET{ 0.4f };
}

void Enemy::Init(RenderWindow& window, Player& player)
{
	pWindow = &window;
	pPlayer = &player;
	if (!sprTex.loadFromFile("data/Temp_Enemy.png"))
		assert(false);
	sprTex.setSmooth(true);
	spr.setTexture(sprTex);
	spr.setScale(0.5, 0.5);
	IntRect texR(0, 0, 200, 200);
	spr.setTextureRect(texR);
	spr.setOrigin(100, 100);
	spr.setPosition(800, 600);
}

void Enemy::Update(float elapsed, RenderWindow& window)
{
	Vector2f pos = spr.getPosition();
	Vector2f otherPos = pPlayer->spr.getPosition();
	float rotation = LookAt(pos , otherPos);
	spr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
	MoveEnemy();
}

void Enemy::Render()
{
	pWindow->draw(spr);
}

void Enemy::MoveEnemy()
{
	Vector2f pos = spr.getPosition();
	Vector2f otherPos = pPlayer->spr.getPosition();
	Vector2f dir = Getdirection(pos, otherPos);
	Vector2f vel = GetCurrentVel(dir, enemySpeed);
	spr.move(vel);
}
