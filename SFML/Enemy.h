
#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collider.h"
//#include "Bullet.h"


class Enemy
{
public:
    Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Enemy();
    //void update1(float deltaTime, Bullet bullet1);
    //faceRight = true;
    void update2(float deltaTime, Player player);
    void draw(sf::RenderWindow& window);
    Collider GetCollider() { return Collider(body); }

    int hit()
    {
        if (count == 1) {
            count--;
            return 1;
        }
    }

    int colSnail()
    {
        if (x1 == 10) {
            x1 -= 10;
            return 2;
        }
    }


private:
    int row;
    int count = 0;
    int x1 = 0;
    //bool faceRight;
    float speed;
    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
};