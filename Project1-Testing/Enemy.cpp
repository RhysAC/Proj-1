#include <assert.h>
#include "Enemy.h"
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

void Enemy::Init(Player& player)
{
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
	active = false;
	tag = "Enemy";
}

void Enemy::MoveEnemy()
{
	Vector2f pos = spr.getPosition();
	Vector2f otherPos = pPlayer->spr.getPosition();
	Vector2f dir = Getdirection(pos, otherPos);
	Vector2f aimDir = otherPos - pos;
	float length = GetVectorLength(pos, otherPos);
	if (length < 100)
	{
		enemySpeed = 0.f;
	}
	else
		enemySpeed = 2.f;
	Vector2f vel = GetCurrentVel(dir, enemySpeed);
	spr.move(vel);
}

void Enemy::Hit(GameObject& object)
{
}

void Enemy::ResetEnemy() 
{
	if (colliding == false) 
	{
		active = true;
		spr.setPosition(GetRandPosOffScreen());
	}
	else 
	{
		active = false;
	}
}

void EnemyMgr::Update(float elapsed, RenderWindow& window)
{
	spawnTimer += elapsed;
	if (spawnTimer > 2) 
	{
		SpawnEnemy();
		spawnTimer = 0;
	}

	for (size_t i = 0; i < enemies.size(); ++i) 
	{
		Vector2f pos = enemies[i].spr.getPosition();
		Vector2f otherPos = enemies[i].pPlayer->spr.getPosition();
		float rotation = LookAt(pos, otherPos);
		enemies[i].spr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
		enemies[i].MoveEnemy();
	}
}

void EnemyMgr::Render(RenderWindow& window)
{
	for (size_t i = 0; i < enemies.size(); ++i) 
	{
		if (enemies[i].active)
			window.draw(enemies[i].spr);
	}
}

void EnemyMgr::SpawnEnemy()
{
	Enemy* e = NewEnemy();
	if (e)
	{
		e->ResetEnemy();
	}
}