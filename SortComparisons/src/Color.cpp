#include "Color.hpp"

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char Alpha)
{
	R 		= r;
	G 		= g;
	B 		= b;
	Alpha 	= Alpha;
}

const Color Color::Black 		(  0, 	0, 	 0);
const Color Color::White 		(255, 255, 255);
const Color Color::Red 			(255, 	0, 	 0);
const Color Color::Green		(  0, 255,   0);
const Color Color::Blue			(  0, 	0, 255);
const Color Color::Yellow		(255, 255,   0);
const Color Color::Magenta 		(255,   0, 255);
const Color Color::Cyan 		(128, 255, 255);

Color Color::operator+(const Color& obj)
{
	return Color((R + obj.R  ) % 255, (G + obj.G  ) % 255, (B + obj.B  ) % 255);
}


Color Color::operator-(const Color& obj)
{
	return Color(R - obj.R  , G - obj.G  , B - obj.B  );
}

