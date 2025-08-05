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
	class CoordinateOutOfRangeException {
	private:
		int coordValue;

	public:
		CoordinateOutOfRangeException(int);

		int getCoordValue() const;
	};

	class ColorVectorOutOfRangeException {
	private:
		int coordValue;
		
	public:
		ColorVectorOutOfRangeException(int);

		int getCoordValue() const;
	};

	static vector<Pixel> readPic(string);
};

