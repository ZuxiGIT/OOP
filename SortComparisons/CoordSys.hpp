#ifndef CoordSys_hpp
#define CoordSys_hpp
#include "Vector.hpp"


class CoordSys
{
	Vector size, position;
	size_t step;

	Vector Xrange, Yrange;

    public:
        
        CoordSys(Vector position 	= Vector(10,10),
				 Vector size 		= Vector(400,400),
				 size_t step		= 10);

        void setRanges(Vector Xrange, Vector Yrange);
        Vector getXrange();

        void draw(sf::RenderTarget& target) const;

};

#endif