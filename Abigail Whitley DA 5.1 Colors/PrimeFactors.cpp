#include "PrimeFactors.h"

int PrimeFactors::findLowestPrimeFactor(int num) {
	//base case, any number below 4 will either not have a factor (1) or only has itself as a factor (not allowed)
    if (num <= 3) {
		return 0;
	}

    //goes thru each number that could be a factor (not 1) and if the value of num % i is 0 it is a factor of num
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) {
            bool isPrime = true;
            
            //if any number % i is 0, the number cannot be prime (all prime numbers are indivisible)
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    isPrime = false;

                    break;
                }
            }

            //if it is a prime number, return it
            if (isPrime) {
                return i;
            }
        }
    }

    return 0;
}

//this will print out all of the prime factors
vector<int> PrimeFactors::getPrimeFactors(int num) {
    //creates the int vector of factors
    vector<int> factors;

    //calls the findLowestPrimeFactor of the inputted number and stores that into an integer
    int lowest = findLowestPrimeFactor(num);

    //if there is no smallest prime found, the result gets pushed
    if (lowest == 0) {
        factors.push_back(num);
    }

    //basically just combines the results, there was prbly a better way to do this tho
    else {
        vector<int> left = getPrimeFactors(lowest);
        vector<int> right = getPrimeFactors(num / lowest);
        factors.insert(factors.end(), left.begin(), left.end());
        factors.insert(factors.end(), right.begin(), right.end());
    }

    return factors;
}