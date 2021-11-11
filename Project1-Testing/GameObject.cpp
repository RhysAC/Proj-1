#include"GameObject.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

void GameObject::Init() 
{

};

void GameObject::Update(vector<GameObject>& objects)
{
	CheckCollision(objects);
};

void GameObject::Render()
{

};

void GameObject::CheckCollision(vector<GameObject>& objects)
{
	if (objects.size() > 1)
	{
		for (size_t i = 0; i < objects.size(); ++i)
		{
			GameObject& a = objects[i];
			if (a.active)
			{
				if (i < (objects.size() - 1))
					for (size_t ii = i + 1; ii < (objects.size()); ++ii)
					{
						GameObject& b = objects[ii];
						if (b.active)
						{
							if (CircleToCircle(a.spr.getPosition(), b.spr.getPosition(), a.radius + b.radius))
							{
								a.colliding = true;
								b.colliding = true;
								a.Hit(b);
								b.Hit(a);
							}
						}
					}
			}
		}
	}
};