#include <iostream>
#include <iomanip>
#include <math.h>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

double add(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double div(double a, double b);
double pwr(double a, double b);
double checkNumber(string input);

int main() {
	double a, b, result;
	string inputA, inputB;
	char op;
	bool again, validAgain, validOperator;
	
	do {
		validOperator = false;
		validAgain = false;
		
		cout << "Insert A Number: ";
		cin >> inputA;
		a = checkNumber(inputA);
		
		cout << "Insert An Operator (+,-,*,/,s,^): ";
		cin >> op;
		
		if (op == 's') {
			result = sqrt(a);
		} else {
			cout << "Insert A Number: ";
			cin >> inputB;
			b = checkNumber(inputB);
			
			do {
				switch(op) {
				case '+':
				result = add(a, b);
				validOperator = true;
				break;
				case '-':
				result = sub(a, b);
				validOperator = true;
				break;
				case '*':
				result = mult(a, b);
				validOperator = true;
				break;
				case '/':
				result = div(a, b);
				validOperator = true;
				break;
				case '^':
				result = pwr(a, b);
				validOperator = true;
				break;
				default:
				cout << "Please Enter A Valid Operator: ";
				cin >> op;
				}
			} while (!validOperator);
		}
		
		cout << setprecision(4) << "Result = " << result << endl;
		
		cout << "Would You Like To Perform Another Calculation (Y/N)? ";
		char input;
		cin >> input;
		
		do {
			switch(input) {
			case ('Y' | 'y'):
			again = true;
			validAgain = true;
			break;
			case ('N' | 'n'):
			again = false;
			validAgain = true;
			break;
			default:
			cout << "Please Enter A Valid Response: ";
			cin >> input;
			}
		} while (!validAgain);
		
	} while (again);
	
	return 0;
}

double add(double variable1, double variable2) {
	return (variable1 + variable2);
}

double sub (double x, double y) {
	return (x - y);
}

double div(double value_one, double value_two) {
	return (value_one / value_two);
}

double mult(double x, double y) {
	return (x * y);
}

double pwr(double x, double y) {
	return pow(x, y);
}

double checkNumber(string input) {
	regex integer("\\d+(\\.\\d+)?");
	
	bool isValid;
	double output;
	
	do {
		isValid = regex_match(input, integer);
		
		if (isValid) {
			output = stod(input);
			cout << "Input " << output << " Is Valid" << endl;
		} else {
			cout << "Please Insert A Valid Number: ";
			cin >> input;
		}
	} while (!isValid);
	
	return output;
}
