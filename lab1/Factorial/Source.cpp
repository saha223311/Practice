#include <iostream>

//Our functioun
unsigned int factorial(unsigned int number) {
	if (number == 0) return 1;
	return number * factorial(number - 1);
}

int main() {
	unsigned int number; 
	std::cin >> number; // Enter the number
	std::cout << factorial(number) << std::endl; // Get result of our function
}