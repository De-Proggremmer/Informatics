#include <SFML/Graphics.hpp>
//
//int main()
//{
//    const int res = 1000;
//    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Gradient", sf::Style::Fullscreen);
//
//    const int gridSize = 100;
//    const int cellSize = res/gridSize;
//
//    sf::RectangleShape cells[gridSize][gridSize];
//
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridSize; j++)
//        {
//            cells[i][j].setSize(sf::Vector2f(cellSize - 2, cellSize - 2));
//            cells[i][j].setPosition(cellSize * i, cellSize * j);
//            cells[i][j].setFillColor(sf::Color(i+1, 0, j+1));
//            cells[i][j].setOutlineColor(sf::Color::White);
//            cells[i][j].setOutlineThickness(1);
//        }
//    }
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//
//        for (int i = 0; i < gridSize; i++)
//        {
//            for (int j = 0; j < gridSize; j++)
//            {
//                window.draw(cells[i][j]);
//            }
//        }
//
//        window.display();
//
//    }
//
//    return 0;
//}





int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Homework6");

	const int gridSize1 = 20;
	const int cellSize1 = 500/gridSize1;

	const int gridSize2 = 10;
	const int cellSize2 = 500 / gridSize2;


	sf::RectangleShape cells1[gridSize1][gridSize1];
	sf::RectangleShape cells2[gridSize2][gridSize2];


	for (int i = 0; i < gridSize1; i++)
	{
		for (int j = 0; j < gridSize1; j++)
		{
			cells1[i][j].setSize(sf::Vector2f(cellSize1 - 1, cellSize1 - 1));
			cells1[i][j].setPosition(i * cellSize1, j * cellSize1);

			if ((i > gridSize1 / 2 - 3 && i < gridSize1 / 2 + 2) && (j > gridSize1 / 2 - 3 && j < gridSize1 / 2 + 2))
			{
				cells1[i][j].setFillColor(sf::Color::Green);
			}
			else
			{
				cells1[i][j].setFillColor(sf::Color::White);
			}

			cells1[i][j].setOutlineColor(sf::Color::Black);
			cells1[i][j].setOutlineThickness(1);
		}
	}

	for (int i = 0; i < gridSize2; i++)
	{
		for (int j = 0; j < gridSize2; j++)
		{
			cells2[i][j].setSize(sf::Vector2f(cellSize2 - 1, cellSize2 - 1));
			cells2[i][j].setPosition(i * cellSize2, j * cellSize2);

			if ((i > gridSize2 / 2 - 3 && i < gridSize2 / 2 + 2) && (j > gridSize2 / 2 - 3 && j < gridSize2 / 2 + 2))
			{
				cells2[i][j].setFillColor(sf::Color::Green);
			}
			else
			{
				cells2[i][j].setFillColor(sf::Color::White);
			}

			cells2[i][j].setOutlineColor(sf::Color::Black);
			cells2[i][j].setOutlineThickness(1);
		}
	}

	bool flg = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();

			}

			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				flg = !flg;
			}
		}

		window.clear(sf::Color::White);

		if (flg)
		{
			for (int i = 0; i < gridSize1; i++)
			{
				for (int j = 0; j < gridSize1; j++)
				{
					window.draw(cells1[i][j]);
				}
			}
		}
		else
		{
			for (int i = 0; i < gridSize2; i++)
			{
				for (int j = 0; j < gridSize2; j++)
				{
					window.draw(cells2[i][j]);
				}
			}
		}

		window.display();
	}

	return 0;
}