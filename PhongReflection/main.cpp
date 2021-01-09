#include "sphere.hpp"
//	#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    Sphere sph (Vector(400, 400, 0), Color(0,255,0), 200, Color(255,0,0,255), Vector(0, 0, 600), Color(255,255,255,25), Vector(800, 800));
    // run the program as long as the window is open
    

    double angle = M_PI / 36;
    
    Vector add = Vector (-sph.lights[0].position.Z, 0, sph.lights[0].position.X);
    
    Light SecondLight(Vector(300, 300, 400), Color(255, 0, 255, 255));
    Light ThirdLight (Vector(300, -300, 400), Color(0, 0, 255, 254));
    Light FourthLight(Vector(-300, 300, 400), Color(128, 255, 128, 255));
    sph.lights.push_back(SecondLight);
    //sph.lights.push_back(ThirdLight);
    //sph.lights.push_back(FourthLight);
    
    while (window.isOpen())
    {   
    	//tmp = tmp + add;
        //printf("Light position: %lf %lf %lf\n", sph.lights[0].position.X, sph.lights[0].position.Y, sph.lights[0].position.Z);
        sph.lights[0].position = Vector(-2*200, 2*200*cos(angle), 2*200*sin(angle));

        
        angle += 0.1;
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