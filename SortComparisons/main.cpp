#include "Button.hpp"
#include "CoordSys.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    
    CoordSys cs (&window, Vector(100, 100), Vector(500, 500));
    cs.setRanges(Vector(-5, 5), Vector(-5, 5));


    // Button         but      (Vector(10,10)  , Vector(150,40), &cs, Color::Cyan,   Color::Black, "Sin", sin);
    // EllipseButton  ellbut   (Vector(600,100), 30, 40        , &cs, Color::Yellow, Color::Black, "Cos", cos);
    // CircleButton   crclbut  (Vector(600,600), 30            , &cs, Color::Green,  Color::Black, "Tan", tan);       
    // CrossedButton  crsbut   (Vector(700,700), Vector(100,100),&cs);

    ButtonHandler bthndl;

    // bthndl.add(&but);
    // bthndl.add(&ellbut);
    // bthndl.add(&crclbut);
    // bthndl.add(&crsbut);

    bthndl.add(new Button       (Vector(10,10)  , Vector(150,40), &cs, Color::Cyan,   Color::Black, "Sin", sin));
    bthndl.add(new EllipseButton(Vector(600,100), 30, 40        , &cs, Color::Yellow, Color::Black, "Cos", cos));
    bthndl.add(new CircleButton (Vector(600,600), 30            , &cs, Color::Green,  Color::Black, "Tan", tan));       
    bthndl.add(new CrossedButton(Vector(700,700), Vector(100,100),&cs));
    
    cs.draw(window);
    
    while (window.isOpen())
    {   

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed     || 
               (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape))
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left)
                bthndl.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left)
                bthndl.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
        }

        //window.clear(sf::Color::Black);

        bthndl.draw(window);
        window.display();
    }

    return 0;
}