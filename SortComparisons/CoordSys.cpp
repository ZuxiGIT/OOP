#include "CoordSys.hpp"

CoordSys::CoordSys(Vector sz, Vector pos, size_t st)
{
	position   = pos;
	size       = sz;
    step = st;
}


void CoordSys::draw(sf::RenderTarget& target) const
{
    //border
    sf::RectangleShape border(sf::Vector2f(size.X, size.Y));
    border.setPosition(position.X, position.Y);
    border.setOutlineThickness(2);
    border.setOutlineColor(sf::Color::White);
    target.draw(border);

    //axes
    Vector Xaxe (size.X, 0);
    Xaxe.startfrom(position.X, position.Y + size.Y);
    Xaxe.draw(target);

    Vector Yaxe (0, -size.Y);
    Yaxe.startfrom(position.X, position.Y + size.Y);
    Yaxe.draw(target);

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
}