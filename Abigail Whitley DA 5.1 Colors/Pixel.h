#pragma once

#include <iostream>

using namespace std;

class Pixel
{
private:
	int X, Y, red, green, blue;
	char img;

public:
	//constructors
	Pixel();
	Pixel(int, int, int, int, int, char);

	//getters
	int getX() const;
	int getY() const;
	int getRed() const;
	int getGreen() const;
	int getBlue() const;
	char getImg() const;

	//setters
	void setX(int);
	void setY(int);
	void setRed(int);
	void setGreen(int);
	void setBlue(int);
	void setImg(char);

	//<< overload
	friend ostream& operator<< (ostream&, Pixel&);
};

