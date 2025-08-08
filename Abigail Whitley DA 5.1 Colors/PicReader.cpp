#include "PicReader.h"
#include "Pixel.h"
#include <fstream>

//essentially these are just getters and setters for the exceptions
PicReader::CoordinateOutOfRangeException::CoordinateOutOfRangeException(int coordValue) {
	this->coordValue = coordValue;
}

int PicReader::CoordinateOutOfRangeException::getCoordValue() const {
	return coordValue;
}

PicReader::ColorVectorOutOfRangeException::ColorVectorOutOfRangeException(int coordValue) {
	this->coordValue = coordValue;
}

int PicReader::ColorVectorOutOfRangeException::getCoordValue() const {
	return coordValue;
}

//reads the file
vector<Pixel> PicReader::readPic(string fileName) {
	//create a Pixel vector
	vector<Pixel> pixels;

	//inputs a file into the variable file
	ifstream file(fileName);

	//variables for each of the colors/coordinates
	int X, Y, red, green, blue;

	//while loop to go thru each line of the inputted file
	while (file >> X >> Y >> red >> green >> blue) {
		try {
			//tests if X and Y are below 0, and throws the exception if they are
			if (X < 0 || Y < 0) {
				throw CoordinateOutOfRangeException((X < 0) ? X : Y);
			}

			try {
				//throws an error if red is < 0 or > 255
				if (red < 0) throw ColorVectorOutOfRangeException(red);
				if (red > 255) throw ColorVectorOutOfRangeException(red);
			}
			catch (const ColorVectorOutOfRangeException& e) {
				//shows the error and changes the values to either 0 if < 0 or 255 if > 255
				cerr << "Red out of range: " << e.getCoordValue() << " => ";
				red = (e.getCoordValue() < 0) ? 0 : 255;
				cerr << red << endl;
			}

			//exact same thing as red for green and blue
			try {
				if (green < 0) throw ColorVectorOutOfRangeException(green);
				if (green > 255) throw ColorVectorOutOfRangeException(green);
			}
			catch (const ColorVectorOutOfRangeException& e) {
				cerr << "Green out of range: " << e.getCoordValue() << " => ";
				green = (e.getCoordValue() < 0) ? 0 : 255;
				cerr << green << endl;
			}

			try {
				if (blue < 0) throw ColorVectorOutOfRangeException(blue);
				if (blue > 255) throw ColorVectorOutOfRangeException(blue);
			}
			catch (const ColorVectorOutOfRangeException& e) {
				cerr << "Blue out of range: " << e.getCoordValue() << " => ";
				blue = (e.getCoordValue() < 0) ? 0 : 255;
				cerr << blue << endl;
			}

			//originally use * for pixels but thats been changed
			pixels.emplace_back(X, Y, red, green, blue, '*');

		}
		//exception if the inputted coordinates are invalid
		catch (const CoordinateOutOfRangeException& e) {
			cerr << "Invalid coordinate: " << e.getCoordValue() << endl;
		}
	}

	return pixels;
}

