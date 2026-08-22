// Mohandass Kannan
// 2/5/25
// CS 215 Lab 4
// Purpose: This program asks the user for an 8-digit number and checks if the card is valid or not. 
// It uses simple algorithms to determine if the card is valid, and if it isn't, then it will display what the last digit should have been.


#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    // Keep running code while hi is true
    bool hi = true;
    while (hi)
    {
        // Enter the card number
        int credit_card_number;
        cout << "Please enter the 8-digit credit card number (enter -1 to quit): " << endl;
        cin >> credit_card_number;

        // Terminate program if -1 is entered
        if (credit_card_number == -1)
        {
            cout << "Thank you for using \"Credit Card Number Validation\"!" << endl;
            hi = false;
        }
        // Otherwise, continue with the rest of the program
        else
        {
            // Gather every digit of the credit number and store it into a variable
            int temp = credit_card_number;
            int last_digit = temp % 10;
            temp /= 10;
            int seventh_digit = temp % 10;
            temp /= 10;
            int sixth_digit = temp % 10;
            temp /= 10;
            int fifth_digit = temp % 10;
            temp /= 10;
            int fourth_digit = temp % 10;
            temp /= 10;
            int third_digit = temp % 10;
            temp /= 10;
            int second_digit = temp % 10;
            temp /= 10;
            int first_digit = temp % 10;

            // First part of the algorithm involves adding these digits
            int step1 = last_digit + sixth_digit + fourth_digit + second_digit;

            // Variables to find every digit in the second part of the algorithm
            int num1;
            int num2;
            int num3;
            int num4;
            int num5;
            int num6;
            int num7;
            int num8;

            // If the digit multiplied by 2 is a double digit number, store the two digits into two variables. 
            // Otherwise, store the first digit and make the other one zero.
            int digi1 = first_digit * 2;
            if (digi1 > 9)
            {
                temp = digi1;
                num1 = temp % 10;
                temp /= 10;
                num2 = temp % 10;
            }
            else
            {
                temp = digi1;
                num1 = temp % 10;
                num2 = 0;
            }


            int digi3 = third_digit * 2;
            if (digi3 > 9)
            {
                temp = digi3;
                num3 = temp % 10;
                temp /= 10;
                num4 = temp % 10;
            }
            else
            {
                temp = digi3;
                num3 = temp % 10;
                num4 = 0;
            }


            int digi5 = fifth_digit * 2;
            if (digi5 > 9)
            {
                temp = digi5;
                num5 = temp % 10;
                temp /= 10;
                num6 = temp % 10;
            }
            else
            {
                temp = digi5;
                num5 = temp % 10;
                num6 = 0;
            }


            int digi7 = seventh_digit * 2;
            if (digi7 > 9)
            {
                temp = digi7;
                num7 = temp % 10;
                temp /= 10;
                num8 = temp % 10;
            }
            else
            {
                temp = digi7;
                num7 = temp % 10;
                num8 = 0;
            }

            // Add all the individual digits for the second part of the algorithm
            int step2 = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8;
            // Add step1 and step2
            int step3 = step1 + step2;

            // If step3 ends with a 0, then the card number is valid
            if ((step3 % 10) == 0)
            {
                cout << "Number is valid." << endl;
               
            }
            // If it doesn't, then it is invalid. 
            // Find out how much needs to be added to the last digit to make step3 end with a 0
            // Then add that to the last_digit to find the desired check_digit
            else
            {
                int need = (10 - step3 % 10);
                int check_digit = need + last_digit;
                if (check_digit > 9)
                {
                    check_digit -= 10;
                    
                }
                

                cout << "Number is invalid." << endl;
                cout << "Check digit should have been " << check_digit << endl;
               
            }
        }
    }
    

    return 0;
}