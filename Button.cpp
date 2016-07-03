#include "Button.hpp"

Button::Button()
{
	if(font.loadFromFile("Fonts/Ladybug Love Demo.ttf") != true)
	{
		std::cout << "Can not to load font." << __FILE__ <<" " << __LINE__ <<std::endl;
	}

	text.setFont(font);
	this->setText("EMPTY TEXT");
	if(texture.loadFromFile("Textures/wood_tablet.bmp", sf::IntRect(0,0, 554,142)) != true)
	{
		std::cout << "Can not to load texture." << __FILE__ <<" " << __LINE__ <<std::endl;
	}

	sprite.setTexture(texture);


}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
	target.draw(text, states);
}

sf::Sprite Button::getSprite() const
{
	return sprite;
}

void Button::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
	text.setPosition(x + sprite.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
					 y + sprite.getGlobalBounds().height/2 - text.getGlobalBounds().height);
}

void Button::setScale(float x, float y)
{
	sprite.setScale(x,y);
	text.setScale(x,y);

	this->setPosition(sprite.getPosition().x, sprite.getPosition().y);
}

void Button::setScaleText(float x, float y)
{
	text.setScale(x, y);
	setPosition(sprite.getPosition().x, sprite.getPosition().y);
}

void Button::setTextColor(sf::Color color)
{
	text.setFillColor(color);
}

bool Button::isContainsMouseCursore(sf::Event e)
{
	sf::Vector2i position;
	if(e.type == sf::Event::MouseMoved)
	{
		position.x = e.mouseMove.x;
		position.y = e.mouseMove.y;
	}
	if(e.type == sf::Event::MouseButtonPressed)
	{

		position.x = e.mouseButton.x;
		position.y = e.mouseButton.y;
	}

	if(position.x >= sprite.getPosition().x
			&& position.y >= sprite.getPosition().y)
	{
		if(position.x <= sprite.getPosition().x + sprite.getGlobalBounds().width
				&& position.y <= sprite.getPosition().y + sprite.getGlobalBounds().height)
		{
			return true;
		}
	}

	return false;
}

sf::Text Button::getText() const
{
	return text;
}

void Button::setText(std::string str)
{
	this->text.setString(str);
	this->setPosition(sprite.getPosition().x, sprite.getPosition().y);


}

