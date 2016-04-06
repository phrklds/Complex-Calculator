// TestCalculator.cpp : main project file.

#include <string>
#include <iostream>
#include <locale>
#include <ctype.h>
#include <vector>
#include <deque>
#include <stdlib.h>

using namespace System;
using namespace std;
//using std::string;

bool lastCharDigit = true;
string RawString; //Contains the raw equation the user types in.

deque<string> TokenEquation(1); //Contains the equation in tokenised infix form.
deque<string> RPNEquation(0); //Contains the equation in tokenised RPN form.
deque<string> OperatorStack(0); //Used as part of the Shunting Yard Algorithm
deque<double> SolverStack(0); //Used to solve the RPN Equation.

locale loc; //Used to verify digits.

int main();
void tokeniser(string RawEquation);
void SYAlg();
void OSProcess(string newOperator);
void Solver();


int main() //Where the user inputs their equation, along with termination handling.
{
	cout << "Please enter a valid infix notation equation, without parenthesis.\n";
	cin >> RawString;
	tokeniser(RawString);
	cout << "\n";
	system("pause");
	return 0;
}

void tokeniser(string RawEquation)
{
	int testCharPos = -1; // Initialise the index of the raw string
	int tokenVectorPos = 0; // Initialise the token array position


	for (int eLength = RawEquation.length(); eLength != 0; eLength--) // For each character in the Raw string...
	{
		testCharPos++; // Increment the char we're testing
		char testChar = RawEquation.at(testCharPos); // Establish the current test char

		if (isdigit(testChar, loc)) //If the testchar is a digit
		{
			if (lastCharDigit) //If the last character was a digit
			{
				TokenEquation[tokenVectorPos] += testChar; //Append the tested char to the current token array pos
			}
			if (!lastCharDigit) //If the last character was not a digit
			{
				TokenEquation.push_back(string(1, testChar)); //Establish a new element with the testchar in it.
				tokenVectorPos++;
			}
			lastCharDigit = true;
		}
		if (!isdigit(testChar, loc))//If the testchar is not a digit
		{
			TokenEquation.push_back(string(1, testChar)); //Establish a new element with the testchar in it.
			tokenVectorPos++;
			lastCharDigit = false;
		}
	}
	/*Uncomment this section if you want to print the infix tokens.
	cout << "The tokens of that equation are:\n\n"; //Outputs the tokens for testing purposes.
	int tokenVectorPrintPos = 0; // Initialise the print position
	for (int tokenLength = TokenEquation.size(); tokenLength != 0; tokenLength--)
	{
	cout << "     " << TokenEquation[tokenVectorPrintPos];
	cout << "\n";
	tokenVectorPrintPos++;
	}
	*/

	SYAlg(); //Call the SYAlg.
}

void SYAlg() //This function uses Shunting Yard Algorithm to convert the Infix tokens to RPN.
{
	while (!TokenEquation.empty()) //For each token in the tokenised deque
	{
		if (!TokenEquation.empty() && isdigit(TokenEquation.front().at(0), loc)) //Check if it's a number
		{
			RPNEquation.push_back(TokenEquation.front()); //Add the first raw token to the RPN Equation
			TokenEquation.pop_front(); //Pop the token from the deque
		}
		if (!TokenEquation.empty() && !isdigit(TokenEquation.front().at(0), loc))	//If it's an operator
		{
			OSProcess(TokenEquation.front()); //Run the SYAlg operator stack procedure. NB This will pop the front of the TokenEquation for you.
		}
		if (TokenEquation.empty())
		{
			while (!OperatorStack.empty())
			{
				RPNEquation.push_back(OperatorStack.back());
				OperatorStack.pop_back();
			}
		}
	}

	/*Uncomment this to display the RPN tokens
	cout << "The tokens of that RPN equation are:\n\n"; //Outputs the tokens for testing purposes.
	int RPNPrintPos = 0;
	for (int tokenLength = RPNEquation.size(); tokenLength != 0; tokenLength--)
	{
	cout << "     " << RPNEquation[RPNPrintPos];
	cout << "\n";
	RPNPrintPos++;
	}
	*/
	Solver();
}

