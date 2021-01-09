#ifndef Extern_hpp
#define Extern_hpp
#include "Vector.hpp"

class AbstractButton
{
	protected:
		Vector2 size, position;

	public:
		
		AbstractButton( Vector2 pos, Vector2 sz) : size(sz), position(pos) {}
		virtual ~AbstractButton () {}

		
		virtual void clicked	(Vector2 mouse_pos) = 0;
		virtual void draw		(sf::RenderTarget& target) = 0;

};

class ActionButton : public AbstractButton
{
	public:
		ActionButton(Vector2 pos, Vector2 sz) : AbstractButton(pos, sz) {}
		~ActionButton() {}
		
		virtual void action() {}
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
		void clicked	(Vector2 mouse_pos);
};

#endif /* Extern_hpp */