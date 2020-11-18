#include "Enemy.h"
#include<iostream>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    body.setSize(sf::Vector2f(110.0f, 90.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Enemy::~Enemy()
{
}

/*void Enemy::update1(float deltaTime, Bullet bullet1)
{
    animation.updateItem(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);
    }
}*/

void Enemy::update2(float deltaTime, Player player)
{
    if (abs(player.GetPosition().x - body.getPosition().x) <= 500.0f)
    {
        velocity.y = 0;
        velocity.x = 80;
        if (player.GetPosition().x < body.getPosition().x)
        {
            body.move(-velocity * deltaTime);
        }
        else if (player.GetCollider().CheckCollision(this->GetCollider()))
        {
            x1 += 10;
            body.setPosition(-100.0f, 350.0f);
        }
        animation.updateenemy(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }

}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(body);
}