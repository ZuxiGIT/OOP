#ifndef Light_hpp
#define Light_hpp
#include "Vector.hpp"
#include "Color.hpp"

struct Light
{
	Vector position;
	Color color;
	Vector Normalized_color;

	Light(Vector pos, Color col);
};

Light::Light(Vector pos, Color col)
{
	position 	= pos;
	color 		= col;
	Normalized_color =  Vector(col.R, col.G, col.B) / 255 * col.Alpha / 255.;
}

#endif /* Light_hpp */