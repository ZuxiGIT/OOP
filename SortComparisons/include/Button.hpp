#ifndef Button_hpp
#define	Button_hpp
#include "extern.hpp"
#include "CoordSys.hpp"
#include "Color.hpp"

typedef double (*fp)(double);

//????????????????????????????????????????????????????????????????????

class CoordSysButton : public ActionButton
{
	protected:
		CoordSys* coordSys;
	public: 
		CoordSysButton(Vector pos, Vector sz, CoordSys* cs);
		~CoordSysButton();
};

class MathButton : public CoordSysButton
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

class CrossedButton : public CoordSysButton
{
	public:
		
		CrossedButton(Vector pos, Vector sz, CoordSys* cs);

		virtual ~CrossedButton 	() override;
		
		virtual void action		() override;
		virtual void clicked 	(Vector mouse_pos) override;
		virtual void draw 		(sf::RenderTarget& target) override;
};




#endif /* Button_hpp */