#include "CoordSys.hpp"


Vector2 CoordSys::scalePoint (double x, double y)
{
    double X_ = size.X / (Xrange.Y - Xrange.X) * x
                + position.X + size.X / 2;
    

    double Y_ = size.Y / (Yrange.Y - Yrange.X) * y
                + position.Y + size.Y / 2;

    return Vector2(X_, Y_);
}




CoordSys::CoordSys(sf::RenderWindow* target, Vector2 pos, Vector2 sz, size_t st)
: position(pos), size(sz), Xrange(0), Yrange(0), win(target)
{
    position    = pos;
    size        = sz;
    step        = st;
}

void CoordSys::setRanges(Vector2 Xrng, Vector2 Yrng)
{
    Xrange = Xrng;
    Yrange = Yrng;
}

Vector2 CoordSys::getXrange()
{
    return Xrange;
}


sf::RenderWindow& CoordSys::getWindow()
{
    return *win;
}


void CoordSys::draw() const
{
    //border
    sf::RectangleShape border(sf::Vector2f(size.X, size.Y));
    border.setPosition(position.X, position.Y);
    border.setOutlineThickness(2);
    border.setOutlineColor(sf::Color::White);
    win->draw(border);

    //grid
    DrawableVector tmp (size.X, 0);
    for ( size_t i = 1; i <= step; i ++)
    {
        tmp.startfrom(position.X, position.Y + (step * size.Y - size.Y * i) / step);
        tmp.drawline(*win, sf::Color::Blue);
    }
    
    tmp.X = 0;
    tmp.Y = size.Y;
    for ( size_t i = 1; i <= step; i ++)
    {
        tmp.startfrom(position.X  + (step * size.X - size.X * i) / step, position.Y);
        tmp.drawline(*win, sf::Color::Blue);
    }

    //axes
    DrawableVector Xaxe (size.X, 0);
    Xaxe.startfrom(position.X, position.Y + size.Y / 2);
    Xaxe.draw(*win);

    DrawableVector Yaxe (0, -size.Y);
    Yaxe.startfrom(position.X + size.X / 2, position.Y + size.Y);
    Yaxe.draw(*win);
}

void CoordSys::drawPoints(sf::VertexArray arr)
{
    printf("%zu number of points\n",arr.getVertexCount() );
    for(size_t i = 0; i < arr.getVertexCount(); i++)
    {
        Vector2 scaledPoint = scalePoint(arr[i].position.x, arr[i].position.y);
        arr[i].position.x = scaledPoint.X; 
        arr[i].position.y = scaledPoint.Y;
    }

    win->draw(arr);
}