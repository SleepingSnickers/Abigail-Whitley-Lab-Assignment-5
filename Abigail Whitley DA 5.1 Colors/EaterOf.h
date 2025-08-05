#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class EaterOf
{
private:
	T sum = T{};

public:
	EaterOf();
	EaterOf(T);

	void eat(T);
	T burp();

	class NotEdibleException {
	private:
		T food;
		T sum;

	public:
		NotEdibleException(T, T);
		void printMessage();
	};
};

