#include "Button.hpp"
#include <math.h>

Button::Button(Vector sz, Vector pos, sf::Color backgr_color, sf::Color txt_color, const char* txt, fp func_pointer)
{
	size = sz;
	position = pos;

	background_color	= backgr_color;
	text_color			= txt_color; 
	
	font = sf::Font();
	font.loadFromFile("UbuntuMono-R.ttf");

	text = sf::Text(txt, font);
	text.setCharacterSize(20);
	text.setFillColor(text_color);
	text.setStyle(sf::Text::Bold);// | sf::Text::Underlined);

	ScaleText();

	function = func_pointer;
}

void Button::clicked(Vector mouse_pos)
{
	if ((mouse_pos.X > position.X) && (mouse_pos.X < (position.X + size.X)) && 
		(mouse_pos.Y > position.Y) && (mouse_pos.Y < (position.Y + size. Y)))
	{
		state = !state;
		text_color			= sf::Color(255 - text_color.r,			255 - text_color.g , 		255 - text_color.b);
		background_color	= sf::Color(255 - background_color.r,	255 - background_color.g, 	255 - background_color.b);


		text.setFillColor(text_color);
	}
}

void Button::ScaleText()
{
	unsigned int glyph_height 	= text.getCharacterSize();
	unsigned int glyph_width 	= text.getCharacterSize() / 2;

	const char* str 			= text.getString().toAnsiString().c_str();
	size_t num_of_glyphs 		= 0;
	
	while(*str++)	num_of_glyphs++; 
	
	printf("Button: height is %u and width is %u and num of glyphs : %zu\n", glyph_height, glyph_width, num_of_glyphs);
	fflush(NULL);
	
	double Xscale 				= (size.X - 4)	/ (num_of_glyphs * glyph_width);
	double Yscale 				= (size.Y )		/ (glyph_height);
	
	Xscale = Xscale > 1 ? 1 : Xscale; 
	Yscale = Yscale > 1 ? 1 : Yscale;

	printf("Button: Xscale is %lf and Yscale is %lf\n", Xscale, Yscale);
	fflush(NULL);

	int Xoffset = (size.X - num_of_glyphs * glyph_width) / 2;
	int Yoffset = (size.Y - glyph_height) / 2;

	Xoffset = Xoffset > 0 ? Xoffset : 0;
	Yoffset = Yoffset > 0 ? Yoffset : 0;

	printf("For rectangleButton Offset is (%d; %d)\n", Xoffset, Yoffset);
	fflush(NULL);

	text.setPosition(position.X + Xoffset, position.Y + Yoffset);
	text.setScale(Xscale, Yscale);
}


void Button::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
	
	sf::RectangleShape Body(sf::Vector2f(size.X, size.Y));
	Body.setPosition(position.X, position.Y);
	Body.setFillColor(background_color);
	Body.setOutlineThickness(2);
	Body.setOutlineColor(sf::Color::Red);

	target.draw(Body);
	target.draw(text);
}


//------------------------------------ELLIPSE-------------------------------------------
EllipseButton::EllipseButton(	Vector pos, int a, int b, sf::Color backgr_color,
								sf::Color txt_color, const char* txt,
								fp func_pointer) 
:	
	Button(Vector(2*a, 2*b), Vector(pos.X, pos.Y), backgr_color, txt_color, txt, func_pointer),
	radius_a(a), 
	radius_b(b)
{
	ScaleText();
}


void EllipseButton::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

	sf::ConvexShape ellipse;
	ellipse.setPosition(position.X, position.Y);
	ellipse.setFillColor(background_color);
	ellipse.setOutlineThickness(2);
	ellipse.setOutlineColor(sf::Color::Red);
	ellipse.setPointCount(quality);

	for(int i = 0; i < quality; i++)
	{
	    float rad 	= (360 / quality * i) / ( 360 / M_PI / 2);
	    float x 	= cos(rad) * radius_a;
	    float y 	= sin(rad) * radius_b;

	    ellipse.setPoint(i, sf::Vector2f(x,y));
	}
	target.draw(ellipse);
	target.draw(text);
}

void EllipseButton::ScaleText()
{
	unsigned int glyph_height 	= text.getCharacterSize();
	unsigned int glyph_width 	= text.getCharacterSize() / 2;

	const char* str 			= text.getString().toAnsiString().c_str();
	size_t num_of_glyphs 		= 0;
	
	while(*str++)	num_of_glyphs++; 
	
	printf("EllipseButton: height is %u and width is %u and num of glyphs : %zu\n", glyph_height, glyph_width, num_of_glyphs);
	fflush(NULL);

	double y = text.getCharacterSize() / 2;
	double x = sqrt(1 -  y * y / radius_b / radius_b ) * radius_a;

	double right_height = 2 * y;
	double right_width 	= 2 * x;

	printf("EllipseButton: RIGHT SIZE IS (width %lf; height %lf)\n", right_width, right_height);

	double Xscale =  (right_width - 4) 	/ (num_of_glyphs * glyph_width);
	double Yscale =	 right_height 			/ (glyph_height);

	Xscale = Xscale > 1 ? 1 : Xscale; 
	Yscale = Yscale > 1 ? 1 : Yscale;


	printf("EllipseButton: Xscale is %lf and Yscale is %lf\n", Xscale, Yscale);
	fflush(NULL);
	
	int Xoffset = (size.X - num_of_glyphs * glyph_width) / 2;
	int Yoffset = (size.Y - glyph_height) / 2;

	Xoffset = Xoffset > 0 ? Xoffset : 0;
	Yoffset = Yoffset > 0 ? Yoffset : 0;

	printf("For EllipseButton Offset is (%d; %d)\n", Xoffset, Yoffset);
	fflush(NULL);

	text.setPosition(position.X  - radius_a + Xoffset, position.Y - radius_b + Yoffset);
	text.setScale(Xscale, Yscale);
}

void EllipseButton::clicked(Vector mouse_pos)
{	
	int X = mouse_pos.X - position.X;
	int Y = mouse_pos.Y - position.Y;
	int a = radius_a;
	int b = radius_b;

	if (X * X / (a * a) + Y * Y / (b * b) <= 1)
	{
		state = !state;
		text_color			= sf::Color(255 - text_color.r,			255 - text_color.g , 		255 - text_color.b);
		background_color	= sf::Color(255 - background_color.r,	255 - background_color.g, 	255 - background_color.b);


		text.setFillColor(text_color);
	}
}



//-------------------------------CIRCLE---------------------------------------
CircleButton::CircleButton(	Vector pos, int r, sf::Color backgr_color,
							sf::Color txt_color, const char* txt,
							fp func_pointer)
:
EllipseButton(pos, r, r, backgr_color, txt_color, txt, func_pointer),
radius(r)
{}

//-----------------------------ButtonHandler-----------------------------------
ButtonHandler::ButtonHandler(Button but[], size_t size)
:	buttons(but), count(size)
{}

void ButtonHandler::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t i = 0; i < count; i ++)
		buttons[i].draw(target, states);  
}