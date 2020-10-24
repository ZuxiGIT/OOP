#include "sphere.hpp"


Vector Sphere::FongReflection(Vector point, Vector light_reflection) const
{
	Vector temp 			= LightPosition;
	temp 					= (temp - point);
	
	if((point.normalize() ^ temp.normalize()) <= 0) return 0; 

	Vector flare_aim 		= (temp * (point.normalize() ^ temp.normalize()) * 2 - temp);
	
	temp 					= Camera;
	temp 					= (temp - point);
	
	double flare_angle_cos 	= temp.normalize() ^ flare_aim.normalize();;

	//if(flare_angle_cos > 0) printf("flare_angle_cos: %lf\n", flare_angle_cos);

	double flare_coeff 		= flare_angle_cos  > 0 ? pow(flare_angle_cos, 40) : 0;
		
	//if (flare_coeff > 0.98) {printf("flare_coeff: %lf\n", flare_coeff);
	//						 printf("flare_angle_cos: %lf\n", flare_angle_cos);}
	
	return light_reflection * flare_coeff * 255;
}

Vector Sphere::LambertReflection(Vector point, Vector light_reflection, Vector col_of_sph) const 
{
	Vector temp 		= LightPosition;
	
	double angle_cos 	= (point.normalize()) ^ ((temp - point).normalize());
	double light_coeff 	= angle_cos > 0 ? angle_cos : 0;
	
	return light_reflection * light_coeff * col_of_sph;
}

Vector Sphere::AmbientReflection(Vector ambient_reflection, Vector col_of_sph) const
{
	return ambient_reflection * col_of_sph;
}

Sphere::Sphere(Vector pos, Color sphere, Color light, Color ambient, int radius, Vector light_position, Vector szOfwnd)
{
	Position 		= pos;
	ourSphere 		= sphere;
	Ambient 		= ambient;
	Radius 			= radius;
	Light 			= light;
	LightPosition 	= light_position;
	SizeOfWind 		= szOfwnd; 
	Camera 			= Vector(0, 0, 400);
}

Vector Sphere::toScreen(int x, int y) const
{
	double temp_x 	= x - (int)SizeOfWind.X / 2;
	double temp_y 	= y - (int)SizeOfWind.Y / 2;
	double temp_z	= Radius * Radius - temp_x * temp_x - temp_y * temp_y; 
	
	if (temp_z < 0)
		temp_z = 0;
	else
		temp_z = sqrt(temp_z);

	return Vector(temp_x, temp_y, temp_z);
}

Vector Sphere::toScreen(Vector obj) const
{
	return toScreen(obj.X, obj.Y);
}

void Sphere::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Image screen;
	screen.create(SizeOfWind.X, SizeOfWind.Y);

	sf::Texture texture;
	texture.create(SizeOfWind.X, SizeOfWind.Y);

	sf::Sprite sprite(texture);

	sf::Color current_col;

	Vector point;

	Vector light_reflection 	= Vector(Light.R  , Light.G  , Light.B  ) / 255 * Light.Alpha   / 255.;
	Vector ambient_reflection 	= Vector(Ambient.R, Ambient.G, Ambient.B) / 255 * Ambient.Alpha / 255.;

	Vector tmp_col;
	Vector col_of_sp = Vector(ourSphere.R, ourSphere.G, ourSphere.B);

	for (int x = 0; x < SizeOfWind.X; x ++)
	{
		for (int y = 0; y < SizeOfWind.Y; y++)
		{
			point = toScreen(x, y);
			if (point.X * point.X + point.Y * point.Y < Radius * Radius)
			{				
				tmp_col = LambertReflection(point, light_reflection, col_of_sp) +\
						  AmbientReflection(ambient_reflection, col_of_sp) +\
						  FongReflection   (point, light_reflection);

				
				tmp_col.X = tmp_col.X > 255 ? 255 : tmp_col.X;
				tmp_col.Y = tmp_col.Y > 255 ? 255 : tmp_col.Y;
				tmp_col.Z = tmp_col.Z > 255 ? 255 : tmp_col.Z;


				current_col = sf::Color(tmp_col.X, tmp_col.Y, tmp_col.Z);
			}
			else
			{
				current_col = sf::Color(Ambient.R, Ambient.G, Ambient.B, Ambient.Alpha);
			}
			screen.setPixel(x, y, current_col);
		}
	}

	texture.update(screen);
	sprite.setTexture(texture);

	target.draw(sprite);
}