#include "Game.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

Game::Game(){}

void Game::Init(RenderWindow& window) 
{
	mPlayer.Init(window);
}

void Game::Update(float elapsed, RenderWindow& window)
{
	mPlayer.Update(elapsed, window);
}

void Game::Render()
{
	mPlayer.Render();
}