/*
* A child class of HourlyEmployeePay
* Employee->HourlyEmployee->HourlyEmployeePay->AgnecyCompanyPay
* 1- get the name of the company from the user.
* 2- print all information to the screen and a file.
*/

#include "AgencyCompanyPay.h"
#include <fstream>
#include <iomanip>

AgencyCompanyPay::AgencyCompanyPay() { companyToPay = ""; }

void AgencyCompanyPay::setCompanyToPay(string input) { companyToPay = input; }

string AgencyCompanyPay::getCompanyToPay() { return companyToPay; }

void AgencyCompanyPay::printAgencyEmployeePay(ofstream& ofs)
{
	calcPayment();
	//print to screen
	cout << "Data for agency employee pay:" << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Hourlypay: " << hourlyPay << endl
		<< "Hours worked " << numberOfHours << endl
		<< "Overtime rate: $" << overtimePay << endl
		<< "Tax rate: " << taxRateCode << endl
		<< "Work status: " << workStatus << endl
		<< "Payment due: $" << paymentDue << endl
		<< "Company to pay: " << companyToPay << endl;

	//print to file
	ofs << fixed << setprecision(2);
	ofs << "Data for agency employee pay:" << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Hourlypay: " << hourlyPay << endl
		<< "Hours worked " << numberOfHours << endl
		<< "Overtime rate: $" << overtimePay << endl
		<< "Tax rate: " << taxRateCode << endl
		<< "Work status: " << workStatus << endl
		<< "Payment due: $" << paymentDue << endl
		<< "Company to pay: " << companyToPay << endl;//not complete
	ofs.flush();
}// end printAgencyEmployeePay