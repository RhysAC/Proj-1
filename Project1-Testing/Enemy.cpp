#include <assert.h>
#include "Enemy.h"
#include "SFML/Graphics.hpp"


/*
 *IN :
 *OUT :
 *PRE_CONDITION : 
 *POST_CONDITION :  */

using namespace std;
using namespace sf;
// A place to store constants needed throughout the Enemy class
namespace CONSTANTS
{
	const float ROTATION_OFFSET{ 180.f };
	const float PI{ 3.14159265 };
	const float SCREEN_SIZE_X{ 1200.f };
	const float SCREEN_SIZE_Y{ 800.f };
	const float SCREEN_OFFSET{ 0.4f };
}

/* A function to initialise certain data for the Enemy 
 *IN : RenderWindow& window, Player& player
 *OUT : 
 *PRE_CONDITION : A valid window and player must have been set
 *POST_CONDITION : If the player / window failed to initilaise this will cause an error  */
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

/* A function to Update the logic for the Enemy
 *IN : float elapsed, RenderWindow& window
 *OUT :
 *PRE_CONDITION : An elapsed time and render window must have been set, the enemy must also be active in the scene
 *POST_CONDITION : The enemy will carry out the updates to the logic of the game regarding itself */
void Enemy::Update(float elapsed, RenderWindow& window)
{
	LookAtPlayer();
}

/* A function to Render any updates for the Enemy
 *IN 
 *OUT :
 *PRE_CONDITION : The local pointer to the window must be working or we wont be able to draw anything to the screen 
 *POST_CONDITION : Any active enemy will show on the current render window */
void Enemy::Render()
{
	pWindow->draw(spr);
}

/* A function to make the Enemy look in the direction of the Player
 *IN
 *OUT :
 *PRE_CONDITION : The local pointer to the Player must be working or we wont be able to reference it's position
 *POST_CONDITION : The enemy will rotate so that it looks towards the player's current position*/
void Enemy::LookAtPlayer()
{
	//This part works out a vector between the enemy and players position and rotates it in the correct direction
	Vector2f pos = spr.getPosition();
	float dx = pos.x - pPlayer->spr.getPosition().x;
	float dy = pos.y - pPlayer->spr.getPosition().y;

	float rotation = (atan2(dy, dx)) * 180 / CONSTANTS::PI;

	spr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
}