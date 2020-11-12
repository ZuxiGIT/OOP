#include "CoordSys.hpp"

CoordSys::CoordSys(Vector sz, Vector pos)
{
	position   = pos;
	size       = sz;
}


void CoordSys::draw(sf::RenderTarget& target, sf::RenderStates states) const
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
    target.draw(Xaxe);

    Vector Yaxe (0, -size.Y);
    Yaxe.startfrom(position.X, position.Y + size.Y);
    target.draw(Yaxe);
  
}

