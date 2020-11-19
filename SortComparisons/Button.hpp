#ifndef Button_hpp
#define	Button_hpp
#include "Vector.hpp"


typedef void (*fp)();


class Button : public sf::Drawable
{
	protected:
		Vector size, position;
		sf::Color background_color, text_color;
		sf::Text text;
		sf::Font font;

		bool state;
		fp function;
	public:

		Button 					(	Vector sz, Vector pos, sf::Color backgr_color = sf::Color::White, 
									sf::Color txt_color = sf::Color::Black, const char* txt = "Some text",
									fp func_pointer = NULL);

		virtual void clicked	(Vector mouse_pos);
		virtual void ScaleText	();
		virtual void draw 		(sf::RenderTarget& target, sf::RenderStates states) const;

};

class EllipseButton : public Button
{
	int radius_a;
	int radius_b;
	protected:
		int quality = 70;
	public:
		EllipseButton			(	Vector pos, int a, int b, sf::Color backgr_color = sf::Color::White,
									sf::Color txt_color = sf::Color::Black, const char* txt = "Some text",
									fp func_pointer 	= NULL);

		virtual void clicked	(Vector mouse_pos) override;
		virtual void ScaleText	()				   override; 
		virtual void draw 		(sf::RenderTarget& target, sf::RenderStates states) const;

};
class CircleButton : public EllipseButton
{
	int radius;
	public:
		CircleButton	(	Vector pos, int r, sf::Color backgr_color = sf::Color::White,
							sf::Color txt_color = sf::Color::Black, const char* txt = "Some text",
							fp func_pointer = NULL);
};



class ButtonHandler : public sf::Drawable
{
	Button* buttons;
	size_t count;

	public:
		ButtonHandler		(Button but [], size_t size);

		virtual void draw 	(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif /* Button_hpp */