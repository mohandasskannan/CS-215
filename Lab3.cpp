// Mohandass Kannan
// 1/28/25
// CS 215 Lab 3
// Purpose: This program is designed to sort 3 integer numbers into either ascending or descending order. 
// It additionally specifies if the integers are sorted in lenient or strict order. For example,
// If there are 2 of the same numbers entered into the program, the order that they are sorted in will
// be lenient. If every number is unique, it will be sorted in strict order.


#include <iostream>
#include <iomanip>
using namespace std;


int main()
{

	// Normal display statements
	cout << "Your wish is my command!" << endl;
	cout << "I will sort three numbers under you wish." << endl;

	// Ask for what order
	string order = "";
	cout << "Enter A for ascending order, D for descending order (A or D)" << endl;
	cin >> order;


	// If an incorrect input is entered
	if ((order != "A" && order != "a") && (order != "D" && order != "d"))
	{
		cout << "Invalid choice, quitting the program..." << endl;
	}

	else
	{
		// Ask for integer input
		cout << "Please enter three integer numbers: " << endl;

		int num1; cin >> num1;
		int num2; cin >> num2;
		int num3; cin >> num3;

		// Account for every possible scenario in ascending order
		if ((order == "A" || order == "a") && (order != "D" || order != "d") && (num1 >= num2) && (num1 >= num3) && (num2 >= num3))
		{
			cout << "Numbers are in ascending order: " << endl;
			cout << num3 << " <= " << num2 << " <= " << num1 << endl;

		}
		else if ((order == "A" || order == "a") && (order != "D" || order != "d") && (num3 >= num1) && (num3 >= num2) && (num2 >= num1))
		{
			cout << "Numbers are in ascending order: " << endl;
			cout << num1 << " <= " << num2 << " <= " << num3 << endl;

		}
		else if ((order == "A" || order == "a") && (order != "D" || order != "d") && (num2 >= num1) && (num2 >= num3) && (num3 >= num1))
		{
			cout << "Numbers are in ascending order: " << endl;
			cout << num1 << " <= " << num3 << " <= " << num2 << endl;

		}
		else if ((order == "A" || order == "a") && (order != "D" || order != "d") && (num3 >= num2) && (num3 >= num2) && (num1 >= num2))
		{
			cout << "Numbers are in ascending order: " << endl;
			cout << num2 << " <= " << num1 << " <= " << num3 << endl;

		}
		else if ((order == "A" || order == "a") && (order != "D" || order != "d") && (num2 >= num3) && (num2 >= num1) && (num1 >= num3))
		{
			cout << "Numbers are in ascending order: " << endl;
			cout << num2 << " <= " << num3 << " <= " << num1 << endl;

		}
		else if ((order == "A" || order == "a") && (order != "D" || order != "d") && (num2 >= num1) && (num2 >= num3) && (num1 >= num3))
		{
			cout << "Numbers are in ascending order: " << endl;
			cout << num3 << " <= " << num1 << " <= " << num2 << endl;

		}
		// Account for every possible scenario in descending ordersd
		else if ((order != "A" || order != "a") && (order == "D" || order == "d") && (num1 >= num2) && (num1 >= num3) && (num2 >= num3))
		{
			cout << "Numbers are in descending order: " << endl;
			cout << num1 << " >= " << num2 << " >= " << num3 << endl;

		}
		else if ((order != "A" || order != "a") && (order == "D" || order == "d") && (num3 >= num1) && (num3 >= num2) && (num2 >= num1))
		{
			cout << "Numbers are in descending order: " << endl;
			cout << num3 << " >= " << num2 << " >= " << num1 << endl;

		}
		else if ((order != "A" || order != "a") && (order == "D" || order == "d") && (num2 >= num1) && (num2 >= num3) && (num3 >= num1))
		{
			cout << "Numbers are in descending order: " << endl;
			cout << num2 << " >= " << num3 << " >= " << num1 << endl;

		}
		else if ((order != "A" || order != "a") && (order == "D" || order == "d") && (num3 >= num2) && (num3 >= num2) && (num1 >= num2))
		{
			cout << "Numbers are in descending order: " << endl;
			cout << num3 << " >= " << num1 << " >= " << num2 << endl;

		}
		else if ((order != "A" || order != "a") && (order == "D" || order == "d") && (num2 >= num3) && (num2 >= num1) && (num1 >= num3))
		{
			cout << "Numbers are in descending order: " << endl;
			cout << num1 << " >= " << num3 << " >= " << num2 << endl;

		}
		else if ((order != "A" || order != "a") && (order == "D" || order == "d") && (num2 >= num1) && (num2 >= num3) && (num1 >= num3))
		{
			cout << "Numbers are in descending order: " << endl;
			cout << num2 << " >= " << num1 << " >= " << num3 << endl;

		}


		// Code to determine if it is in strictly or leniently ascending or descending order
		if ((order == "A" || order == "a") && (num1 != num2 && num2 != num3 && num1 != num3))
		{
			cout << "Numbers are in strictly ascending order!" << endl;
		}
		else if ((order == "D" || order == "d") && (num1 != num2 && num2 != num3 && num1 != num3))
		{
			cout << "Numbers are in strictly descending order!" << endl;
		}
		else if ((order == "D" || order == "d") && (num1 == num2 || num1 == num3 || num2 == num3))
		{
			cout << "Numbers are in leniently descending order!" << endl;
		}
		else if (order == "A" || order == "a" && (num1 == num2 || num1 == num3 || num2 == num3))
		{
			cout << "Numbers are in leniently ascending order!" << endl;
		}

	}
	}
	