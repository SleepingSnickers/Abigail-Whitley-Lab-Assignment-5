#include "Pixel.h"
#include <math.h>

//constructors
Pixel::Pixel() {
	X = 0;
	Y = 0;
	red = 0;
	green = 0;
	blue = 0;
	img = ' ';
}

Pixel::Pixel(int X, int Y, int red, int green, int blue, char img) {
	this->X = X;
	this->Y = Y;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->img = img;
}

//getters and setters
int Pixel::getX() const { 
	return X;
}

int Pixel::getY() const { 
	return Y; 
}

int Pixel::getRed() const { 
	return red; 
}

int Pixel::getGreen() const { 
	return green; 
}

int Pixel::getBlue() const { 
	return blue;
}

char Pixel::getImg() const { 
	return img;
}

void Pixel::setX(int X) {
	this->X = X;
}

void Pixel::setY(int Y) {
	this->Y = Y;
}

void Pixel::setRed(int red) { 
	this->red = red;
}

void Pixel::setGreen(int green) { 
	this->green = green;
}

void Pixel::setBlue(int blue) { 
	this->blue = blue;
}

void Pixel::setImg(char img) { 
	this->img = img;
}

//<< overload
ostream& operator<< (ostream& out, Pixel& pix) {
	//depending on the highest color value of the pixels, a different character will be shown
	if (pix.getRed() > pix.getBlue() && pix.getRed() > pix.getGreen()) {
		pix.setImg('R');
	}

	if (pix.getBlue() > pix.getRed() && pix.getBlue() > pix.getGreen()) {
		pix.setImg('B');
	}

	if (pix.getGreen() > pix.getRed() && pix.getGreen() > pix.getBlue()) {
		pix.setImg('V');
	}

	if (pix.getBlue() == pix.getRed() && pix.getRed() > pix.getGreen()) {
		pix.setImg('P');
	}

	if (pix.getGreen() == pix.getRed() && pix.getRed() > pix.getBlue()) {
		pix.setImg('Y');
	}

	if (pix.getBlue() == pix.getGreen() && pix.getRed() < pix.getGreen()) {
		pix.setImg('T');
	}


	if (pix.getBlue() == pix.getRed() && pix.getRed() == pix.getGreen() && pix.getRed() > 250) {
		pix.setImg('W');
	}

	if (pix.getBlue() == pix.getRed() && pix.getRed() == pix.getGreen() && pix.getRed() < 50) {
		pix.setImg('D');
	}

	if (pix.getBlue() == pix.getRed() && pix.getRed() == pix.getGreen() && pix.getRed() < 250 && pix.getRed() > 50) {
		pix.setImg('G');
	}

	out << pix.img;

	return out;
}