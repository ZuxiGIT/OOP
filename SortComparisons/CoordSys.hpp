#ifndef CoordSys_hpp
#define CoordSys_hpp
#include "Window.hpp"
class CoordSys
{
	Vector size, position;
	size_t step;

	Vector Xrange, Yrange;

	sf::RenderWindow* win;

	Vector scalePoint(double x, double y);

    public:
        
        CoordSys(	sf::RenderWindow* target,
        			Vector position   = Vector(10,10),
				 	Vector size       = Vector(400,400),
				 	size_t step       = 10);

        void setRanges      (Vector Xrange, Vector Yrange);
        Vector getXrange    ();

        sf::RenderWindow&   getWindow   ();
        void draw 		    () const;
        void drawPoints	    (sf::VertexArray arr);
};

#endif