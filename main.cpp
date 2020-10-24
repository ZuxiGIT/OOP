#include "sphere.hpp"
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    Sphere sph(Vector(400, 400, 0), Color(255,0,0), Color(), Color(255,255,255,25), 200, Vector(0, 0, -400), Vector(800, 800));
    // run the program as long as the window is open
    Vector add;
    while (window.isOpen())
    {   
        add = Vector (-sph.LightPosition.Z, 0, sph.LightPosition.X);
        sph.LightPosition = sph.LightPosition + add.normalize()*25;
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