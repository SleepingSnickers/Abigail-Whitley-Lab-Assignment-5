#include "PicReader.h"
#include "Pixel.h"

#include "EaterOf.h"

#include "PrimeFactors.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    //Problem 1: Exceptions
    /*
    vector<Pixel> pixels = PicReader::readPic("colors.txt");

    for (Pixel& p : pixels) {
        cout << p;
    }
    */

    //Problem 2: Templates
   /*
    EaterOf<int> breakfastInt;
    breakfastInt.eat(6.5);

    EaterOf<int> secondBreakfastInt;
    breakfastInt.eat(0);

    EaterOf<double> lunchDouble;
    lunchDouble.eat(6.5);

    EaterOf<string> dinnerString;
    dinnerString.eat(string("6.5"));

    cout << "Int: " << breakfastInt.burp() << endl;
    cout << "Exception: " << secondBreakfastInt.burp() << endl;
    cout << "Double: " << lunchDouble.burp() << endl;
    cout << "String: " << dinnerString.burp() << endl;
    */

    //Problem 3: Recursion
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (number <= 1) {
        cout << "No prime factors for numbers <= 1." << endl;
        return 0;
    }

    PrimeFactors primes;

    vector<int> factors = primes.getPrimeFactors(number);
    cout << "Prime factors of " << number << ": ";
    for (int f : factors)
        cout << f << " ";
    cout << endl;

    return 0;
}