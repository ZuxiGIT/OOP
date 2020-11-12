#ifndef Color_hpp
#define Color_hpp


struct Color
{

	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char Alpha;

	Color(unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char alpha = 255);
};

#endif /* Color_hpp */ 