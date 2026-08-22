/*
 *Lab 5
 *2/11/25
 *Purpose: First, it converts a sequence of numbers to its corresponding Roman Numerals
 *         Second, it repeatedly asks the user to input a triangle size until the user enters "Q" or "q" to quit the program
 *                 then displays a triangles using stars (asterisk symbol) and the total rows of stars is equal to the user input size, say n.
 *                 (The triangle contains one star at the first line, three little stars at the second line, and so on till 2*n-1 stars at the nth line, and it is symmetric.)
 *                 it displays the original triangle then roates the triangle 90-degree clockwise
 *
 *Author: Mohandass Kannan
 */

#include <iostream>
#include <iomanip>
#include <limits>       // define numeric_limits
#include <cmath>        // define pow function
#include <string>

using namespace std;



// The compiler needs to see at least function prototype before the function can be called

// It turns a digit into a Roman numeral
string roman_digit(int digit, string one, string five, string ten);

// It returns a string form of a Roman Numeral.
// (n must be between 1 and 3999)
string roman_numeral(int n);

// It prints a triangle of n rows of asterisk, center alignment
// starting with one asterisk at the first row, three at the second row...
void printTri(int n);

// It prints a triangle of asterisk
// It rotates the pattern from printTri function, 90-degree clockwise
void printTriR90(int n);

int main()
{
    const int START = 0;      // The minimum exponent
    const int END = 12;       // The maximum exponent
    const int BASE = 2;       // The base for the power function
    const int WIDTH = 10;     // formatted layout purpose: as WIDTH wide

    cout << "\tWelcome to CS215 Roman Numeral Converter!" << endl;
    cout << "\tDecimal\t\tRoman Numerals" << endl;

    // complete the following block of code
    // to display the sequence of numbers in the range: (BASE to the power of START, BASE to the power of END)
    // at each line: one number      -->     its Roman Numeral
    // your code starts here...

    
    cout << endl;

    // for 0 through 12
    for (int i = 0; i <= END; i++)
    {
        // number is 2 to the power of i
        int num = pow(BASE, i);
        // do this if it is less than 4096
        if (num < 4096)
        {
            cout << "      " << setw(4) << num << "      --> " << "\t" << setw(10) << roman_numeral(num) << endl;
        }
        else
        // do this if the number is 4096
        {
            cout << "      " << setw(4) << num << "      --> " << "\t" << "Error: NOT in the correct range!" << endl;
        }
        
    }
    
    cout << endl;




    const int MINSIZE = 1;
    const int MAXSIZE = 50;
    int triangle_size = 0;
    cout << "Enter the size of your triangle (an integer in [" << MINSIZE << ", " << MAXSIZE << "])" << endl;
    cout << "Type Q (or q) to quit the program: ";
    cin >> triangle_size;

    while (true)
    {
        if (cin.fail())  // the user input is not an integer
        {
            cin.clear();
            string usrOption;   // initialize to empty string
            cin >> usrOption;
            if (usrOption == "Q" || usrOption == "q")  // it satisfies the condition to quit the loop immediately
                break;
            else
                cout << "Invalid size! Expecting an integer in [" << MINSIZE << ", " << MAXSIZE << "]" << endl;
        }
        else  // the user input is an integer
        {
            if (triangle_size >= MINSIZE && triangle_size <= MAXSIZE) // the user input is in the correct range
            {
                cout << "The triangle with size " << triangle_size << " (ROMAN NUMBER: " << roman_numeral(triangle_size) << " ) is:" << endl;
                printTri(triangle_size);
                cout << "The rotation for 90 degrees clockwise: " << endl;
                printTriR90(triangle_size);
            }
            else  // the user input is NOT in the correct range
            {
                cout << "The size is not in the correct range! Expecting the size in [" << MINSIZE << ", " << MAXSIZE << "]" << endl;
            }
        }

        cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream

        cout << "Enter the size of your triangle (an integer in [" << MINSIZE << ", " << MAXSIZE << "])" << endl;
        cout << "Type Q (or q) to quit the program: ";
        cin >> triangle_size;
    }

    cout << "Thank you, have a great day!" << endl;
    return 0;
}

/*
   Turns a digit into a Roman numeral.
   @param digit the digit to convert into Roman
   @param one string representing the Roman numeral for ones
   @param five string representing the Roman numeral for fives
   @param ten string representing the Roman numeral for tens
   @return string representing the Roman number for digit
*/
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


// Upright triangle function
void printTri(int n)
{
    // for 1 through n
    for (int i = 1; i <= n; i++)
    {
        // spaces decrease everytime
        for (int k = n - i; k > 0; k--)
        {
            cout << " ";
        }
        // stars increase everytime
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
            
        }
        cout << endl;

    }
}


void printTriR90(int n)
{
    // for 1 through n
    for (int i = 1; i <= n; i++)
    {
        // print an increasing amount of stars until you get to i
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // start to decrease i until it reaches 1 again
    for (int i = n - 1; i >= 1; i--)
    {
        // Until then, print a decreasing amount of stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
