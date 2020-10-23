#include "sphere.hpp"

Sphere::Sphere(Vector pos, Color sphere, Color light, Color ambient, int radius, Vector light_position, Vector szOfwnd)
{
	Position 		= pos;
	ourSphere 		= sphere;
	Ambient 		= ambient;
	Radius 			= radius;
	Light 			= light;
	LightPosition 	= light_position;
	SizeOfWind 		= szOfwnd; 
}

Vector Sphere::toScreen(int x, int y) const
{
	double temp_x 	= x - (int)SizeOfWind.X / 2;
	double temp_y 	= y - (int)SizeOfWind.Y / 2;
	double temp_z	= Radius * Radius - x * x + y * y; 
	
	if (temp_z < 0)
		temp_z = 0;	
	return Vector(temp_x, temp_y, temp_z);
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
	double angle_cos;
	double light_coeff;

	Vector light_reflection;
	Vector ambient_reflection;

	Vector tmp_col;

	for (int x = 0; x < SizeOfWind.X; x ++)
		for(int y = 0; y < SizeOfWind.Y; y++)
		{
			point = toScreen(x, y);
			//printf("-----X^2 = %lf Y^2 = %lf Radius^2 = %d  ", point.X*point.X, point.Y*point.Y, Radius*Radius);
			if (point.X * point.X + point.Y * point.Y < Radius * Radius)
			{
				/*
				Vector temp = LightPosition;
				angle_cos 	= point.normalize() ^ ((temp - point).normalize());
				light_coeff = angle_cos > 0 ? angle_cos : 0;

				light_reflection 	= Vector(Light.R  , Light.G  , Light.B  ) / 255 * Light.Alpha   / 255;
				ambient_reflection 	= Vector(Ambient.R, Ambient.G, Ambient.B) / 255 * Ambient.Alpha / 255;

				tmp_col = Vector(ourSphere.R, ourSphere.G, ourSphere.B) * (light_reflection * light_coeff + ambient_reflection);
				*/
				current_col = sf::Color(255, 255, 0);
				//printf("tmp_col: %lf %lf %lf\n", tmp_col.X, tmp_col.Y, tmp_col.Y);
				//printf("ambient_reflection : %lf %lf %lf\n", ambient_reflection.X, ambient_reflection.Y, ambient_reflection.Z);
			}
			else
			{
				current_col = sf::Color(Ambient.R, Ambient.G, Ambient.B, Ambient.Alpha);
			}
			screen.setPixel(x, y, current_col);
		}

		texture.update(screen);
		sprite.setTexture(texture);

		target.draw(sprite);
}