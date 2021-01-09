#include "Vector.hpp"
#include <iostream>
//-------------------Vector2-------------------

inline Vector2 	operator*(const Vector2& obj, double num)
{
	return Vector2( obj.X * num, obj.Y * num);
}
inline Vector2 	operator*(double num, const Vector2& obj)
{
	return obj * num;
}
/*
inline Vector2 	operator*(const Vector2& left, const Vector2& right)
{
	return Vector2(left.X * right.X, left.Y * right.Y);
}
*/
inline Vector2 	operator/(const Vector2& obj, double num)
{
	return Vector2( obj.X / num, obj.Y / num);
}
/*
inline Vector2 operator/(const Vector2& left, const Vector2& right)
{
	return Vector2(left.X / right.X, left.Y / right.Y);
}
*/
inline double 	operator^	(const Vector2& left, const Vector2& right)
{
	return left.X * right.X + left.Y * right.Y;
}
inline Vector2 	operator+(const Vector2& left, const Vector2& right)
{
	std::cout <<" ++ \n";
	return Vector2(left.X + right.X, left.Y + right.Y);
}
Vector2& Vector2::operator+=(const Vector2& obj)
{
	*this = *this + obj;
	return *this;
}
inline Vector2 	operator-(const Vector2& left, const Vector2& right)
{
	return Vector2(left.X - right.X, left.Y - right.Y);
}
inline Vector2 	operator-(const Vector2& obj)
{
	return Vector2(-obj.X, -obj.Y);
}
inline bool 	operator==(const Vector2& left, const Vector2& right)
{
	return ((left.X == right.X) && (left.Y == right.Y));
}
inline bool 	operator!=(const Vector2& left, const Vector2& right)
{
	return !( left == right);
}
double Vector2::length()
{
	return sqrt(X * X + Y * Y);
}



//-------------------DrawableVector-------------------
void DrawableVector::startfrom(const Vector2& obj)
{
	startX = obj.X;
	startY = obj.Y;
}
void DrawableVector::startfrom(const DrawableVector& obj)
{
	startX = obj.startX + obj.X;
	startY = obj.startY + obj.Y;
}
void DrawableVector::startfrom(double x, double y)
{
	startX = x;
	startY = y;
}
DrawableVector DrawableVector::normalize()
{
	double len = length();
	//std::cout << "normalizing len = " << len << "\n";
	if (len != 0)
		return DrawableVector(Vector2((*this) / len), startX, startY);	
	return *this; 
	
}
DrawableVector DrawableVector::normalVector()
{
	return DrawableVector(Vector2(-Y, X), startX, startY);
}
void DrawableVector::drawline(const Vector2& start, const Vector2& finish, sf::RenderTarget& target)
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(start.X,  start.Y)),
		sf::Vertex(sf::Vector2f(finish.X, finish.Y))
	};
	target.draw(line, 2, sf::Lines);	
}
void DrawableVector::drawline(sf::RenderTarget& target, sf::Color color) 
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(startX, 	startY), 		color),
		sf::Vertex(sf::Vector2f(startX + X, startY + Y),	color)
	};
	target.draw(line, 2, sf::Lines);
}
void DrawableVector::draw(sf::RenderTarget& target)
{
	DrawableVector line	= *this;
	line				= line.normalize();
	line.startfrom(*this); 
	line				= line * (-20);

	DrawableVector fst_arrow 	= this->normalVector();
	//std::cout <<"\n"<< "------before-------------fst_narrow: coordinate:"<< fst_arrow.X<< " "<<fst_arrow.Y<<" start: "<< fst_arrow.startX<< " "<<fst_arrow.startY;
	fst_arrow 					= fst_arrow.normalize();
	fst_arrow.startfrom(*this);
	fst_arrow 					= fst_arrow * 5;
	
	//std::cout <<"\n"<< "------after-------------fst_narrow: coordinate:"<< fst_arrow.X<< " "<<fst_arrow.Y<<" start: "<< fst_arrow.startX<< " "<<fst_arrow.startY;

	DrawableVector snd_arrow 	= -fst_arrow;
	fst_arrow 					= fst_arrow + line;
	snd_arrow 					= snd_arrow + line;
	
	//std::cout <<"\n"<< "snd_narrow: coordinates:"<< snd_arrow.X<< " "<<snd_arrow.Y<<" start: "<< snd_arrow.startX<< " "<<snd_arrow.startY;

	snd_arrow.drawline	(target, sf::Color::Red);
	fst_arrow.drawline	(target, sf::Color::Red);
	drawline			(target, sf::Color::Black);
}
inline DrawableVector operator*	(const DrawableVector& obj, double num)
{
	return DrawableVector(Vector2(obj) * num, obj.startX, obj.startY);
}
inline DrawableVector operator* (double num, const DrawableVector& obj)
{
	return obj * num;
}
/*
inline DrawableVector operator* (const DrawableVector& left, const DrawableVector& right)
{
	left.check(right);
	return DrawableVector(Vector2(left) * Vector2(right), left.startX, left.startY);
}
*/
inline DrawableVector operator/(const DrawableVector& obj, double num)
{
	return DrawableVector(Vector2(obj) / num, obj.startX, obj.startY);
}
inline DrawableVector operator-	(const DrawableVector& obj)
{
	return DrawableVector(-Vector2(obj), obj.startX, obj.startY);
}
inline DrawableVector operator+	(const DrawableVector& left, const DrawableVector& right)
{
	left.check(right);
	return DrawableVector(Vector2(left) + Vector2(right), left.startX, left.startY);
}
inline DrawableVector operator- (const DrawableVector& left, const DrawableVector& right)
{
	left.check(right);
	return DrawableVector(Vector2(left) - Vector2(right), left.startX, left.startY);
}
inline bool operator==(const DrawableVector& left, const DrawableVector& right)
{
	left.check(right);
	return Vector2(left) == Vector2(right);
}
inline bool operator!=(const DrawableVector& left, const DrawableVector& right)
{
	return !(left == right);
}