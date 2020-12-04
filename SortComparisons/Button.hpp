#ifndef Button_hpp
#define	Button_hpp
#include "Vector.hpp"
#include "Color.hpp"
#include "CoordSys.hpp"
#include "math.h"

typedef double (*fp)(double);


class AbstractButton
{
	protected:
		Vector size, position;

	public:
		
		AbstractButton( Vector pos, Vector sz);
		virtual ~AbstractButton () = 0;

		
		virtual void clicked	(Vector mouse_pos) = 0;
		virtual void draw		(sf::RenderTarget& target) = 0;

};

class CoordSysActionButton : public AbstractButton
{
	protected:
		CoordSys* coordSys;
	public:
		virtual void action() = 0; 
		CoordSysActionButton(Vector pos, Vector sz, CoordSys* cs);
		~CoordSysActionButton();
};

class MathButton : public CoordSysActionButton
{
	protected:
		
		Color background_color, text_color;
		sf::Text text;
		sf::Font font;
		
		
		fp function;
		bool state;


	public:
		MathButton( Vector pos, Vector sz, CoordSys* cs,
							Color backgr_color  = Color::White,
							Color txt_color 	= Color::Black, 
							const char* txt 	= "Some text", 
							fp func_pointer 	= NULL);
		~MathButton();

		void reverseColor	();
		void drawShadow		(sf::RenderTarget& target);
};

class Button : public MathButton
{
	public:

		Button 					(	Vector pos, Vector sz, CoordSys* cs,
									Color backgr_color 	= Color::White, 
									Color txt_color 	= Color::Black, 
									const char* txt 	= "Some text",
									fp func_pointer 	= NULL);

		virtual ~Button 		() override;
		
		virtual void action 	() override;
		virtual void clicked	(Vector mouse_pos) override;
		virtual void ScaleText	();
		virtual void draw 		(sf::RenderTarget& target) override;

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
		virtual ~EllipseButton 	() override;
		
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

class CrossedButton : public CoordSysActionButton
{
	public:
		
		CrossedButton(Vector pos, Vector sz, CoordSys* cs);

		virtual ~CrossedButton 	() override;
		
		virtual void action		() override;
		virtual void clicked 	(Vector mouse_pos) override;
		virtual void draw 		(sf::RenderTarget& target) override;
};


class ButtonHandler
{
	static const int NUMBER_OF_BUTTONS = 30;
	CoordSysActionButton* buttons[NUMBER_OF_BUTTONS] = {};
	size_t count = 0;

	public:
		
		ButtonHandler	();
		~ButtonHandler	();
		
		void draw 		(sf::RenderTarget& target);
		void add 		(CoordSysActionButton* but);
		void clicked	(Vector mouse_pos);
};
#endif /* Button_hpp */