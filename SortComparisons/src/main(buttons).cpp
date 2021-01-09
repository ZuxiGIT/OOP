#define SFML_STATIC
#define SFML_DEFINE_DISCRETE_GPU_PREFERENCE

#include "Button.hpp"
#include <iostream>





int main()
{
    WindowHandler winhndl;

//-------------------1 window-----------------------
    winhndl.add(new Window (Vector2(800, 800), "My window"));
        
    CoordSys cs (&winhndl[0], Vector2(100, 100), Vector2(500, 500));
    cs.setRanges(Vector2(-5, 5), Vector2(-5, 5));

    ButtonHandler bthndl;

    bthndl.add(new Button       (Vector2(10,10)  , Vector2(150,40), &cs, Color::Cyan,   Color::Black, "Sin", sin));
    bthndl.add(new EllipseButton(Vector2(600,100), 30, 40         , &cs, Color::Yellow, Color::Black, "Cos", cos));
    bthndl.add(new CircleButton (Vector2(600,600), 30             , &cs, Color::Green,  Color::Black, "Tan", tan));       
    bthndl.add(new CrossedButton(Vector2(700,700), Vector2(100,100), &cs));
    
    

	winhndl[0].connectButtonManager(&bthndl);

//---------------2 window------------------------

	winhndl.add(new Window (Vector2(800, 800), "My 2 window"));

	CoordSys cs2 (&winhndl[1], Vector2(100, 100), Vector2(500, 500));
    cs2.setRanges(Vector2(-5, 5), Vector2(-5, 5));

    ButtonHandler bthndl2;

    bthndl2.add(new Button       (Vector2(10,10)  , Vector2(150,40), &cs2, Color::Cyan,   Color::Black, "Sinh", sinh));
    bthndl2.add(new EllipseButton(Vector2(600,100), 30, 40         , &cs2, Color::Yellow, Color::Black, "Cosh", cosh));
    bthndl2.add(new CircleButton (Vector2(600,600), 30             , &cs2, Color::Green,  Color::Black, "Tanh", tanh));       
    bthndl2.add(new CrossedButton(Vector2(700,700), Vector2(100,100),&cs2));
    
    winhndl[1].connectButtonManager(&bthndl2);

    while (winhndl.isAlive())
    {    	
    	sf::Event event;    
        while (winhndl.getEvent(event))
        {
            winhndl.pressed(event); 			//closed window can be recreated!!!!!!!!!!!!!! do not delete
            winhndl.clicked(event);
        }
        
        winhndl.clear(Color::Black);
        cs.draw();
        cs2.draw();
        winhndl.display();
    }

    return 0;
}