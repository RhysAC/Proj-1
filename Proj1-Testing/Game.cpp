#include "Game.h"
#include "Bullets.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

Game::Game(){}

void Game::Init(RenderWindow& window) 
{
	player.Init(window);

	Bullets bullet;
	bullet.InitBullet(window, player);
	bullets.push_back(Bullets(bullet));
}

void Game::Update(float elapsed, RenderWindow& window)
{
	player.Update(elapsed, window);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].UpdateBullet();
	}
}

void Game::Render()
{
	player.Render();

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].RenderBullet();
	}
}