#include "sphere.hpp"


Vector Sphere::PhongReflection(Vector point, Vector ambient_reflection, Vector col_of_sph) const
{
	Vector Result;
	Vector norm_col;
	size_t size = lights.size();

	for (std::size_t i = 0; i < size; i++)
	{
		Vector temp             = lights[i].position;
		temp                    = (temp - point);

		//point.X += sin(10000 * point.X + 1e8) * 10;
		//point.Y += cos(10 * point.Z) * 500;
		point.Z += sin(10000 * point.Z + 1e8) * 10;
		

		if ((point.normalize() ^ temp.normalize()) < -1e-3) continue;
		
		Vector flare_aim        = ( point.normalize() * (point.normalize() ^ temp.normalize()) * 2 - temp.normalize());
		
		temp                    = Camera;
		temp                    = (temp - point);
		
		double flare_angle_cos  = temp.normalize() ^ flare_aim;//,normalize();

		double flare_coeff 		= flare_angle_cos > 0 ? pow(flare_angle_cos, 10) : 0;
		
		norm_col = lights[i].Normalized_color;
		Result = Result + norm_col * flare_coeff * 255;
	}
	return Result + LambertReflection(point, ambient_reflection, col_of_sph);
}

Vector Sphere::LambertReflection(Vector point, Vector ambient_reflection, Vector col_of_sph) const 
{
	Vector Result;
	Vector norm_col;
	size_t size = lights.size();

	for (std::size_t i = 0; i < size; i++)
	{
		Vector temp         = lights[i].position;
		
		//point.Z += sin(1e4 * point.Z + 1e8) * 10;

		double angle_cos    = (point.normalize()) ^ ((temp - point).normalize());
		double light_coeff  = angle_cos > 0 ? angle_cos : 0;

		norm_col = lights[i].Normalized_color;
		Result = Result + norm_col * light_coeff * col_of_sph;
	}
	
	return Result + AmbientReflection(ambient_reflection, col_of_sph);
}

Vector Sphere::AmbientReflection(Vector ambient_reflection, Vector col_of_sph) const
{
	return ambient_reflection * col_of_sph;
}

Sphere::Sphere(Vector pos, Color sphere, int radius, Color light, Vector light_position, Color ambient, Vector szOfwnd)
{
	Position 		= pos;
	ourSphere 		= sphere;
	Ambient 		= ambient;
	Radius 			= radius;
	SizeOfWind 		= szOfwnd; 
	Camera 			= Vector(0, 0, 400);

	lights.push_back(Light(light_position, light));
}

Vector Sphere::toScreen(int x, int y) const
{
	double temp_x 	= x - (int)SizeOfWind.X / 2;
	double temp_y 	= y - (int)SizeOfWind.Y / 2;
	double temp_z	= Radius * Radius - temp_x * temp_x - temp_y * temp_y; 
	
	if (temp_z <= 0)
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
				tmp_col = PhongReflection (point, ambient_reflection, col_of_sp);

				//printf("tmp_col: %lf %lf %lf\n", tmp_col.X, tmp_col.Y, tmp_col.Z);
				
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