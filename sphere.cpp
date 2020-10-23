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
	double angle_cos;
	double light_coeff;

	Vector light_reflection 	= Vector(Light.R  , Light.G  , Light.B  ) / 255 * Light.Alpha   / 255.;
	Vector ambient_reflection 	= Vector(Ambient.R, Ambient.G, Ambient.B) / 255 * Ambient.Alpha / 255.;

	Vector tmp_col;
	Vector col_of_sp = Vector(ourSphere.R, ourSphere.G, ourSphere.B);
	Vector temp = LightPosition;

	for (int x = 0; x < SizeOfWind.X; x ++)
		for (int y = 0; y < SizeOfWind.Y; y++)
		{
			point = toScreen(x, y);
			if (point.X * point.X + point.Y * point.Y < Radius * Radius)
			{
				angle_cos 	= (point.normalize()) ^ ((temp - point).normalize());
				light_coeff = angle_cos > 0 ? angle_cos : 0;
				
				tmp_col = col_of_sp * (light_reflection * light_coeff + ambient_reflection);
				
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

		texture.update(screen);
		sprite.setTexture(texture);

		target.draw(sprite);
}