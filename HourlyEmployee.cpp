/*
* This class .cpp define the functions in the header file;
1- it assigns all local variables  to zero
2- has setters and getters functions
3- Checks if input is valid
4- It gets the weekly payment and the number of hours to calculate the hourly rate.
5- Number of hours 1-60 and the weekly payment $400-$3000, hourly pay $10- $75(the range for weekly pay will take care of this)
6- Prints the hourly employee's information to the screen and a file.
*/

#include "HourlyEmployee.h"
#include <fstream> 
#include <iomanip>

HourlyEmployee::HourlyEmployee()
{
	hourlyPay = 0;
	numberOfHours = 0;
	weeklyPay = 0;
}

void HourlyEmployee::setWeeklyPay(string input, bool* methodStatus)
{
	float userInput;
	try
	{
		userInput = stof(input);//change string to float, catch if was string or char
		if (userInput >=400  && userInput <=3000)//check if int and in range
		{
			*methodStatus = true;
			weeklyPay = userInput;
			hourlyPay = weeklyPay / 40;
		}
		else
		{
			*methodStatus = false;
		}
	}
	catch (const exception& e)
	{
		cout << "Enter a number\n";
		*methodStatus = false;

	} //catch if char or string
	
	
}//end method set weekly pay

float HourlyEmployee::getHourlyPay() { return hourlyPay; }

float HourlyEmployee::getweeklyPay() { return weeklyPay; }

void HourlyEmployee::setNumberOfHours(int input, bool* methodStatus)
{
	//validate user input of the work hours
	if (input < 1 || input >60)
		*methodStatus = false;
	else
	{
		*methodStatus = true;
		numberOfHours = input;
	}
}//end method set number of hours

int HourlyEmployee::getNumberOfHours() { return numberOfHours; }

void HourlyEmployee::printHourlyEmployee(ofstream& ofs)
{
	cout << fixed << setprecision(2);//print 2 digit after the decimal 
	cout << "Data for hourly employee: " << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Hourly pay:: " << hourlyPay << endl
		<< "Hours worked:  " << numberOfHours << endl;

	//print to file
	ofs << fixed << setprecision(2);
	ofs << "Data for hourly employee: " << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Hourlypay:: " << hourlyPay << endl
		<< "Hours worked:  " << numberOfHours << endl;
	ofs.flush();

}