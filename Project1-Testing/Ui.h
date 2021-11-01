#pragma once
#include "SFML/Graphics.hpp"

struct HudPos
{
	float posX;
	float posY;
};

class Ui
{
public:
	Ui() {};

	void Init(sf::Texture& tex);

	void Update();

	void Render(sf::RenderWindow& window);

	sf::Sprite sprite;

private:

	sf::Texture spriteTex;

	sf::IntRect texRect;

	sf::Vector2f pos;
};

class GunUi : public Ui 
{
public:
	GunUi() {};

	void Init(sf::Texture& tex);

	void UpdateMag(int ammo);

	void Render(sf::RenderWindow& window);

	sf::Sprite sprite;

	std::vector<GunUi> bullets;

private:
	// Vector for the positions that the Hud bullet elements will be rendered
	std::vector<HudPos> hudPos = { {125.f, 46.f}, {127.f, 53.f}, {129.f, 60.f}, {131.f, 67.f}, {136.f, 74.f}, {140.f, 81.f}, {140.f, 88.f} };

	sf::Texture spriteTex;

	sf::IntRect texRect;

	sf::Vector2f pos;

	bool active;
};

