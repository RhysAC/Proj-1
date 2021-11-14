#pragma once
#include "Player.h"
#include "Utils.h"
#include "GameObject.h"
#include "SFML/Graphics.hpp"

//Enemy class derived from the Player as they share the same characteristics
class Enemy : public GameObject
{
public:
	//Default constructor
	Enemy() {};

	/* A function to initialise certain data for the Enemy
	*IN : Player& player
	*OUT :
	*PRE_CONDITION : player must have been set
	*POST_CONDITION : If the player failed to initilaise this will cause an error  */
	void Init(Player& player);

	void Hit(GameObject& other);

	//A function to move the enemy towards the player using a given direction
	void MoveEnemy();

	void ResetEnemy();

	//A local pointer to the Player
	Player* pPlayer = nullptr;

private:
	//A texture for the Enemy sprite
	sf::Texture sprTex;
	//Enemy speed value
	float enemySpeed = 2.f;

};

class EnemyMgr
{
public:
	EnemyMgr()
	{
		enemies.insert(enemies.begin(), 20, Enemy());
	};

	/* A function to Update the logic for the Enemy
	*IN : float elapsed, RenderWindow& window
	*OUT :
	*PRE_CONDITION : An elapsed time and render window must have been set, the enemy must also be active in the scene
	*POST_CONDITION : The enemy will carry out the updates to the logic of the game regarding itself */
	void Update(float elapsed, sf::RenderWindow& window);

	/* A function to Render any updates for the Enemy
	*IN
	*OUT :
	*PRE_CONDITION : The local pointer to the window must be working or we wont be able to draw anything to the screen
	*POST_CONDITION : Any active enemy will show on the current render window */
	void Render(sf::RenderWindow& window);

	void SpawnEnemy();

	Enemy* NewEnemy()
	{
		size_t i = 0;
		while (i < enemies.size() && enemies[i].active == true) ++i;
		if (i >= enemies.size())
			return nullptr;
		enemies[i].active = true;
		return &enemies[i];
	}

	float spawnTimer = 0;

	//A vector to be populated with bullets
	std::vector<Enemy> enemies;
};

