#define SFML_STATIC
#define SFML_DEFINE_DISCRETE_GPU_PREFERENCE
#include "Button.hpp"

int main()
{
    WindowHandler winhndl;
    printf("WINDOWS SUCKS!");


//-------------------1 window-----------------------
    winhndl.add(new Window (Vector(800, 800), "My window"));
    
    //Window window(Vector(800, 800), "My window");
    
    CoordSys cs (&winhndl[0], Vector(100, 100), Vector(500, 500));
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

    bthndl.add(new Button       (Vector(10,10)  , Vector(150,40) , &cs, Color::Cyan,   Color::Black, "Sin", sin));
    bthndl.add(new EllipseButton(Vector(600,100), 30, 40         , &cs, Color::Yellow, Color::Black, "Cos", cos));
    bthndl.add(new CircleButton (Vector(600,600), 30             , &cs, Color::Green,  Color::Black, "Tan", tan));       
    bthndl.add(new CrossedButton(Vector(700,700), Vector(100,100), &cs));
    
    cs.draw();

	winhndl[0].connectButtonManager(&bthndl);

//---------------2 window------------------------

	winhndl.add(new Window (Vector(800, 800), "My 2 window"));

	CoordSys cs2 (&winhndl[1], Vector(100, 100), Vector(500, 500));
    cs2.setRanges(Vector(-5, 5), Vector(-5, 5));
    cs2.draw();

    ButtonHandler bthndl2;

    bthndl2.add(new Button       (Vector(10,10)  , Vector(150,40) , &cs2, Color::Cyan,   Color::Black, "Sinh", sinh));
    bthndl2.add(new EllipseButton(Vector(600,100), 30, 40         , &cs2, Color::Yellow, Color::Black, "Cosh", cosh));
    bthndl2.add(new CircleButton (Vector(600,600), 30             , &cs2, Color::Green,  Color::Black, "Tanh", tanh));       
    bthndl2.add(new CrossedButton(Vector(700,700), Vector(100,100), &cs2));
    
    winhndl[1].connectButtonManager(&bthndl2);

    while (winhndl.isAlive())
    {   
    	//window.setTitle("fffff");
    	//window.display();
    	
    	sf::Event event;    
        while (winhndl.getEvent(event))
        {
        	
            if (event.type == sf::Event::Closed     || 
               (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape))
                winhndl.closeWindow(); 							//read more int can be recreated!!!!!!!!!!!!!! do not delete
            
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left)
                winhndl.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left)
                winhndl.clicked(Vector(event.mouseButton.x, event.mouseButton.y));
        }
        
        //window.clear(sf::Color::Black);

        //bthndl.draw(window);
        //window.setTitle("vvvvvvvvvvvvvvvvv");
        //window.display();
        winhndl.display();
    }

    return 0;
}