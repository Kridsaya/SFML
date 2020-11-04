#include<SFML\Graphics.hpp>
#include<iostream>
#include<vector>
#include"Player.h"
#include "main.h"
#include"Platform.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() 
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML", sf::Style::Close | sf::Style::Resize );
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	//sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	//player.setPosition(206.0f, 206.0f);

	sf::RectangleShape background(sf::Vector2f(3072.0f, 512.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("cherry bd02.png");
	background.setTexture(&space);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("fox test06.png");
	//player.setTexture(&playerTexture);

	Player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 200.0f, 200.0f);

	std::vector<Platform> platforms;

	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 300.0f), sf::Vector2f(1740.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(1700.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3072.0f, 200.0f), sf::Vector2f(1536.0f, 510.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(20.0f, 520.0f), sf::Vector2f(3082.0f, 256.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(20.0f, 520.0f), sf::Vector2f(-10.0f, 256.0f)));
	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	//Platform platform3(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

	int count;
	float deltaTime = 0.0f;
	sf::Clock clock;

	//sf::Vector2u textureSize = playerTexture.getSize();
	//textureSize.x /= 3;
	//textureSize.y /= 9;

	//player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));
	while (window.isOpen())
	{
		count = player.GetPosition().x;

		deltaTime=clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << '  ' << pos.y << '\n';

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
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

		
		player.Update(deltaTime);

		sf::Vector2f direction;

		//for (int i = 0; i < platforms.size(); i++)
		//{
		//	Platform& platform = platforms[i];
		//}

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		//Collider playerCollision = player.GetCollider();
		//platform1.GetCollider().CheckCollision(playerCollision, 0.2f);
		//platform2.GetCollider().CheckCollision(playerCollision, 1.0f);
		view.setCenter(player.GetPosition());
		//animation.Update(0, deltaTime , false);
		//player.setTextureRect(animation.uvRect);

		window.clear(sf::Color(150,150,150));
		window.setView(view);
		
		
		window.draw(background);
		for (Platform& platform : platforms)
			platform.Draw(window);

		//window.draw(background);
		player.Draw(window);
		window.display();
	}
	return 0;
}