#include<SFML\Graphics.hpp>
#include<iostream>
#include<vector>
#include"Player.h"
#include"main.h"
#include"Platform.h"
#include"sunshine.h"
#include <sstream>
#include"Menu.h"
#include"Enemy.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() 
{
sf::RenderWindow window(sf::VideoMode(512, 512), "SFML", sf::Style::Close | sf::Style::Resize);
sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
//sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
//player.setPosition(206.0f, 206.0f);

Menu menu(window.getSize().x, window.getSize().y);

sf::RectangleShape background(sf::Vector2f(5120.0f, 512.0f));
background.setPosition(0.0f, 0.0f);
sf::Texture space;
space.loadFromFile("BG03.png");
background.setTexture(&space);

sf::Texture ITEM;
ITEM.loadFromFile("sunshine 001.png");
std::vector <sunshine> itemVector;
itemVector.push_back(sunshine(&ITEM, sf::Vector2u(2, 1), 1.00f, 2000.0f, 170.0f));
itemVector.push_back(sunshine(&ITEM, sf::Vector2u(2, 1), 1.00f, 1000.0f, 250.0f));
itemVector.push_back(sunshine(&ITEM, sf::Vector2u(2, 1), 1.00f, 3150.0f, 150.0f));

sf::Texture snail;
snail.loadFromFile("fox test04.png");
std::vector <Enemy> SnailVector;
SnailVector.push_back(Enemy(&snail, sf::Vector2u(3, 4), 0.08f, 2010.0f, 170.0f));
SnailVector.push_back(Enemy(&snail, sf::Vector2u(3, 4), 0.08f, 1010.0f, 250.0f));


sf::Texture playerTexture;
playerTexture.loadFromFile("fox test06.png");
//player.setTexture(&playerTexture);

Player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 200.0f, 200.0f);

std::vector<Platform> platforms;

platforms.push_back(Platform(nullptr, sf::Vector2f(260.0f, 360.0f), sf::Vector2f(2130.0f, 400.0f)));
platforms.push_back(Platform(nullptr, sf::Vector2f(325.0f, 225.0f), sf::Vector2f(1015.0f, 400.0f)));
platforms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 30.0f), sf::Vector2f(1990.0f, 400.0f)));
platforms.push_back(Platform(nullptr, sf::Vector2f(270.0f, 170.0f), sf::Vector2f(2400.0f, 400.0f)));
platforms.push_back(Platform(nullptr, sf::Vector2f(505.0f, 350.0f), sf::Vector2f(3328.0f, 400.0f)));
platforms.push_back(Platform(nullptr, sf::Vector2f(505.0f, 220.0f), sf::Vector2f(3150.0f, 400.0f)));

platforms.push_back(Platform(nullptr, sf::Vector2f(5120.0f, 90.0f), sf::Vector2f(2560.0f, 510.0f)));

platforms.push_back(Platform(nullptr, sf::Vector2f(20.0f, 520.0f), sf::Vector2f(5130.0f, 256.0f)));
platforms.push_back(Platform(nullptr, sf::Vector2f(20.0f, 520.0f), sf::Vector2f(-10.0f, 256.0f)));
//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
//Platform platform3(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

int count;
float deltaTime = 0.0f;
sf::Clock clock;
int scoreCount = 0;

//sf::Vector2u textureSize = playerTexture.getSize();
//textureSize.x /= 3;
//textureSize.y /= 9;

//player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));
while (window.isOpen())
{
	count = player.GetPosition().x;

	deltaTime = clock.restart().asSeconds();
	sf::Vector2f pos = player.GetPosition();
	std::cout << pos.x << '  ' << pos.y << '\n';

	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::KeyReleased:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Up:
				menu.MoveUp();
				break;

			case sf::Keyboard::Down:
				menu.MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (menu.GetPressedItem())
				{
				case 0 :
					std::cout << "TEST" << std::endl;
					break;
				case 1:
					std::cout << "test" << std::endl;
					break;
				case 2:
					window.close();
					break;
				}
			}
			break;

		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized:
			ResizeView(window, view);
			break;
			//case sf::Event::Resized:
				//std::cout << "New window width: "<< evnt.size.width << "New window height: " << evnt.size.height << std::endl;
				//printf("New window width: %i New window height: %i", evnt.size.width, evnt.size.height);
				//break;
			//case sf::Event::TextEntered:
				//if (evnt.text.unicode < 128)
				//{
					//printf("%c", evnt.text.unicode);
				//}
		}
		//if (evnt.type == evnt.Closed)
		//{
			//window.close();
		//}

	}

	for (int i = 0; i < itemVector.size(); i++)
	{
		itemVector[i].update(deltaTime, player);
	}

	for (int i = 0; i < itemVector.size(); i++)
	{
		if (itemVector[i].getpoint() == 1)
		
			scoreCount += 100;
			
	}
		
		player.Update(deltaTime);

		sf::Vector2f direction;

		//for (int i = 0; i < platforms.size(); i++)
		//{
		//	Platform& platform = platforms[i];
		//}

		sf::Font font;
		font.loadFromFile("Fluo Gums.ttf");
		std::ostringstream point;
		sf::Text scoreText;
		//scoreText.setPosition(200, 200);
		//scoreText.setString(point.str());
		scoreText.setCharacterSize(20);
		scoreText.setFont(font);
		scoreText.setFillColor(sf::Color(129, 119, 95));
		//scoreText.setString(to_string(scoreCount));
		//point.str("  ");
		//point << "SCORE:  ";
		//scoreText.setString(point.str());
		scoreText.setPosition({ view.getCenter().x  ,view.getCenter().y - 200 });
		scoreText.setString("SCORE:  " + std::to_string(scoreCount));


		//sf::Text starttext("START", font, 40);
		//starttext.setPosition(200, 200);
		//sf::Text highscoretext("HIGH SCORE",font, 40);
		//sf::Text exittext("START", font, 40);

		Collider playerCollision = player.GetCollider();
		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				player.OnCollision(direction);

		//Collider playerCollision = player.GetCollider();
		//platform1.GetCollider().CheckCollision(playerCollision, 0.2f);
		//platform2.GetCollider().CheckCollision(playerCollision, 1.0f);
		view.setCenter(player.GetPosition());
		//animation.Update(0, deltaTime , false);
		//player.setTextureRect(animation.uvRect);

		window.clear(sf::Color(218,237,246));
		menu.draw(window);
		window.setView(view);
		
		//window.draw(background);
		for (Platform& platform : platforms)
			platform.Draw(window);

		window.draw(background);
		for (int i = 0; i < itemVector.size(); i++)
		{
			itemVector[i].draw(window);
		}

		for (int i = 0; i < SnailVector.size(); i++) {
			SnailVector[i].draw(window);
		}
		// Alien
		for (int i = 0; i < SnailVector.size(); i++) {
			//SnailVector[i].update1(deltaTime, bullet1);
			SnailVector[i].update2(deltaTime, player);
		}
		player.Draw(window);
		window.draw(scoreText);
		//window.draw(starttext);
		//window.draw(highscoretext);
		//window.draw(exittext);
		window.display();
	}
	return 0;
}