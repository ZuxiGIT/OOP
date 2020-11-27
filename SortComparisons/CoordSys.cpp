#include "CoordSys.hpp"


Vector CoordSys::scalePoint (double x, double y)
{
    double X_ = size.X / (Xrange.Y - Xrange.X) * x
                + position.X + size.X / 2;
    

    double Y_ = size.Y / (Yrange.Y - Yrange.X) * y
                + position.Y + size.Y / 2;

    return Vector(X_, Y_);
}




CoordSys::CoordSys(sf::RenderWindow* target, Vector pos, Vector sz, size_t st)
: win(target)
{
	position   = pos;
	size       = sz;
    step       = st;
}

void CoordSys::setRanges(Vector Xrng, Vector Yrng)
{
    Xrange = Xrng;
    Yrange = Yrng;
}

Vector CoordSys::getXrange()
{
    return Xrange;
}


sf::RenderTarget& CoordSys::getWindow()
{
    return *win;
}


void CoordSys::draw(sf::RenderTarget& target) const
{
    //border
    sf::RectangleShape border(sf::Vector2f(size.X, size.Y));
    border.setPosition(position.X, position.Y);
    border.setOutlineThickness(2);
    border.setOutlineColor(sf::Color::White);
    target.draw(border);

    //grid
    Vector tmp (size.X, 0);
    for ( size_t i = 1; i <= step; i ++)
    {
        tmp.startfrom(position.X, position.Y + (step * size.Y - size.Y * i) / step);
        tmp.drawline(target, sf::Color::Blue);
    }
    
    tmp.X = 0;
    tmp.Y = size.Y;
    for ( size_t i = 1; i <= step; i ++)
    {
        tmp.startfrom(position.X  + (step * size.X - size.X * i) / step, position.Y);
        tmp.drawline(target, sf::Color::Blue);
    }

    //axes
    Vector Xaxe (size.X, 0);
    Xaxe.startfrom(position.X, position.Y + size.Y / 2);
    Xaxe.draw(target);

    Vector Yaxe (0, -size.Y);
    Yaxe.startfrom(position.X + size.X / 2, position.Y + size.Y);
    Yaxe.draw(target);
}

void CoordSys::drawPoints(sf::VertexArray arr)
{
    printf("%zu number of points\n",arr.getVertexCount() );
    for(size_t i = 0; i < arr.getVertexCount(); i++)
    {
        Vector scaledPoint = scalePoint(arr[i].position.x, arr[i].position.y);
        arr[i].position.x = scaledPoint.X; 
        arr[i].position.y = scaledPoint.Y;
    }

    win->draw(arr);
}