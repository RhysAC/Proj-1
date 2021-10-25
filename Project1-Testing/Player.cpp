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

/*A function to initialise certain data for the Player
 *IN : RenderWindow& window
 *OUT : 
 *PRE_CONDITION : A valid window must have been set
 *POST_CONDITION : The pointer will reference the passed in window and the player sprite will be set */
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
}

/* A function to move the player 
 *IN : float elapsed
 *OUT : 
 *PRE_CONDITION : A valid elapsed time must have been passed in
 *POST_CONDITION : The player will move smoothly using the elapsed time as a buffer, They will be confined to the screen */
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

/* A function to Update the logic for the Player, and move the bullets belonging to it
 *IN : float elapsed, RenderWindow& window
 *OUT :
 *PRE_CONDITION : An elapsed time and render window must have been set, there must also be a valid bullets vector to use
 *POST_CONDITION : The player will update it's logic and update the bullets accordingly */
void Player::Update(float elapsed, RenderWindow& window)
{
	//We use this to establish a fire rate for the player
	timer += elapsed;

	Aim(window);
	LookAtMouse(window);
	Move(elapsed);

	//If we choose to fire, set the bullet to the players position and add another one to the vector
	if (Mouse::isButtonPressed(Mouse::Left) && timer > fireRate)
	{
		bullet.bulletShape.setPosition(spr.getPosition());
		bullet.currentVel = aimDirNorm * bullet.maxSpeed;
		bullets.push_back(Bullets(bullet));
		timer = 0;
	}

	//The bullet is moved in the direction of the normalized vector with it's velocity set
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].bulletShape.move(bullets[i].currentVel);

		//If the bullet exits the screen we erase it to save on performance
		if (bullets[i].bulletShape.getPosition().x < 0 || bullets[i].bulletShape.getPosition().x > 1200
			|| bullets[i].bulletShape.getPosition().y < 0 || bullets[i].bulletShape.getPosition().y > 800)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

/* A function to Render changes to the player and the bullets belonging to it
 *IN : 
 *OUT :
 *PRE_CONDITION : The pointer to the window must be correctly set
 *POST_CONDITION : All changes will be drawn to the current window */
void Player::Render()
{
	pWindow->draw(spr);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		pWindow->draw(bullets[i].bulletShape);
	}
}

/* A function that establishes the direction the player is aiming and intending to fire
 *IN : RenderWindow& window
 *OUT :
 *PRE_CONDITION : Here we have to pass in the window as the pointer does not work in this context
 *POST_CONDITION : A normalized direction vector is established to be used outside the function */
void Player::Aim(RenderWindow& window)
{
	mousePos = Vector2f(Mouse::getPosition(window));
	Vector2f aimDir = mousePos - spr.getPosition();
	// N = V / Sqrt(V.x^2 + V.y^2)
	aimDirNorm = aimDir / (static_cast<float> (sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2))));
}

/* A function that rotates the sprite to look at the mouse position in relation to the render window
 *IN : RenderWindow& window
 *OUT :
 *PRE_CONDITION : Here we have to pass in the window as the pointer does not work in this context
 *POST_CONDITION : The sprite looks towards the mouse's current position*/
void Player::LookAtMouse(RenderWindow& window)
{
	Vector2f pos = spr.getPosition();
	mousePos = Vector2f(Mouse::getPosition(window));

	float dx = pos.x - mousePos.x;
	float dy = pos.y - mousePos.y;

	float rotation = (atan2(dy, dx)) * 180 / CONSTANTS::PI;

	spr.setRotation(rotation + CONSTANTS::ROTATION_OFFSET);
}
