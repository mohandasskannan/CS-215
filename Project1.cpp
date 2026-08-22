/*
* 
* Project 1 - Super Bowl Roman Numeral
* 2 / 18 / 25
* Purpose: Program that repeatedly asks the user to input a year with a user-friendly interface
* It then displays the Super Bowl with the roman numeral assigned to it, until the user quits the program
* Author: Mohandass Kannan
* 
*/


// libraries
#include <iostream>
#include <iomanip>
#include <limits>    
#include <cmath>        
#include <string>

using namespace std;

// Call the necessary functions
string roman_digit(int digit, string one, string five, string ten);
string roman_numeral(int n);

int main()
{
 

    // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum) 
    const int START_SUPERBOWL = 1967;

    // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    
    // highest possible roman numeral
    const int END_SUPERBOWL = START_SUPERBOWL + (MAX_ROMAN - MIN_ROMAN);

    // user interface
    cout << "***********************************************************" << endl;
    cout << "*     The Super Bowl is the annual final playoff game     *" << endl;
    cout << "*         of the NFL to determine the league champion.    *" << endl;
    cout << "* The first Super Bowl took place on January 15, 1967.    *" << endl;
    cout << "* Super Bowl I (Los Angeles Memorial Coliseum) --> 1967   *" << endl;
    cout << "*                                                         *" << endl;
    cout << "* Super Bowl LIX was played on February 9, 2025           *" << endl;
    cout << "*                at Casesars Superdome in New Orleans.    *" << endl;
    cout << "*     Philadelphia Eagles 40 -- Kansas City Chiefs 22     *" << endl;
    cout << "*     The Super Bowl is the annual final playoff game     *" << endl;
    cout << "*                                                         *" << endl;
    cout << "* This Roman Numerals Convertor is written by Mohandass.  *" << endl;
    cout << "* If you had a time machine, which year of Super Bowl     *" << endl;
    cout << "* would you want to attend (1967 - 5965) ?                *" << endl;
    cout << "***********************************************************" << endl;

    // ask for year and store it as a variable
    int year;
    cout << "Please enter the year you want to attend (click Q or q to quit) : " << endl;
    cin >> year;


    while (true)
    {
        // some code for the program to know what year to convert to roman numerals
        const int new_year = year - 1966;

        if (cin.fail())  // the user input is not an integer
        {
            cin.clear();
            string usrOption;   // initialize to empty string
            cin >> usrOption;
            if (usrOption == "Q" || usrOption == "q")  // it satisfies the condition to quit the loop immediately
                break;
            else
                cout << "Please use a four-digit number to represent a year (" << START_SUPERBOWL << "-" << END_SUPERBOWL << ") !" << endl;
                cout << endl;
        }
        else  // the user input is an integer
        {
            if (year >= START_SUPERBOWL && year <= END_SUPERBOWL) // the user input is in the correct range
            {
                // Display what superbowl it is
                cout << "The time machine will bring you to the year of " << year << endl;
                cout << "It is Super Bowl " << roman_numeral(new_year) << "." << endl;
                cout << "We will help you find out the result and other interesting information..next time :) " << endl;
                cout << endl;
                cout << endl;
            }
            else if (year < START_SUPERBOWL)
            {
                // if the year is before 1967
                cout << "Wait!!! The year you enter is EARLIER than the first Super Bowl!" << endl;
                cout << endl;
            }
            else if (year > START_SUPERBOWL)
            {
                // if the year is too big of a number for roman numerals
                cout << "Hold on!!! The year you enter is TOO BIG for Roman Numerals!" << endl;
                cout << endl;
            }
            else  // the user input is NOT in the correct range
            {
                // if the input is not valid
                cout << "Please use a four-digit number to represent a year (" << START_SUPERBOWL << "-" << END_SUPERBOWL << ") !" << endl;
                cout << endl;
            }
        }

        cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream

        // keep going until program is terminated
        cout << "***********************************************************" << endl;
        cout << "*     The Super Bowl is the annual final playoff game     *" << endl;
        cout << "*         of the NFL to determine the league champion.    *" << endl;
        cout << "* The first Super Bowl took place on January 15, 1967.    *" << endl;
        cout << "* Super Bowl I (Los Angeles Memorial Coliseum) --> 1967   *" << endl;
        cout << "*                                                         *" << endl;
        cout << "* Super Bowl LIX was played on February 9, 2025           *" << endl;
        cout << "*                at Casesars Superdome in New Orleans.    *" << endl;
        cout << "*     Philadelphia Eagles 40 -- Kansas City Chiefs 22     *" << endl;
        cout << "*     The Super Bowl is the annual final playoff game     *" << endl;
        cout << "*                                                         *" << endl;
        cout << "* This Roman Numerals Convertor is written by Mohandass.  *" << endl;
        cout << "* If you had a time machine, which year of Super Bowl     *" << endl;
        cout << "* would you want to attend (1967 - 5965) ?                *" << endl;
        cout << "***********************************************************" << endl;

        cout << endl;
        
        cout << "Please enter the year you want to attend (click Q or q to quit) : " << endl;
        cin >> year;
    }

    // display this when program has been closed
    cout << "Back to 2025, and have a great day!" << endl;
    
    return 0;

}

string roman_digit(int digit, string one, string five, string ten)
{
    //using switch statement
    string roman;
    switch (digit)
    {
    case 1: roman = one;
        break;
    case 2: roman = one + one;
        break;
    case 3: roman = one + one + one;
        break;
    case 4: roman = one + five;
        break;
    case 5: roman = five;
        break;
    case 6: roman = five + one;
        break;
    case 7: roman = five + one + one;
        break;
    case 8: roman = five + one + one + one;
        break;
    case 9: roman = one + ten;
        break;
    default: break;
    }
    return roman;
}


// Function that converts a number into a roman numeral. It does this by creating an empty string first.
// It then adds to the string with the appropriate roman numeral for every digit.
string roman_numeral(int n)
{

    // empty string that you can add to later on
    string numeral = "";
    if (n >= 1000)
    {
        // Decide what to do for the 1000's place and take it out when done
        numeral += roman_digit(n / 1000, "M", "", "");
        n %= 1000;

    }
    if (n >= 100)
    {
        // Decide what to do for the 100's place and take it out when done
        numeral += roman_digit(n / 100, "C", "D", "M");
        n %= 100;
    }
    if (n >= 10)
    {
        // Decide what to do for the 10's place and take it out when done
        numeral += roman_digit(n / 10, "X", "L", "C");
        n %= 10;
    }
    if (n >= 1)
    {
        // Decide what to do for the 1's place and take it out when done
        numeral += roman_digit(n, "I", "V", "X");
    }
    return numeral;
}