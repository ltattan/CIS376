/*
* A child class of Employee
* 1- It gets the weekly payment and the number of hours to calculate the hourly rate.
* 2- Number of hours 1-60 and the weekly payment $400-$3000
* 3- Prints the hourly employee's information to the screen and a file.
*/
#pragma once
#ifndef HOURLYEMPLOYEE_HPP
#define HOURLYEMPLOYEE_HPP
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;
class HourlyEmployee : public Employee
{
protected:
	float hourlyPay;
	int numberOfHours;
	float weeklyPay;
public:
	HourlyEmployee();
	void setWeeklyPay(string input, bool* methodStatus);
	float getHourlyPay();
	float getweeklyPay();
	void setNumberOfHours(int input, bool* methodStatus);
	int getNumberOfHours();
	void printHourlyEmployee(ofstream& ofs);
};

#endif
