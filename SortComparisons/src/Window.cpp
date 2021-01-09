#include "Window.hpp"
//#include <iostream>
//---------------------------------------------Window---------------------------------
Window::Window()
:sf::RenderWindow(sf::VideoMode(30, 30), "ERROR!")
{}

Window::Window(Vector2 size, const char* title, unsigned int bpp)
: sf::RenderWindow(sf::VideoMode(size.X, size.Y, bpp), title) {}

Window::~Window()
{}

void Window::connectButtonManager(ButtonHandler* btnhndl)
{
	if(!btnhndl)
	{
		printf("ERROR: wrong button manager pointer\n");
		fflush(NULL);
		return;
	}

	if(btn_manager)
	{
		printf("ERROR: window already has button manager\n");
		fflush(NULL);
		return;
	}

	btn_manager = btnhndl;		
}

ButtonHandler& Window::getBtnMngr()
{
	return *btn_manager;
}
//--------------------------------------------WindowHandler------------------------
WindowHandler::WindowHandler()
{}

WindowHandler::~WindowHandler()
{
	for (size_t i = 0; i < count; i ++)
		delete windows[i];
}

void WindowHandler::add(Window* win)
{
	if (count <= NUMBER_OF_WINDOWS - 1)
		windows[count++] = win;
	else
		{printf("ERROR: ButtonManager is full\n"); fflush(NULL);}

} 

void WindowHandler::clicked(const sf::Event& event)
{
	if ( (event.type == sf::Event::MouseButtonPressed) ||
		 (event.type == sf::Event::MouseButtonReleased))
		if(event.mouseButton.button == sf::Mouse::Left)
			for (size_t i = 0; i < count; i ++)
				if((*windows[i]).hasFocus())
				{ 
					(*windows[i]).getBtnMngr().clicked(Vector2(event.mouseButton.x, event.mouseButton.y));
					break;
				}
}

void WindowHandler::pressed (const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::LAlt)
        {
            closeWindow(true);
			return;
        }
		else if (event.key.code == sf::Keyboard::Escape)
		{
			//std::cout <<"escape\n";
			closeWindow();
			return;
		} 
    if (event.type == sf::Event::Closed)
        {
			//std::cout <<"closing...\n";
			closeWindow();
			return;
		}
		
	return;
}

void WindowHandler::clear(Color col)
{
	for (size_t i = 0; i < count; i ++)
		(*windows[i]).clear(col);

}
void WindowHandler::closeWindow(bool all)
{	
	if (all)
	{
		for (size_t i = 0; i < count; i ++)
		{
			printf("Closing window %zu\n", i);
			(*windows[i]).close();
			delete windows[i];
		}
		return;
	}
	
	for (size_t i = 0; i < count; i ++)
		if((*windows[i]).hasFocus())
		{ 
			printf("Closing window %zu\n", i);
			(*windows[i]).close();
			delete windows[i];
			
			
			for (size_t j = i; j < count - 1; j++)
				//std::cout << "moving "<<j<< "window\n";
				windows[j] = windows[j + 1];
			
			windows[count - 1] = NULL;
			count--;
			break;
		}

	return;
}

void WindowHandler::display()
{
	for (size_t i = 0; i < count; i ++)
	{
		(*(windows[i])).getBtnMngr().draw(*windows[i]);
		(*windows[i]).display();
	}

}

//????????????????????????????????????????????????????????????????????????????????????????????????????????

Window& WindowHandler::operator[] (size_t index)
{
	if (index < count)
		return *windows[index];
	else
		{printf("ERROR: out of range of WindowHandler\n"); fflush(NULL); return *windows[count - 1];} // return value?
}

bool WindowHandler::isAlive()
{
	bool res = false;
	for (size_t i = 0; i < count; i ++)
		res = res || (*windows[i]).isOpen();

	return res;
}

bool WindowHandler::getEvent(sf::Event& event)
{
	for (size_t i = 0; i < count; i ++)
		if((*windows[i]).hasFocus())
			return (*windows[i]).pollEvent(event);

	exit(1);
}