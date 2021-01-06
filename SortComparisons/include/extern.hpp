#ifndef Extern_hpp
#define Extern_hpp
#include "Vector.hpp"

class AbstractButton
{
	protected:
		Vector size, position;

	public:
		
		AbstractButton( Vector pos, Vector sz);
		virtual ~AbstractButton () = 0;				//undefined reference????????????

		
		virtual void clicked	(Vector mouse_pos) = 0;
		virtual void draw		(sf::RenderTarget& target) = 0;

};

class ActionButton : public AbstractButton
{
	public:
		virtual void action() = 0;
		ActionButton(Vector pos, Vector sz);
		~ActionButton();

};
class ButtonHandler
{
	static const int NUMBER_OF_BUTTONS = 30;
	ActionButton* buttons[NUMBER_OF_BUTTONS] = {};
	size_t count = 0;

	public:
		
		ButtonHandler	();
		~ButtonHandler	();
		
		void draw 		(sf::RenderTarget& target);
		void add 		(ActionButton* but);
		void clicked	(Vector mouse_pos);
};

#endif /* Extern_hpp */