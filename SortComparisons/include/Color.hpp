#ifndef Color_hpp
#define Color_hpp

#include "SFML/Graphics/Color.hpp"
#include "error.h"

typedef sf::Color SFMLColor;

struct Color
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char Alpha;

	static const Color Black;
	static const Color White;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Magenta;
	static const Color Cyan;

	Color(unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char alpha = 255)
	{ R = r; G = g; B = b; Alpha = alpha;}

	~Color() {}

	Color operator +(const Color& obj) { return Color((R + obj.R  ) % 255, (G + obj.G  ) % 255, (B + obj.B  ) % 255); }
	Color operator -(const Color& obj) { return Color(R - obj.R  , G - obj.G  , B - obj.B); }
	Color operator ~() 				   { return Color(255 - R, 255 - G, 255 - B); }

	operator sf::Color() {return sf::Color(R, G, B, Alpha);}
};
#endif /* Color_hpp */ 