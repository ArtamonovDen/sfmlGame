#include "Ovo.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//Ovo aHero("darthvader.png");
	//Player Hero("darthvader.png", 4, 4, 1, 2, 50,50);

	sf::RenderWindow window(sf::VideoMode(400, 400), " Abandon all hope, ye who enter here");
	sf::CircleShape shape(200.f);
	shape.setFillColor(sf::Color::Red);

	int c_x = 32;
	int c_y = 48;

	sf::Texture texture;
	texture.loadFromFile("darthvader.png");
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(50, 50);
	sprite.setTextureRect(sf::IntRect(0, 0, c_x, c_y));

	// load a 32x32 rectangle that starts at (10, 10)	
	// load a 32x32 rectangle that starts at (10, 10)
	//heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 48));
	//heroSprite.setPosition(sf::Vector2f(100, 100));
	//heroSprite.setScale(sf::Vector2f(1.2f, 1.2f));
	//sprite.setColor(sf::Color(0, 255, 0)); // green
	//sprite.setColor(sf::Color(255, 255, 255, 60));


	sf::Clock clock;
	float curFrame = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		//std::cout << time << std::endl;
		time = time /200; //Game speed
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code ==
				sf::Keyboard::Escape)){
				window.close();
				break;
			}
			/*if (event.type == sf::Event::LostFocus){
				std::cout << "Go back, faggot" << std::endl;
			}
			if (event.type == sf::Event::GainedFocus){
				std::cout << "Alright" << std::endl;
			}*/
			//if (event.type == sf::Event::TextEntered)
			//{
			//	if (event.text.unicode < 128)
			//		std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
			//}
			//if (event.type == sf::Event::MouseWheelMoved)
			//{
			//	std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
			//	std::cout << "mouse x: " << event.mouseWheel.x << std::endl;
			//	std::cout << "mouse y: " << event.mouseWheel.y << std::endl;
			//}

			//if (event.type == sf::Event::MouseButtonPressed)
			//{
			//	if (event.mouseButton.button == sf::Mouse::Right)
			//	{
			//		std::cout << "the right button was pressed" << std::endl;
			//		std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			//		std::cout << "mouse y: " << event.mouseButton.y << std::endl;
			//	}
			//}

			//if (event.type == sf::Event::MouseMoved)
			//{
			//	std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
			//	std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			//{
			//	// left key is pressed: move our character
			//	std::cout << "qqq" << std::endl;
			//}
			//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			//{
			//	// left mouse button is pressed: shoot
			//	//gun.fire();
			//}
					


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					curFrame += 0.1*time;
					if (curFrame >= 4) curFrame = 0;

					sprite.move(-0.1*time, 0);
					sprite.setTextureRect(sf::IntRect(c_x*int(curFrame), c_y, c_x, c_y));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
					curFrame += 0.1*time;
					if (curFrame >= 4) curFrame = 0;
					sprite.move(0.1*time, 0);
					sprite.setTextureRect(sf::IntRect(c_x*int(curFrame), 2 * c_y, c_x, c_y));
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					curFrame += 0.1*time;
					if (curFrame >= 4) curFrame = 0;

					sprite.move(0, -0.1*time);
					sprite.setTextureRect(sf::IntRect(c_x*int(curFrame), 3 * c_y, c_x, c_y));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					curFrame += 0.1*time;
					if (curFrame >= 4) curFrame = 0;

					sprite.move(0, 0.1*time);

					sprite.setTextureRect(sf::IntRect(c_x*int(curFrame), 0, c_x, c_y));
				}

			
		}
		

				//if (event.type == sf::Event::KeyPressed){


				//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				//	{
				//		Hero.dir = 1;
				//		//Hero.update(1, time);
				//	}
				//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				//		Hero.dir = 0;
				//		//Hero.update(0, time);
				//	}

				//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				//	{
				//		Hero.dir = 3;
				//		//Hero.update(3, time);
				//	}
				//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				//	{
				//		Hero.dir = 2;
				//		//Hero.update(2, time);
				//	}
				//	

				//}
				//Hero.update(1, time);

				/*if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						heroSprite.setColor(sf::Color::Red);
					}
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						heroSprite.setColor(sf::Color(255, 255, 255));
					}
				}*/



			
			//Hero.m_sprite.setPosition(100,100);
			//Hero.m_texture.update(window);
			window.clear();
			window.draw(shape);
			window.draw(sprite);
			//window.draw(Hero.m_sprite);
			window.display();

		}




		
	return 0;
}

//sf::Event event;
//
//// while there are pending events...
//while (window.pollEvent(event))
//{
//	// check the type of the event...
//	switch (event.type)
//	{
//		// window closed
//	case sf::Event::Closed:
//		window.close();
//		break;
//
//		// key pressed
//	case sf::Event::KeyPressed:
//		...
//			break;
//
//		// we don't process other types of events
//	default:
//		break;
//	}
//}