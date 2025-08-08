#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class EaterOf
{
private:
	//create a vector of T
	T sum = T{};

public:
	//constructors
	EaterOf();
	EaterOf(T);

	//function to display nom-nom and add the eaten food to the sum
	void eat(T);
	//returns the sum
	T burp();

	//exception for if something EaterOf tries to eat that isn't edible
	class NotEdibleException {
	private:
		T food;
		T sum;

	public:
		NotEdibleException(T, T);
		void printMessage();
	};
};