void OSProcess(string newOperator) //This function processes the Operator Stack
{
	bool PushedNewOperator = false;
	//std::string newOpSTD = newOperator; //Creates an std::string version of the argument for easier comparison.
	while (PushedNewOperator == false)
	{ //As long as the new operator is still waiting to go to the stack
		if (!OperatorStack.empty()) //If there's already an operator on the stack
		{
			if (newOperator.compare("/") == 0 || newOperator.compare("*") == 0)
			{
				//std::string OSBackSTD = OperatorStack.back(); //Create an STD version of the back of the OpStack for comparison.
				if (OperatorStack.back().compare("+") == 0 || OperatorStack.back().compare("-") == 0)
				{
					OperatorStack.push_back(newOperator); //Add the tested operator to the stack
					TokenEquation.pop_front(); //And pop it from the token equation
					PushedNewOperator = true; //Set the flag variable to true so we stop looping
				}
				else
				{
					RPNEquation.push_back(OperatorStack.back()); //Add the top of the operator stack to the equation
					OperatorStack.pop_back(); //Pop this back
				}
			}
			else
			{
				RPNEquation.push_back(OperatorStack.back()); //Add the top of the operator stack to the equation
				OperatorStack.pop_back(); //Pop this back
			}
		}
		if (OperatorStack.empty())
		{
			OperatorStack.push_back(newOperator); //Add the tested operator to the stack
			TokenEquation.pop_front(); //And pop it from the token equation
			PushedNewOperator = true; //Set the flag variable to true so we stop looping
		}
	}
	//For each operator on the stack, until the following statement returns false...
	//Check if the precedence of newOperator is less than or equal to the top operator.
}

void Solver() //This function solves the RPNEquation
{
	double answer;
	while (!RPNEquation.empty())//While there's still tokens in the RPN equation.
	{
		bool tokenProcessed = false; //Flag to ensure only one token gets processed per cycle of the parent while loop.
		if (isdigit(RPNEquation.front().at(0)) && tokenProcessed == false) //If the front token is a number.
		{
			SolverStack.push_back(atof(RPNEquation.front().c_str())); //Pushed the numeric string, converted to an int, on to the solver.
			RPNEquation.pop_front();
			tokenProcessed = true;
		}
		if (!RPNEquation.empty() && tokenProcessed == false) //If the front token is not a number...
		{
			double secondOperand = SolverStack.back(); //These four lines pop out the right numbers from the stack to be processed.
			SolverStack.pop_back();
			double firstOperand = SolverStack.back();
			SolverStack.pop_back();

			if (tokenProcessed == false && RPNEquation.front().compare("+") == 0)
			{
				answer = firstOperand + secondOperand; //Solve, push to stack, pop old token and flag processing.
				SolverStack.push_back(answer);
				RPNEquation.pop_front();
				tokenProcessed = true;
			}
			if (tokenProcessed == false && RPNEquation.front().compare("-") == 0)
			{
				answer = firstOperand - secondOperand; //Solve, push to stack, pop old token and flag processing.
				SolverStack.push_back(answer);
				RPNEquation.pop_front();
				tokenProcessed = true;
			}
			if (tokenProcessed == false && RPNEquation.front().compare("*") == 0)
			{
				answer = firstOperand * secondOperand; //Solve, push to stack, pop old token and flag processing.
				SolverStack.push_back(answer);
				RPNEquation.pop_front();
				tokenProcessed = true;
			}
			if (tokenProcessed == false && RPNEquation.front().compare("/") == 0)
			{
				answer = firstOperand / secondOperand; //Solve, push to stack, pop old token and flag processing.
				SolverStack.push_back(answer);
				RPNEquation.pop_front();
				tokenProcessed = true;
			}
		}
	}
	cout << "The solution to that equation is:\n\n"; //Outputs the tokens for testing purposes.
	cout << "	" << SolverStack.back();
}
