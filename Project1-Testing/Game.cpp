#include "Game.h"
#include "SFML/Graphics.hpp"
#include <assert.h>
#include <sstream>
#include <string>

using namespace std;
using namespace sf;

Game::Game()
	//Game starts in a 'pre-Game' stage
	: mState(StateMachine::WAITING_INIT) 
{}

/*A function to initialise certain data for the Game
 *IN : RenderWindow& window
 *OUT :
 *PRE_CONDITION : A valid window must have been set
 *POST_CONDITION : The state will be changed to the menu screen and data will be set */
void Game::Init(RenderWindow& window)
{
	if (!font.loadFromFile("data/fonts/Blacklisted.ttf"))
		assert(false);
	player.Init(window);
	enemy.Init(window, player);
	mState = StateMachine::SPLASH_SCREEN;
}

/* A function to Update the logic for the Game and change states
 *IN : float elapsed, RenderWindow& window
 *OUT :
 *PRE_CONDITION : An elapsed time and render window must have been set, every referenced object must have also been initialised
 *POST_CONDITION : The Game will update it's logic and change states where appropriate */
void Game::Update(float elapsed, RenderWindow& window)
{
	switch (mState)
	{
	case StateMachine::SPLASH_SCREEN:
		if (Keyboard::isKeyPressed(Keyboard::Space)) 
		{
			mState = StateMachine::PLAY;
		}
		break;
	case StateMachine::PLAY:
		player.Update(elapsed, window);
		enemy.Update(elapsed, window);
		break;
	}
}

/* A function to Render changes to the Game
 *IN : RenderWindow& window
 *OUT :
 *PRE_CONDITION : window must have been set, and a font must have been initialised 
 *POST_CONDITION : All changes will be drawn to the current window depending on the current state */
void Game::Render(RenderWindow& window)
{
	Text txt("Press Space", font, 20);
	txt.setFillColor(Color::White);
	txt.setScale(2, 2);
	FloatRect fr = txt.getGlobalBounds();
	txt.setPosition(window.getSize().x / 2.f - fr.width / 2, window.getSize().y / 2.f - fr.height / 2);
	switch (mState)
	{
	case StateMachine::SPLASH_SCREEN:
		window.draw(txt);
		break;
	case StateMachine::PLAY:
		player.Render();
		enemy.Render();
		break;
	}
}
