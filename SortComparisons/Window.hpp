#ifndef Window_hpp
#define Window_hpp
#include "extern.hpp"

class Window : public sf::RenderWindow
{

	ButtonHandler* btn_manager = NULL;
	public:
		Window();
		Window(Vector size, const char* title, unsigned int bits_per_pixel = 32);
		~Window();

		void connectButtonManager(ButtonHandler* btnhndl);
		ButtonHandler& getBtnMngr();
};


class WindowHandler
{
	static const int NUMBER_OF_WINDOWS = 5;
	Window* windows[NUMBER_OF_WINDOWS] = {};
	size_t count = 0;

	public:
		WindowHandler();
		~WindowHandler();

		void 	add			(Window* obj);	
		void 	clicked		(Vector mouse_pos);
		void 	closeWindow	();
		void 	display		();
		
		Window& operator[] 	(size_t index);
		
		bool 	isAlive		();
		bool 	getEvent	(sf::Event&);
};

#endif /* Window_hpp */