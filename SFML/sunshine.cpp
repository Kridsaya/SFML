#include "sunshine.h"
#include<iostream>

sunshine::sunshine(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y):
    animation(texture, imageCount, switchTime)
{
    Csun = 0;
    collide = 0;
    row = 0;
    body.setSize(sf::Vector2f(35.0f, 44.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

sunshine::~sunshine()
{

}

void sunshine::update(float deltaTime, Player player)
{
    animation.updatesunshine(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    Collider playerCollision = player.GetCollider();

    if (playerCollision.CheckCollision(this->GetCollider())) 
    {
        Csun++;
        body.setPosition(-100, 80);
    }
}

void draw(sf::RenderWindow& window)
{
    window.draw(body);
}