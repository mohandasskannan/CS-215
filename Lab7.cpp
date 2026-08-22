// Mohandass Kannan
// 2/27/25
// CS 215 Lab 7
// Purpose: Takes user input to make an array. The highest and lowest scores are dropped, and the Execution Score 
// is the average of the remaining four judges’ scores. The program displays the original scores as well as 
// the scores after the highest and lowest scores are dropped. It then calculates and dispalys the Execution Score.


// libraries
#include <iostream>
#include <iomanip>
#include <limits>    
#include <cmath>        
#include <string>

using namespace std;

// Call the size variable outside the function
const int MAX_SIZE = 6;

// call the functions before the main function
void dropTwo(double scores[], int& size);
double final_score(double scores[], int size);


int main()
{
	// define array
	double scores[MAX_SIZE] ;
	int size = MAX_SIZE;

	// incrementing value
	int i = 0;

	// until we reach the maximum size of the array
	while (i < MAX_SIZE)
	{
		// Ask for input
		double input;
		cout << "Please enter your score for the gymnast: " << endl;
		cin >> input;

		// If input is not a number
		if (cin.fail())
		{
			cin.clear();
			
			cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;

			
		}
		// If input is a number but not in the correct range
		else if (input < 0 || input > 10)
		{
			cout << "Score is NOT in the correct range!" << endl;

		}
		// If the input is valid
		else
		{	
			scores[i] = input;
			i++;
		}
		
		cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream


	}

	// Display the original scores
	cout << "The scores from the judges are: " << endl;
	for (i = 0; i < MAX_SIZE; i++)
	{
		cout << fixed << setprecision(2) << scores[i] << "\t";
	}
	cout << endl;

	// Modify the array by dropping the lowest and highest scores and then display
	dropTwo(scores, size);

	cout << "The scores after dropping the highest and lowest scores: " << endl;
	for (i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2) << scores[i] << "\t";
	}
	cout << endl;

	// Display the final score by calling the function
	double final_execution = final_score(scores, size);
	cout << "Final Execution Score is: " << fixed << setprecision(2) << final_execution << endl;


	return 0;
	
}


// this is a function that removes the lowest score and highest score 
// from the array passed in as the first parameter

void dropTwo(double scores[], int& size)
{

	double min = scores[0];
	double max = scores[0];

	// minimum and maximum indexes
	int minIndex = 0;
	int maxIndex = 0;

	// Check minimum and maximum index for every i
	for (int i = 1; i < size; i++) {
		
		// min
		if (scores[i] < min) {
			min = scores[i];
			minIndex = i;
		}
		// max
		if (scores[i] > max) {
			max = scores[i];
			maxIndex = i;
		}

	}

	// define a new size value for the new array
	int newSize = 0;
	double temp[MAX_SIZE];

	// set new size equal to 4
	for (int i = 0; i < size; i++)
	{
		if (i != minIndex && i != maxIndex)
		{
			temp[newSize++] = scores[i];
		}
	}

	// only show the index values for the values in the middle
	for (int i = 0; i < newSize; i++)
	{
		scores[i] = temp[i];
	}

	// changing size value to new size value
	size = newSize;

}

// This function calculates the final Execution score for a gymnast after 
// dropping both the lowest and highest scores
double final_score(double scores[], int size)
{
	// set sum = 0
	double sum = 0;
	// for every number in scores array, add it to sum
	for (int i = 0; i < size; i++) {
		sum += scores[i];
	}
	// calculate the average
	return sum / size;

}
