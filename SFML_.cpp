// SFML_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
double pi = 3.14159265359;
class circle {
public:
	sf::Vector2f pos;
	float angle = 0; 
	int radius;

	circle(sf::Vector2f pos_, int radius_) {
		pos = pos_;
		radius = radius_;

	};
	sf::Vector2f ret_next(float angle_iter) {
		if (angle > 2 * pi) {
			angle = 0;
		}
		angle += angle_iter;
		temp.x = pos.x + (std::cosf(angle) * radius);
		temp.y = pos.y + (std::sinf(angle) * radius);
		return temp;

	};
	void set_pos(sf::Vector2f val) {
		pos = val;
		return;
	}
private:
	sf::Vector2f temp{0.0f, 0.0f};
};



int main()
{
	sf::RectangleShape bruh;
	bruh.setSize({ 1,1 });
	bruh.setFillColor(sf::Color::Red);

	//srand(time(NULL));
    sf::RenderWindow window({ 800,800 }, "hello");

    sf::Event event;

	circle first({400,400},70);
	circle second({ 0,0 }, 20);
	circle thrid({ 0,0 }, 84);

    std::cout << "Hello World!\n";
	while (window.isOpen() == true) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		second.set_pos(first.ret_next(0.005));
		thrid.set_pos(second.ret_next(0.04));
		bruh.setPosition(thrid.ret_next(1));
		//draw plants
		//window.clear(sf::Color::Black);//clear to black 

		window.draw(bruh);
		window.display();
	}
	return 0;
}
