#pragma once
#include "SFML/Graphics.hpp"
#include "Bullet.h"
#include "GameObject.h"
#include "Utils.h"

class Player : public GameObject
{
public:
	//Default constructor
	Player() {};

	/*A function to initialise certain data for the Player
	*IN : RenderWindow& window
	*OUT :
	*PRE_CONDITION : A valid window must have been set
	*POST_CONDITION : The pointer will reference the passed in window and the player sprite will be set */
	void Init(sf::RenderWindow& window);

	/* A function to Update the logic for the Player, and move the bullets belonging to it
	*IN : float elapsed, RenderWindow& window
	*OUT :
	*PRE_CONDITION : An elapsed time and render window must have been set, there must also be a valid bullets vector to use
	*POST_CONDITION : The player will update it's logic and update the bullets accordingly */
	void Update(float elapsed, sf::RenderWindow& window, BulletMgr& bulletMgr);

	/* A function to Render changes to the player and the bullets belonging to it
	*IN :RenderWindow& window
	*OUT :
	*PRE_CONDITION : The pointer to the window must be correctly set
	*POST_CONDITION : All changes will be drawn to the current window */
	void Render(sf::RenderWindow& window);

	void Hit(GameObject& other);

	//Ammo counter
	int ammo;

private:
	/* A function to move the player
	 *IN : float elapsed
	*OUT :
	*PRE_CONDITION : A valid elapsed time must have been passed in
	*POST_CONDITION : The player will move smoothly using the elapsed time as a buffer, They will be confined to the screen */
	void Move(float elapsed);

	/* A function to fire a bullet from the players current location
	 *IN : Vector2f& pos, Vector2f& aimDirNorm
	*OUT :
	*PRE_CONDITION : both the passed in vectors must be valid and the player must be active in the scene
	*POST_CONDITION : A bullet will spawn at the player's location and move accordingly */
	void FireBullet(sf::Vector2f& pos, sf::Vector2f& aimDirNorm, BulletMgr& bulletMgr);

	//Player sprite texture
	sf::Texture sprTex;
	//mouse position 
	sf::Vector2f mousePos;
	//local pointer to the main render window
	sf::RenderWindow* pWindow = nullptr;
	//The aim direction normalized
	sf::Vector2f aimDirNorm;
	//Track the elapsed time versus the time since the last gunshot
	float timer = 0;
	float rotation;
	float fireRate = 0.3f;
	//Player movement speed, const as it doesn't need to change
	const float playerSpeed = 200.f;
};

