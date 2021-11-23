/*
* A child class of HourlyEmployee, which a child of Employee
* Employee->HourlyEmployee->HourlyEmployeePay
* 1- It calculate the overpayment based on the hourly payment
* 2- get the tax rate from the user and calculate the due payment
* 3- get the work statu from the user (Full, Part)
* 4- print all information to the screen and a file.
*/
#include "HourlyEmployeePay.h"
#include <fstream>
#include <iomanip>

HourlyEmployeePay::HourlyEmployeePay() { overtimePay = 0; taxRateCode = 1;workStatus = "P"; }//captial P

float HourlyEmployeePay::getOvertimePay(){return overtimePay;}

void HourlyEmployeePay::setTaxRateCode(string input, bool* methodStatus)
{
	float userInput;
	try
	{
		userInput = stof(input);//change string to float, catch if was string or char
		if (userInput > 0 && userInput < 4 && userInput == int(userInput))//check if int and in range
		{
			*methodStatus = true;
			taxRateCode = userInput;
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
}
int HourlyEmployeePay::getTaxRateCode() { return taxRateCode; }

void HourlyEmployeePay::setWorkStatus(string input, bool* methodStatus)
{
	//validate work status
	if (input != "F" && input != "f" && input != "P" && input != "p")
		*methodStatus = false;
	else if (input == "F" || input == "f")
	{
		input = "F";
		*methodStatus = true;
		workStatus = input;
	}
	else if (input == "P" || input == "p")
	{
		input = "P";
		*methodStatus = true;
		workStatus = input;
	}
}
string HourlyEmployeePay::getWorkStatus() { return workStatus; }

void HourlyEmployeePay::calcPayment(){
	float taxRate;
	if (taxRateCode == 1)
		taxRate = .25;
	else if (taxRateCode == 2)
		taxRate = .2;
	else
		taxRate = .15;
	float fullTimeWeeklyPayment = weeklyPay - (weeklyPay * taxRate);
	//check hours
	overtimePay = hourlyPay * 1.5;
	if (numberOfHours > 40)
	{
		paymentDue = (overtimePay * (numberOfHours % 40) - (overtimePay * (numberOfHours % 40) * taxRate));//reminder
		paymentDue += fullTimeWeeklyPayment;
	}
	else if (numberOfHours <= 40)//see if just do else
		paymentDue = (numberOfHours * hourlyPay) - ((numberOfHours * hourlyPay) * taxRate);
	cout << fixed << setprecision(2);//print 2 digit after the decimal 
}
void HourlyEmployeePay::printHourlyEmployeePay(ofstream& ofs)
{
	calcPayment();
	//print to screen
	cout << "Data for hourly employee pay: " << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Hourlypay: " << hourlyPay << endl
		<< "Hours worked " << numberOfHours << endl
		<< "Overtime rate: $" << overtimePay << endl
		<< "Tax rate: " << taxRateCode << endl
		<< "Work status: " << workStatus << endl
		<< "Payment due: $" << paymentDue << endl;

	//print to file
	ofs << fixed << setprecision(2);
	ofs << "Data for hourly employee pay: " << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Hourlypay: " << hourlyPay << endl
		<< "Hours worked " << numberOfHours << endl
		<< "Overtime rate: $" << overtimePay << endl
		<< "Tax rate: " << taxRateCode << endl
		<< "Work status: " << workStatus << endl
		<< "Payment due: $" << paymentDue << endl;
	ofs.flush();
}//end printHourlyEmployeePay function 