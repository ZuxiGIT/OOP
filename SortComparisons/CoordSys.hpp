#ifndef CoordSys_hpp
#define CoordSys_hpp
#include "Vector.hpp"


class CoordSys : public sf::Drawable
{
	Vector size, position;
    public:
        
        CoordSys(Vector position 	= Vector(10,10),
				 Vector size 		= Vector(400,400));
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif