#ifndef Color_hpp
#define Color_hpp


struct Color
{


	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char Alpha;

	static const Color Black;       
	static const Color White;       
	static const Color Red;         
	static const Color Green;       
	static const Color Blue;        
	static const Color Yellow;      
	static const Color Magenta;     
	static const Color Cyan;        
	static const Color Transparent; 

	Color(unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char alpha = 255);
};

#endif /* Color_hpp */ 