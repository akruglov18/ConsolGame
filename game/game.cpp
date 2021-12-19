#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), sf::String("SFML Works!"));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(250, 220, 100, 0));

		sf::CircleShape circle(50.f);

		circle.setFillColor(sf::Color(230, 0, 230));

		window.draw(circle);

		window.display();
	}

	return 0;
}