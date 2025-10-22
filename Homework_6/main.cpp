#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(500,500), "Homework6");

	const int cellSize = 50;
	const int gridSize = 10;

	sf::RectangleShape cells[gridSize][gridSize];


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		for (int i = 0; i < gridSize; i++)
		{
			for (int j = 0; j < gridSize; j++)
			{
				cells[i][j].setSize(sf::Vector2f(cellSize - 1, cellSize - 1));
				cells[i][j].setPosition(i * cellSize, j * cellSize);

				if ((i>2 && i < 7) && (j > 2 && j < 7)) 
				{
					cells[i][j].setFillColor(sf::Color::Green);
				}
				else 
				{
					cells[i][j].setFillColor(sf::Color::White);
				}

				cells[i][j].setOutlineColor(sf::Color::Black);
				cells[i][j].setOutlineThickness(1);

				window.draw(cells[i][j]);
			}
		}

		window.display();
	}

	return 0;
}