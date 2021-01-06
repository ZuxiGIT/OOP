#ifndef Vector_hpp
#define Vector_hpp
#include <math.h>
#include <SFML/Graphics.hpp>


class Vector
{
	public:
		double startX, startY;
		double X, Y, Z;
		Vector(double x = 0,
			   double y = 0,
			   double z = 0,
			   double startX = 0,
			   double startY = 0);
		Vector(const Vector&);

		Vector 	operator*	();
		Vector 	operator*  	(double num);
		Vector 	operator*	(const Vector&);
		Vector 	operator/  	(double num);
		double 	operator^  	(const Vector&);
		Vector 	operator+  	(const Vector&);
		//Vector 	operator+= 	(const Vector&);
		Vector 	operator-  	(const Vector&);
		Vector 	operator-  	();
		bool   	operator== 	(const Vector&);

		void 	setSize(double x, double y, double z = 0);
		void   	startfrom	(const Vector&);
		void 	startfrom	(double, double);
		Vector 	normalize	();
		double 	length		();
		Vector 	normalVector() const;
		void   	drawline	(const Vector&, const Vector&, sf::RenderTarget& target) const;

		void 	drawline	(sf::RenderTarget& target, sf::Color Color = sf::Color::White) const;

		void   	draw 		(sf::RenderTarget& target) const;
};

#endif /* Vector_hpp */