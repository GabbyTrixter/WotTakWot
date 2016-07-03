#ifndef BUTTONTEST_H
#define BUTTONTEST_H

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Button.hpp"
#include <iostream>

/**
 * @brief The ButtonTest class
 * Проводит тестирование класса Button
 *
 * ПРОБЛЕММЫ!
 * При развертывании окна на весь экран ломается отслеживание позиции курсора.
 * НУжно уточнить, принцип работы методов получения кординат в bool Button::isContainsMouseCursore(sf::Event e)
 */
class ButtonTest
{
	public:
		/**
		 * @brief ButtonTest
		 * Создаёт окно
		 * Для выхода жми ESC
		 * Создаёт две кнопкм
		 * 1) Start
		 * 2) End
		 *
		 * Обрабатывает события нажатия и наведения на кнопки
		 */
		ButtonTest();
};

#endif // BUTTONTEST_H
