#include "Button.hpp"

Button::Button(Vector sz, Vector pos, sf::Color backgr_color, sf::Color txt_color, const char* txt, fp func_pointer)
{
	size = sz;
	position = pos;

	background_color	= backgr_color;
	text_color			= txt_color; 
	
	Body = sf::RectangleShape(sf::Vector2f(sz.X, sz.Y));
	Body.setPosition(pos.X, pos.Y);
	Body.setFillColor(backgr_color);
	Body.setOutlineThickness(2);
	Body.setOutlineColor(sf::Color::Red);

	font = sf::Font();
	font.loadFromFile("UbuntuMono-R.ttf");

	text = sf::Text(txt, font);
	text.setCharacterSize(30);
	text.setFillColor(text_color);

	int offset = (size.Y - text.getCharacterSize()) / 2;
	offset = offset > 0 ? offset : 0;

	printf("Offset is %d\n", offset);
	fflush(NULL);

	text.setPosition(pos.X, pos.Y + offset);
	text.setStyle(sf::Text::Bold);// | sf::Text::Underlined);

	Scale(text);

	function = func_pointer;
}

void Button::clicked(Vector mouse_pos)
{
	if ((mouse_pos.X > position.X) && (mouse_pos.X < (position.X + size.X)) && 
		(mouse_pos.Y > position.Y) && (mouse_pos.Y < (position.Y + size. Y)))
	{
		state = !state;
		text_color			= sf::Color(255,255,255) - text_color;// + sf::Color(0,0,1);
		background_color	= sf::Color::White - background_color;


		text.setFillColor(text_color);
		Body.setFillColor(background_color);
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
	target.draw(Body);
	target.draw(text);
}