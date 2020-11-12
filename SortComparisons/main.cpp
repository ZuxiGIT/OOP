#include "Button.hpp"
#include "CoordSys.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    // run the program as long as the window is open
    
    Button but (Vector(150,40), Vector(10,10));
    CoordSys cs (Vector(200, 200), Vector(100, 100));


    while (window.isOpen())
    {   
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
        window.draw(but);
        window.draw(cs);
        // end the current frame
        window.display();
    }

    return 0;
}