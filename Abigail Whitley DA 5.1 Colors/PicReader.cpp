#include "PicReader.h"
#include "Pixel.h"
#include <fstream>

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

vector<Pixel> PicReader::readPic(string fileName) {
	vector<Pixel> pixels;

	ifstream file(fileName);

	int X, Y, red, green, blue;

	while (file >> X >> Y >> red >> green >> blue) {
		try {
			if (X < 0 || Y < 0) {
				throw CoordinateOutOfRangeException((X < 0) ? X : Y);
			}

			try {
				if (red < 0) throw ColorVectorOutOfRangeException(red);
				if (red > 255) throw ColorVectorOutOfRangeException(red);
			}
			catch (const ColorVectorOutOfRangeException& e) {
				cerr << "Red out of range: " << e.getCoordValue() << " => ";
				red = (e.getCoordValue() < 0) ? 0 : 255;
				cerr << red << endl;
			}

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

			pixels.emplace_back(X, Y, red, green, blue, '*');

		}
		catch (const CoordinateOutOfRangeException& e) {
			cerr << "Invalid coordinate: " << e.getCoordValue() << endl;
		}
	}

	return pixels;
}

