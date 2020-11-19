#include "Button.hpp"
#include "CoordSys.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    // run the program as long as the window is open
    

    Button buttons[] = {
        Button         (Vector(150,40), Vector(10,10)),
        EllipseButton  (Vector(600,100), 30, 40)
    };

    ButtonHandler bthndl(buttons, sizeof(buttons)/sizeof(buttons[0]));
    //CoordSys cs (Vector(100, 100), Vector(100, 100));


    while (window.isOpen())
    {   
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed     || 
                (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape))
                window.close();
            /*
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left)
                {
                    but.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
                    ellbut.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
                }
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left)
                {
                    but.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
                    ellbut.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
                }
                */
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(bthndl);
        //window.draw(cs);
        // end the current frame
        window.display();
    }

    return 0;
}