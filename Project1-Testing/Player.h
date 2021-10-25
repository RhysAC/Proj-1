#pragma once
#include "SFML/Graphics.hpp"
#include "Bullets.h"

using namespace std;
using namespace sf;

class Player
{
public:
	//Default constructor
	Player() {};
	//Initilaise data 
	void Init(RenderWindow& window);
	//Update logic
	void Update(float elapsed, RenderWindow& window); 
	//Render changes
	void Render();
	//Player sprite, kept public to access it's position and other functions from the enemy 
	Sprite spr;

private:
	//Move the player
	void Move(float elapsed);
	//Get the aim direction
	void Aim(RenderWindow& window);
	//Roatate the sprite to look at the mouse
	void LookAtMouse(RenderWindow& window);
	//Player sprite texture
	Texture sprTex;
	//mouse position 
	Vector2f mousePos;
	//local pointer to the main render window
	RenderWindow* pWindow = nullptr;
	//The aim direction normalized
	Vector2f aimDirNorm;
	//The initial bullet object
	Bullets bullet;
	//A vector to be populated with bullets
	vector<Bullets> bullets;
	//Track the elapsed time versus the time since the last gunshot
	float timer = 0;
	float fireRate = 0.5f;
	//Player movement speed, const as it doesn't need to change
	const float playerSpeed = 200.f;
};

