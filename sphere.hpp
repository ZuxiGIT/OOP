#ifndef Sphere_hpp
#define Sphere_hpp
#include "Vector.hpp"
#include "Color.hpp"
#include <math.h>

class Sphere : public sf::Drawable
{

	Vector Position;
	Vector SizeOfWind;
	int Radius;

	Vector toScreen(int x, int y) const;
	Vector toScreen(Vector point) const;
	public:

		Color ourSphere;
		Color Light;
		Color Ambient; 
		Vector LightPosition;
		

		Sphere(Vector	pos,
			   Color 	sphere,
			   Color 	light,
			   Color 	ambient,
			   int   	radius,
			   Vector	light_position,
			   Vector 	szOfwind);


		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif /* Sphere_hpp */