#include "sphere.hpp"
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    Sphere sph (Vector(400, 400, 0), Color(0,255,0), 200, Color(255,255,0,255), Vector(0, 0, 600), Color(255,255,255,25), Vector(800, 800));
    // run the program as long as the window is open
    Vector add;

    double angle = M_PI / 36;
    while (window.isOpen())
    {   
        //add = Vector (-sph.LightPosition.Z, 0, sph.LightPosition.X);
        //sph.LightPosition = sph.LightPosition + ( - sph.LightPosition * ( 1 - cos(angle)) + add * sin(angle));
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(sph);
        // end the current frame
        window.display();
    }

    return 0;
}