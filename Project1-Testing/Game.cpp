#include "Game.h"
#include "Bullets.h"
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

Game::Game() {}

void Game::Init(RenderWindow& window)
{
	player.Init(window);
}

void Game::Update(float elapsed, RenderWindow& window)
{
	timer += elapsed;

	player.Update(elapsed, window);

	if (Mouse::isButtonPressed(Mouse::Left) && timer > 0.5f)
	{
		bullet.bulletShape.setPosition(player.playerSpr.getPosition());
		bullet.currentVel = player.aimDirNorm * bullet.maxSpeed;
		bullets.push_back(Bullets(bullet));
		timer = 0;
	}

	for (size_t i = 0; i < bullets.size(); i++) 
	{
		bullets[i].bulletShape.move(bullets[i].currentVel);

		if (bullets[i].bulletShape.getPosition().x < 0 || bullets[i].bulletShape.getPosition().x > 1200
			|| bullets[i].bulletShape.getPosition().y < 0 || bullets[i].bulletShape.getPosition().y > 800)
		{
			bullets.erase(bullets.begin() + i);
		}

		std::cout << bullets.size() << "\n";
	}

}

void Game::Render(RenderWindow& window)
{
	player.Render();

	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i].bulletShape);
	}
}
