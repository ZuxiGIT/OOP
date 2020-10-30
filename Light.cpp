#include "Light.hpp"

Light::Light(Vector pos, Color col)
{
	position 			= pos;
	color 				= col;
	Normalized_color 	= Vector(col.R, col.G, col.B) / 255 * col.Alpha / 255.;
}
