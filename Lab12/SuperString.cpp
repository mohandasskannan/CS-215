/*Lab 12
 *4/24/25
 *Purpose: This program checks to see if a string input is a palindrome or not.
 * It does this by first finding the reverse of a string through a loop, recursion, and a stack.
 * It then uses loops and recursions to check if the reverse of the string is equal to the original string.
 *
 *Author: Mohandass Kannan
 */

#include <stack>
#include <iostream>
#include "SuperString.h"


// Default constructor
SuperString::SuperString(string ini_str)
{
	str = ini_str;
}

// Returns the string
string SuperString::getString() const
{
	return str;
}


// Sets string to an input
void SuperString::setString(string input_str)
{
	str = input_str;
}

// Uses a for loop to reverse the string and returns it
string SuperString::rev_loop() const
{
	string loop;
	for (int i = str.length() - 1; i >= 0; i--) {

		loop += str[i];
	}
	return loop;
}

// Uses recursion to get the middle of the string (not the start and end) and keep reversing that
string SuperString::rev_recursion() const
{
	string recursion;
	if (str.length() <= 1) {
		return str;
	}
	else {
		SuperString middle(str.substr(1, str.length() - 2)); // Make a class that extracts the middle of a string
		// Return a string that keeps extracting the middle using 
		// recursion and reverse the first and last characters
		return(str[(str.length() - 1)] + middle.rev_recursion() + str[0]); 
		
	}

}

// Make a stack, and use a loop to add the last element stack to the 
// string while removing the last element of the stack
string SuperString::rev_stack() const
{
	if (str.length() <= 1) {
		return str;
	}
	else {
		// Make a stack
		stack<char> s;
		// Make a string to add the elements of the stack
		string stack;
		for (int i = 0; i < str.length(); i++) {
			// Add values to the stack
			s.push(str[i]);
		}
		while (!s.empty()) {
			// Add those values to the string
			stack += s.top();
			s.pop();
		}

		return stack;

	}

}

// Compare the very left and very right elements, and then move the left element up one and the right element down one
bool SuperString::isPalindrome() const
{
	// This could work, but it's too easy
	//return str == rev_loop();
	
	if (str.length() <= 1) {
		return true;
	}

	// left and right characters of the string
	int left = 0;
	int right = str.length() - 1;

	// check if the left and right characters are equal, and if they are, keep going
	while (left < right) {
		if (str[left] != str[right])
		{
			// If they are not equal, it is not a palindrome
			return false;
		}
		left++;
		right--;

	}
}

// Uses recursion to check if a string is a palindrome or not
bool SuperString::isPalindrome_recursion() const
{
	// base case
	if (str.length() <= 1)
		return true;
	else // recursive case
	{
		string middle = str.substr(1, str.length() - 2); // Extract middle portion of string
		SuperString shorter(middle); // Make an object with that string
		bool firstPair = (str[0] == str[str.length() - 1]); // Check if the first and last characters are the same
		return (firstPair && shorter.isPalindrome_recursion()); // Use recursion to check the rest of the string
	}
}

// print function
void SuperString::print() const
{
	cout << str << endl;
}
