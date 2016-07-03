#ifndef BUTTON_H
#define BUTTON_H
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class Button: public sf::Drawable
{
	public:

		Button();
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	friend std::ostream &operator<<( std::ostream &output, const Button & btn)
	{
		output << "Button: " << std::endl;
		output << "Text: " << btn.getText().getString().toAnsiString() <<std::endl;
		output << "Text XY: " << btn.getText().getPosition().x << ", " << btn.getSprite().getPosition().y << std::endl;
		output << "Text WH: " << btn.getText().getLocalBounds().width << ", " << btn.getText().getLocalBounds().height << std::endl;
		output << "Sprite XY: " << btn.getSprite().getPosition().x << ", " << btn.getSprite().getPosition().y << std::endl;
		output << "Sprite WH: " << btn.getSprite().getLocalBounds().width << ", " << btn.getSprite().getLocalBounds().height << std::endl;
		return output;
	}

	sf::Text getText() const;
	void setText(std::string str);

	sf::Sprite getSprite() const;
	void setPosition(float x, float y);
	void setScale(float x, float y);
	void setScaleText(float x, float y);
	void setTextColor(sf::Color color);

	bool isContainsMouseCursore(sf::Event e);

	private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Font font;
	sf::Text text;



};

#endif // BUTTON_H
