#include "EaterOf.h"
#include <type_traits>

//constructors
template <class T>
EaterOf<T>::EaterOf() {

}

template <class T>
EaterOf<T>::EaterOf(T sum) {
	this->sum = sum;
}

template <class T>
void EaterOf<T>::eat(T food) {
	try {
		bool isBad = false;

		//if the inputted value is <= 0, or >= to 100, the food is set as "bad" and is inedible
		if constexpr (is_same<T, int>::value || is_same<T, double>::value) {
			if (food <= 0 || food >= 100) {
				isBad = true;
			}
		}

		//if it is bad, it throws the exception
		if (isBad) {
			throw NotEdibleException(food, sum);
		}
		else {
			//prints nom-nom and adds food to sum
			cout << "nom-nom" << endl;
			sum += food;
		}
	}
	//just prints the not edible message
	catch (NotEdibleException& e) {
		e.printMessage();
	}
}

//returns the sum
template <class T>
T EaterOf<T>::burp() {
	return sum;
}

//setters
template <class T>
EaterOf<T>::NotEdibleException::NotEdibleException(T food, T sum) {
	this->food = food;
	this->sum = sum;
}

//prints an error message
template <class T>
void EaterOf<T>::NotEdibleException::printMessage() {
	cout << "Burp!\n" << sum << "\n" << "I can't eat " << food << endl;
}

//needed bc I split the EaterOf into an .h and .cpp
template class EaterOf<int>;
template class EaterOf<double>;
template class EaterOf<string>;