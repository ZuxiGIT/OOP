#ifndef Button_hpp
#define	Button_hpp
#include "Vector.hpp"


typedef void (*fp)();


class Button : public sf::Drawable
{
	Vector size, position;
	sf::RectangleShape Body;
	sf::Text text;
	sf::Font font;

	bool state;
	fp function;
	public:

		Button(	Vector sz, Vector pos, sf::Color backgr_color = sf::Color::White, const char* txt = "Some text",
				fp func_pointer = NULL);

		void Scale	(sf::Text text);
		void draw 	(sf::RenderTarget& target, sf::RenderStates states) const override;

};
#endif /* Button_hpp */