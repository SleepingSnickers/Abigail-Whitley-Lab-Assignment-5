#pragma once
#include "Pixel.h"

#include <vector>
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class PicReader
{
public:
	//exception for if the X or Y coordinate is out of range
	class CoordinateOutOfRangeException {
	private:
		int coordValue;

	public:
		CoordinateOutOfRangeException(int);

		int getCoordValue() const;
	};

	//exception for if the numbers in color are < 0 or > 255
	class ColorVectorOutOfRangeException {
	private:
		int coordValue;
		
	public:
		ColorVectorOutOfRangeException(int);

		int getCoordValue() const;
	};

	static vector<Pixel> readPic(string);
};

