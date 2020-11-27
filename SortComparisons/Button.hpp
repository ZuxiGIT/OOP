#ifndef Button_hpp
#define	Button_hpp
#include "Vector.hpp"
#include "Color.hpp"
#include "CoordSys.hpp"

typedef double (*fp)(double);

class Button
{
	protected:
		Vector size, position;
		Color background_color, text_color;
		sf::Text text;
		sf::Font font;

		CoordSys* coordSys; 

		bool state;
		fp function;
	public:

		Button 					(	Vector sz, Vector pos, CoordSys* cs,
									Color backgr_color 	= Color::White, 
									Color txt_color 	= Color::Black, 
									const char* txt 	= "Some text",
									fp func_pointer 	= NULL);

		void reverseColor		();
		void action 			();
		virtual void clicked	(Vector mouse_pos);
		virtual void ScaleText	();
		virtual void draw 		(sf::RenderTarget& target);

};

class EllipseButton : public Button
{
	int radius_a;
	int radius_b;
	protected:
		int quality = 70;
	public:
		EllipseButton			(	Vector pos, int a, int b, CoordSys* cs,
									Color backgr_color 	= Color::White,
									Color txt_color 	= Color::Black, 
									const char* txt 	= "Some text",
									fp func_pointer 	= NULL);

		virtual void clicked	(Vector mouse_pos) 			override;
		virtual void ScaleText	()				   			override; 
		virtual void draw 		(sf::RenderTarget& target) 	override;

};
class CircleButton : public EllipseButton
{
	int radius;
	public:
		CircleButton	(	Vector pos, int r, CoordSys* cs,
							Color backgr_color 	= Color::White,
							Color txt_color 	= Color::Black, 
							const char* txt 	= "Some text",
							fp func_pointer 	= NULL);
};

class ButtonHandler
{
	static const int NUMBER_OF_BUTTONS = 30;
	Button* buttons[NUMBER_OF_BUTTONS] = {};
	size_t count = 0;

	public:
		ButtonHandler	();

		void draw 		(sf::RenderTarget& target);
		void add 		(Button* but);
		void clicked	(Vector mouse_pos);
};
#endif /* Button_hpp */