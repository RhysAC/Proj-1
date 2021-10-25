#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

//Enemy class derived from the Player as they share the same characteristics
class Enemy : public Player
{
public:
	//Default constructor
	Enemy() {};
	//A function to initialise data for the Enemy
	void Init(RenderWindow& window, Player& player);
	//Update logic
	void Update(float elapsed, RenderWindow& window);
	//Render changes
	void Render();

private:
	//A function to look towards the player
	void LookAtPlayer();
	//The enemy sprite
	Sprite spr;
	//A texture for the Enemy sprite
	Texture sprTex;
	//A local pointer to the main Render window
	RenderWindow* pWindow = nullptr;
	//A local pointer to the Player
	Player* pPlayer = nullptr;
};

