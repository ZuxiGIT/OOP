#ifndef CoordSys_hpp
#define CoordSys_hpp
#include "Vector.hpp"


class CoordSys
{
	Vector size, position;
	size_t step;
    public:
        
        CoordSys(Vector position 	= Vector(10,10),
				 Vector size 		= Vector(400,400),
				 size_t step		= 10);
        void draw(sf::RenderTarget& target) const;

};

#endif