#pragma once

#include <iostream>
#include <vector>

using namespace std;

class PrimeFactors
{
private:

public:
	//function to find the lowest prime factor
	int findLowestPrimeFactor(int);

	//creates a vector of ints to store the prime factors
	vector<int> getPrimeFactors(int);
};

