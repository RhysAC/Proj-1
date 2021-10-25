#include "Game.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

Game::Game()
	: mState(StateMachine::WAITING_INIT) 
{}

void Game::Init(RenderWindow& window)
{
	player.Init(window);
	enemy.Init(window, player);
	mState = StateMachine::SPLASH_SCREEN;
}

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

void Game::Render(RenderWindow& window)
{
	switch (mState)
	{
	case StateMachine::SPLASH_SCREEN:
		
		break;
	case StateMachine::PLAY:
		player.Render();
		enemy.Render();
		break;
	}
}
