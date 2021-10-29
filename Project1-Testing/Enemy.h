#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"

//Enemy class derived from the Player as they share the same characteristics
class Enemy : public Player
{
public:
	//Default constructor
	Enemy() {};

	/* A function to initialise certain data for the Enemy
	*IN : RenderWindow& window, Player& player
	*OUT :
	*PRE_CONDITION : A valid window and player must have been set
	*POST_CONDITION : If the player / window failed to initilaise this will cause an error  */
	void Init(sf::RenderWindow& window, Player& player);

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
	void Render();

private:
	//A function to move the enemy towards the player using a given direction
	void MoveEnemy();

	//The enemy sprite
	sf::Sprite spr;
	//A texture for the Enemy sprite
	sf::Texture sprTex;
	//A local pointer to the main Render window
	sf::RenderWindow* pWindow = nullptr;
	//A local pointer to the Player
	Player* pPlayer = nullptr;
	//Enemy speed value
	const float enemySpeed = 2.f;

};

