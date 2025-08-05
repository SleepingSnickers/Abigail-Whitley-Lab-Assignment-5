#include "EaterOf.h"
#include <type_traits>

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

		if constexpr (is_same<T, int>::value || is_same<T, double>::value) {
			if (food <= 0 || food >= 100) {
				isBad = true;
			}
		}

		if (isBad) {
			throw NotEdibleException(food, sum);
		}
		else {
			cout << "nom-nom" << endl;
			sum += food;
		}
	}
	catch (NotEdibleException& e) {
		e.printMessage();
	}
}

template <class T>
T EaterOf<T>::burp() {
	return sum;
}
template <class T>
EaterOf<T>::NotEdibleException::NotEdibleException(T food, T sum) {
	this->food = food;
	this->sum = sum;
}

template <class T>
void EaterOf<T>::NotEdibleException::printMessage() {
	cout << "Burp!\n" << sum << "\n" << "I can't eat " << food << endl;
}

template class EaterOf<int>;
template class EaterOf<double>;
template class EaterOf<string>;