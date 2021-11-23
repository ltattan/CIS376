/*
* A child class of HourlyEmployeePay
* Employee->HourlyEmployee->HourlyEmployeePay->AgnecyCompanyPay
* 1- get the name of the company from the user.
* 2- print all information to the screen and a file.
*/

#pragma once
#pragma once
#ifndef AGENCYCOMPANYPAY_HPP
#define AGENCYCOMPANYPAY_HPP
#include "HourlyEmployeePay.h"
#include <iostream>
#include <string>
using namespace std;

class AgencyCompanyPay :public HourlyEmployeePay
{
protected:
	string companyToPay;
public://check if need constructor
	AgencyCompanyPay();
	void setCompanyToPay(string input);
	string getCompanyToPay();
	void printAgencyEmployeePay(ofstream& ofs);
};

#endif
