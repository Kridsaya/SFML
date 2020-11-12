#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collider.h"

class sunshine
{
public:

	sunshine(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
	~sunshine();
	void update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);

	int iscollide()
	{
		if (Csun == 1) {
			Csun--;
			return 1;
		}
	}

	int getpoint()
	{
		if (Csun == 100) {
			Csun-= 100;
			return 1;
		}
	}

	Collider GetCollider() { return Collider(body); }

private:
	int row;
	int Csun;
	int collide;
	bool faceRight;
	sf::RectangleShape body;
	Animation animation;
};

