#include "ButtonTest.hpp"

ButtonTest::ButtonTest()
{
	std::cout << "ButtonTest start" << std::endl;

	sf::RenderWindow testWindow(sf::VideoMode(600,400),"Button test");
	testWindow.display();
	sf::Event winEvent;

	Button startBtn;
	startBtn.setText("Start");
	startBtn.setScale(0.5, 0.5);
	startBtn.setScaleText(1.5,1);
	startBtn.setPosition(testWindow.getSize().x/2 - startBtn.getSprite().getGlobalBounds().width/2,150);
	startBtn.setTextColor(sf::Color(200,200,0,255));

	Button endBtn;
	endBtn.setText("End");
	endBtn.setScale(0.5, 0.5);
	endBtn.setScaleText(1.5,1);
	endBtn.setPosition(testWindow.getSize().x/2 - startBtn.getSprite().getGlobalBounds().width/2 ,220);
	endBtn.setTextColor(sf::Color(100,200,0,255));

	std::cout << startBtn <<std::endl;

	while(testWindow.isOpen() == true)
	{
		while (testWindow.pollEvent(winEvent))
		{
			if (winEvent.key.code == sf::Keyboard::Escape)
			{
				testWindow.close();
				break;
			}

			if(winEvent.type == sf::Event::MouseMoved)
			{
				if(startBtn.isContainsMouseCursore(winEvent))
				{
					startBtn.setTextColor(sf::Color(255,0,0,255));
				}else
					startBtn.setTextColor(sf::Color(200,200,0,255));

				if(endBtn.isContainsMouseCursore(winEvent))
				{
					endBtn.setTextColor(sf::Color(255,0,0,255));
				}else
					endBtn.setTextColor(sf::Color(200,200,0,255));
			}

			if (winEvent.type == sf::Event::MouseButtonPressed)
			{
				if (winEvent.mouseButton.button == sf::Mouse::Left && endBtn.isContainsMouseCursore(winEvent) == true)
				{
					std::cout << "EXIT EVENT" << std::endl;
				}

				if (winEvent.mouseButton.button == sf::Mouse::Left && startBtn.isContainsMouseCursore(winEvent) == true)
				{
					std::cout << "start EVENT" << std::endl;
				}
			}
		}

		testWindow.clear(sf::Color(127,127,255,255));
		testWindow.draw(startBtn);
		testWindow.draw(endBtn);
		testWindow.display();
	}

	std::cout << "ButtonTest end" << std::endl;

}
