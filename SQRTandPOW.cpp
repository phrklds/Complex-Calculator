// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h> 
using namespace std;

double add(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double div(double a, double b);
double sqr(double a);
double pwr(double a, double b);

int main() {
	double a, b, result;
	char op;
	bool again, validOperator = false;

	do {
		validOperator = false;

		cout << "Insert A Number: ";
		cin >> a;

		cout << "Insert An Operator (+,-,*,/,s,^): ";
		cin >> op;
		if (op == 's') {
			result = sqrt(a);
		}
		else {

			cout << "Insert A Number: ";
			cin >> b;

			do {
				switch (op) {
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

		switch (input) {
		case 'Y':
			again = true;
			break;
		case 'N':
			again = false;
			break;
		}

	} while (again);

	return 0;
}

double add(double variable1, double variable2) {
	return (variable1 + variable2);
}

double sub(double x, double y) {
	return (x - y);
}

double div(double value_one, double value_two) {
	return (value_one / value_two);
}

double mult(double x, double y) {
	return (x * y);
}
double sqr(double x) {
	return sqrt(x);
}
double pwr(double x, double y) {
	return pow(x,y);
}

