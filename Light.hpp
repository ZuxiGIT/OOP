#ifndef Light_hpp
#define Light_hpp

#include "Vector.hpp"
#include "Color.hpp"

class Light
{	
public:
	Vector 	position;
	Color 	color;
	Vector 	Normalized_color;

	Light(Vector pos, Color col);
};
#endif /* Light_hpp */