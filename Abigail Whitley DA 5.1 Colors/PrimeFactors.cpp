#include "PrimeFactors.h"

int PrimeFactors::findLowestPrimeFactor(int num) {
	if (num <= 3) {
		return 0;
	}

    for (int i = 2; i < num; ++i) {
        if (num % i == 0) {
            bool isPrime = true;

            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    isPrime = false;

                    break;
                }
            }

            if (isPrime) {
                return i;
            }
        }
    }

    return 0;
}

vector<int> PrimeFactors::getPrimeFactors(int num) {
    vector<int> factors;

    int lowest = findLowestPrimeFactor(num);

    if (lowest == 0) {
        factors.push_back(num);
    }

    else {
        vector<int> left = getPrimeFactors(lowest);
        vector<int> right = getPrimeFactors(num / lowest);
        factors.insert(factors.end(), left.begin(), left.end());
        factors.insert(factors.end(), right.begin(), right.end());
    }

    return factors;
}