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
    //create a vector of Pixels and store the variables inside colors.txt in it
    vector<Pixel> pixels = PicReader::readPic("colors.txt");

    //print all of the pixels
    for (Pixel& p : pixels) {
        cout << p;
    }

    //Problem 2: Templates
    //create an EaterOf with the int type, store a double to test behavior that is also the same variable as the int and string
    EaterOf<int> breakfastInt;
    breakfastInt.eat(6.5);

    //create an EaterOf with the int type, store 0 to test the exception handling
    EaterOf<int> secondBreakfastInt;
    breakfastInt.eat(0);

    //create an EaterOf with the double type, store the same variable as the int and string
    EaterOf<double> lunchDouble;
    lunchDouble.eat(6.5);

    //create an EaterOf with the string type, store the same variable as the int and string
    EaterOf<string> dinnerString;
    dinnerString.eat(string("6.5"));

    //cout all of it using the burp() function
    cout << "Int: " << breakfastInt.burp() << endl;
    cout << "Exception: " << secondBreakfastInt.burp() << endl;
    cout << "Double: " << lunchDouble.burp() << endl;
    cout << "String: " << dinnerString.burp() << endl;

    //Problem 3: Recursion
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    //automatically removes the primeless number
    if (number <= 1) {
        cout << "No prime factors for numbers <= 1." << endl;
        return 0;
    }

    PrimeFactors primes;

    //create a vector of ints to cout all of the prime factors of that number
    vector<int> factors = primes.getPrimeFactors(number);
    cout << "Prime factors of " << number << ": ";
    for (int f : factors)
        cout << f << " ";
    cout << endl;

    return 0;
}