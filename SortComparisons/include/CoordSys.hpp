#ifndef CoordSys_hpp
#define CoordSys_hpp
#include "Window.hpp"

class CoordSys
{
	Vector2 size, position;
	size_t step;

	sf::VertexArray field;

	Vector2 Xrange, Yrange;

	sf::RenderWindow* win;

	Vector2 scalePoint(double x, double y);

    public:
        
        CoordSys(	sf::RenderWindow* target,
        			Vector2 position   = Vector2(10,10),
				 	Vector2 size       = Vector2(400,400),
				 	size_t step       = 10);

        void setRanges      (Vector2 Xrange, Vector2 Yrange);
        Vector2 getXrange    ();

        sf::RenderWindow&   getWindow   ();
        void draw 		    () const;
        void drawPoints	    (sf::VertexArray arr);
		void clean() 		{ field = sf::VertexArray(sf::Points);}
};

#endif