#ifndef Sphere_hpp
#define Sphere_hpp
#include "Vector.hpp"
#include "Color.hpp"
#include "Light.hpp"
#include <math.h>

class Sphere : public sf::Drawable
{

	Vector Position;
	Vector SizeOfWind;
	int Radius;
	int num_of_lights;

	Vector toScreen(int x, int y) const;
	Vector toScreen(Vector point) const;

	Vector PhongReflection	(Vector point, Vector ambient_reflection, Vector col_of_sph) const;
	Vector LambertReflection(Vector point, Vector ambient_reflection, Vector col_of_sph) const; 
	Vector AmbientReflection(Vector ambient_reflection, Vector col_of_sph) const;
	public:

		Color ourSphere;
		
		std::vector<Light> lights;
		Color Ambient; 
		Vector Camera;		

		Sphere(Vector	pos,
			   Color 	sphere,
			   int   	radius,
			   Color 	light,
			   Vector	light_position,
			   Color 	ambient,
			   Vector 	szOfwind);


		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif /* Sphere_hpp */