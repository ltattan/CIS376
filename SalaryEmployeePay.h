/* 
1-A child class of Employees, that get the annual income and the tax rate to
calculate the weekly payment
2-tax rate 1-3, and annual income should be greater than zero
3- It prints the salary employee information to the screen and a file.
*/
#pragma once
#ifndef SALARYEMPLOYEEPAY_HPP
#define SALARYEMPLOYEEPAY_HPP
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

class SalaryEmployeePay : public Employee
{
protected:
    float annualPay;
    float weeklyPay;
    int taxRateCode;
public:
    SalaryEmployeePay();

    float getAnnualPay();
    void setAnnualPay(string input, bool * methodStatus);//here will set the weekly too by annual/52 weeks
    int getTaxRateCode();
    void setTaxRateCode(string input, bool* methodStatus);

    void printSalaryEmployeePay(ofstream& ofs);
};

#endif
