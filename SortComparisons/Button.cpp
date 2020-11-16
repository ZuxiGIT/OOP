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

	int offset = (size.Y - text.getCharacterSize()) / 2;
	offset = offset > 0 ? offset : 0;

	printf("For rectangleButton Offset is %d\n", offset);
	fflush(NULL);

	text.setPosition(pos.X, pos.Y + offset);
	text.setStyle(sf::Text::Bold);// | sf::Text::Underlined);

	//Scale(text);

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

void Button::Scale(sf::Text)
{
	unsigned int glyph_height 	= text.getCharacterSize();
	unsigned int glyph_width 	= text.getCharacterSize() / 2;

	const char* str 			= text.getString().toAnsiString().c_str();
	size_t num_of_glyphs 		= 0;
	
	while(*str++)	num_of_glyphs++; 
	
	printf("height is %u and width is %u and num of glyphs : %zu\n", glyph_height, glyph_width, num_of_glyphs);
	fflush(NULL);
	
	double Xscale 				= (size.X - 10)	/ (num_of_glyphs * glyph_width);
	double Yscale 				= (size.Y )		/ (glyph_height);
	
	Yscale = Yscale > 1 ? 1 : Yscale;
	Xscale = Xscale > 1 ? 1 : Xscale; 

	printf("Xscale is %lf and Yscale is %lf\n", Xscale, Yscale);
	fflush(NULL);
	
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

EllipseButton::EllipseButton(	Vector pos, int a, int b, sf::Color backgr_color,
								sf::Color txt_color, const char* txt,
								fp func_pointer) 
:	
	Button(Vector(a, b), Vector(pos.X, pos.Y), backgr_color, txt_color, txt, func_pointer), 
	radius_a(a), 
	radius_b(b)
{
	int offset = (size.Y - text.getCharacterSize()) / 2;
	offset = offset > 0 ? offset : 0;

	printf("For rectangleButton Offset is %d\n", offset);
	fflush(NULL);
	text.setPosition(pos.X - a / 2, pos.Y - b / 2 + offset);
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

CircleButton::CircleButton(	Vector pos, int r, sf::Color backgr_color,
							sf::Color txt_color, const char* txt,
							fp func_pointer)
:
EllipseButton(pos, r, r, backgr_color, txt_color, txt, func_pointer),
radius(r)
{}

