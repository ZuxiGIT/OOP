#ifndef Window_hpp
#define Window_hpp
#include "extern.hpp"
#include "Color.hpp"
#include <stack>

class Window : public sf::RenderWindow
{

	ButtonHandler* btn_manager = NULL;
	public:
		Window();
		Window(Vector2 size, const char* title, unsigned int bits_per_pixel = 32);
		~Window();

		void connectButtonManager(ButtonHandler* btnhndl);
		ButtonHandler& getBtnMngr();
};


class WindowHandler
{
	static const int NUMBER_OF_WINDOWS = 5;
	Window* windows[NUMBER_OF_WINDOWS] = {};
	size_t count = 0;

	void closeWindow	(bool all = false);
	
	public:
		WindowHandler();
		~WindowHandler();

		void 	add			(Window* obj);	
		void 	clicked		(const sf::Event& event);
		void 	display		();
		void	pressed		(const sf::Event& event);
		void 	clear		(Color col);

		Window& operator[] 	(size_t index);
		
		bool 	isAlive		();
		bool 	getEvent	(sf::Event&);

};



class DrawableSpace
{
	sf::Sprite background {};
	std::stack<const sf::Texture*> back_history{};
	sf::RenderTexture foreground {};

	void update() { back_history.push(background.getTexture()); background.setTexture(foreground.getTexture()); }
	void undo();
public:
	DrawableSpace();
	void draw(sf::RenderTarget& target);
};

#endif /* Window_hpp */