#ifndef Vector_hpp
#define Vector_hpp
#include <math.h>
#include <SFML/Graphics.hpp>
#include "error.h"


struct Vector2
{
	double X, Y;
	Vector2(double num) 		{ X = num, Y = num;} 
	Vector2(double x, double y) { X = x, Y = y;}
	Vector2(const Vector2& obj) { X = obj.X, Y = obj.Y; }
	~Vector2() {}

	Vector2& operator+= 	(const Vector2& obj);

	void 	setSize			(double x, double y) { X = x; Y = y; }
	double 	length			();
};
Vector2 operator*	(const Vector2& obj, double num);
Vector2 operator*	(double num, const Vector2& obj);
//Vector2 operator*	(const Vector2& left, const Vector2& right);
Vector2 operator/	(const Vector2& obj, double num);
//Vector2 operator/	(const Vector2& left, const Vector2& right);
double 	operator^	(const Vector2& left, const Vector2& right);
Vector2 operator+	(const Vector2& left, const Vector2& right);
Vector2 operator-	(const Vector2& left, const Vector2& right);
Vector2 operator-	(const Vector2& obj);
bool 	operator==	(const Vector2& left, const Vector2& right);
bool 	operator!=	(const Vector2& left, const Vector2& right);

	

struct DrawableVector :  Vector2
{
	double startX, startY;

	DrawableVector(double num) 			: Vector2(num)  { startX = startY = 0;}
	DrawableVector(double x, double y) 	: Vector2(x, y) { startX = startY = 0;}
	DrawableVector(const DrawableVector& obj) 
		: Vector2(obj.X, obj.Y) { startX = obj.startX; startY = obj.startY; }
	DrawableVector(const Vector2& obj, double sX = 0, double sY = 0) 
		: Vector2(obj) {startX = sX; startY = sY;}

	DrawableVector	normalize	();
	
	DrawableVector	normalVector();
	
	void   	startfrom	(const Vector2&);
	void 	startfrom	(const DrawableVector&);
	void 	startfrom	(double, double);
	
	void   	drawline	(const Vector2&, const Vector2&, sf::RenderTarget& target);
	void 	drawline	(sf::RenderTarget& target, sf::Color Color = sf::Color::White);
	void   	draw 		(sf::RenderTarget& target);

	void 	check		(const DrawableVector& obj) const { if(!((startX == obj.startX) && (startY == obj.startY))) 
												   		error("DrawableVector::check(): differnt start points");  } 
};

DrawableVector  operator*	(const DrawableVector& obj, double num);
DrawableVector  operator*	(double num, const DrawableVector& obj);  
//DrawableVector  operator*	(const DrawableVector& left, const DrawableVector& right);
DrawableVector  operator/	(const DrawableVector& obj, double num);
DrawableVector 	operator-	(const DrawableVector& obj);
DrawableVector 	operator+	(const DrawableVector& left, const DrawableVector& right);
DrawableVector	operator-	(const DrawableVector& left, const DrawableVector& right);
bool 			operator==	(const DrawableVector& left, const DrawableVector& right);
bool 			operator!=	(const DrawableVector& left, const DrawableVector& right);
#endif /* Vector_hpp */