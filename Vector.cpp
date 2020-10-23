#include "Vector.hpp"

Vector::Vector(double x, double y, double z, double stX, double stY)
{
	X = x;
	Y = y;
	Z = z;
	startX = stX;
	startY = stY;	
}

Vector::Vector(const Vector& obj)
{
	X = obj.X;
	Y = obj.Y;
	Z = obj.Z;
	startX = obj.startX;
	startY = obj.startY;
}

Vector Vector::operator*(int num)
{
	return Vector(X*num, Y*num, Z*num, startX, startY);
}

Vector Vector::operator*(const Vector& obj)
{
	return Vector(X*obj.X, Y*obj.Y, Z*obj.Z);
}

Vector Vector::operator/(int num)
{
	return Vector(X/num, Y/num, Z/num, startX, startY);
}

double Vector::operator^(const Vector& obj)
{
	return X*obj.X + Y*obj.Y + Z*obj.Z;
}

Vector Vector::operator+(const Vector& obj)
{
	if (startX == obj.startX && startY == startY)
		return Vector(X + obj.X, Y + obj.Y, Z + obj.Z, startX, startY);
	else return *this;
}

Vector Vector::operator-(const Vector& obj)
{
	return Vector(X - obj.X, Y - obj.Y, Z - obj.Z, startX, startY);
}

Vector Vector::operator-()
{
	return Vector(-X, -Y, -Z, startX, startY);
}

bool Vector::operator==(const Vector& obj)
{
	return ((X == obj.X) && (X == obj.Y) && (Z == obj.Z));
}

void Vector::setSize(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}
void Vector::startfrom(const Vector& obj)
{
	startX = obj.startX + obj.X;
	startY = obj.startY + obj.Y;
}

void Vector::startfrom(double x, double y)
{
	startX = x;
	startY = y;
}

Vector Vector::normalize()
{
	double len = length();
	X /= len;
	Y /= len;
	Z /= len;
	return Vector(X, Y, Z);
}

double Vector::length()
{
	return sqrt(X*X + Y*Y + Z*Z);
}

Vector Vector::normalVector() const
{
	return Vector(-Y, X);
}

void Vector::drawline(const Vector& start, const Vector& finish, sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(start.X,  start.Y)),
		sf::Vertex(sf::Vector2f(finish.X, finish.Y))
	};
	target.draw(line, 2, sf::Lines);	
}

void Vector::drawline(sf::RenderTarget& target, sf::RenderStates states, sf::Color color) const
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(startX, startY), color),
		sf::Vertex(sf::Vector2f(startX + X, startY + Y), color)
	};
	target.draw(line, 2, sf::Lines);
}

void Vector::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Vector line = *this;
	line.normalize();
	line.startfrom(*this);
	line = line*(-20);
	
	Vector fst_arrow = this->normalVector();
	fst_arrow.normalize();
	fst_arrow.startfrom(*this);
	fst_arrow = fst_arrow * 5;
	
	Vector snd_arrow = -fst_arrow;
	fst_arrow = fst_arrow + line;
	snd_arrow = snd_arrow + line;
	
	snd_arrow.drawline(target, states, sf::Color::Red);
	fst_arrow.drawline(target, states, sf::Color::Red);
	drawline(target, states);
}