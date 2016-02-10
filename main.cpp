# Complex-Calculator
Sprint Software
#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

float add(float a, float b);
float sub(float a, float b);
float mult(float a, float b);
float div(float a, float b);

int main() {
	float a, b, result;
	char op;
	bool again, validOperator = false;
	
	do {
		validOperator = false;
		
		cout << "Insert A Number: ";
		cin >> a;
		
		cout << "Insert An Operator (+,-,*,/): ";
		cin >> op;
		
		cout << "Insert A Number: ";
		cin >> b;
		
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
			default:
			cout << "Please Enter A Valid Operator: ";
			cin >> op;
			}
		} while (!validOperator);
		
		cout << setprecision(4) << "Result = " << result << endl;
		
		cout << "Would You Like To Perform Another Calculation (Y/N)? ";
		char input;
		cin >> input;
		
		switch(input) {
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

float add(float variable1, float variable2) {
	return (variable1 + variable2);
}

float sub (float x, float y) {
	return (x - y);
}

float div(float value_one, float value_two) {
	return (value_one / value_two);
}

float mult(float x, float y) {
	return (x * y);
}
