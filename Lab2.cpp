// Mohandass Kannan
// 1/21/25
// CS 215 Lab 2
// Purpose: To convert Canadian Dollars to United States Dollars and then display 
// how many dollars, quarters, dimes, nickels, and pennies the customer should have to pay.


#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	// prompting user to enter CAD amount
	cout << "Convert CAD to USD service." << endl;
	cout << "Please enter the amount of Canadian Dollars you want to exchange: C$ " << endl;

	// take in CAD for input
	double CAD;
	cin >> CAD;
	// conversion from CAD to USD
	double USD;
	USD = CAD * 0.69;

	// displaying the CAD equal to USD
	cout << "The exchange for C$" << fixed << setprecision(2) << CAD << " --> $ " << USD << " :" << endl;

	

	// multiplying USD by 100 for easier conversion
	int pennies = round(100 * USD);
	// taking away the dollars
	int dollars = int(pennies / 100);
	pennies %= 100;
	// taking away the quarters
	int quarters = int(pennies / 25);
	pennies %= 25;
	// taking away the dimes
	int dimes = int(pennies / 10);
	pennies %= 10;
	// taking away the nickels
	int nickels = int(pennies / 5);
	pennies %= 5;
	// the rest is just pennies
	pennies = int(pennies);
	
	// display the final product using width modification
	cout << "Dollars:" << setw(7) << dollars << endl;
	cout << "Quarters:" << setw(6) << quarters << endl;
	cout << "Dimes:" << setw(9) << dimes << endl;
	cout << "Nickels:" << setw(7) << nickels << endl;
	cout << "Pennies:" << setw(7) << pennies << endl;
	

}