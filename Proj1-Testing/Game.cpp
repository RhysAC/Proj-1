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
	bullets.insert(bullets.begin(), 50, bullet);
}

void Game::Update(float elapsed, RenderWindow& window)
{
	player.Update(elapsed, window);

	for (size_t i = 0; i < bullets.size(); ++i)
	{
		bullets[i].UpdateBullet(bullets);
	}
}

void Game::Render()
{
	player.Render();

	for (size_t i = 0; i < bullets.size(); ++i)
	{
		bullets[i].RenderBullet();
	}
}