#include <iostream>
using namespace std;

int main()
{
	cout << "Hi Cameron," << endl;
	cout << "I am glad you are my TA." << endl;
	cout << "My name is Mohandass Kannan. Nice to meet you!" << endl;

	cout << endl;
	
	cout << "   Let it snow!" << endl;
	cout << "   *   *   *  " << endl;
	cout << "  *    *    * " << endl;
	cout << " *     *     * " << endl;
	cout << "*      *      *" << endl;
	cout << "****************" << endl;

	cout << "    _    " << endl;
	cout << "   |_|   " << endl;
	cout << " (o   o)" << endl;
	cout << "(   :   )" << endl;
	cout << "(   :   )" << endl;
	cout << "(   :   )" << endl;
	cout << "   ___    " << endl;
	cout << endl;

	cout << "It is a snow day!" << endl;
	cout << "How many courses do you have today?" << endl;
	double courses = 0.0;
	cin >> courses;
	cout << "Enjoy your " << courses << " course(s)!" << endl;
	cout << endl;

	double hours = 0.0;
	cout << "How many hours are you going to spend on CS215 every week?" << endl;
	cin >> hours;
	const int HOUR_TOMIN = 60; //declare a constant: 1 hour = 60 minutes
	const int MIN_TO_SEC = 60; //declare a  constant: 1 minute = 60 seconds
	double seconds = hours * HOUR_TOMIN * MIN_TO_SEC;
	cout << "Good luck! You will spend " << seconds << " seconds each week on CS 215." << endl;

	return 0;
}