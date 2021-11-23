/*Employee.h
* this class is designed to create an employee. it is the header of the class where it contains the class members 
* and the prototypes - function headers- that will define in the C++ of this class
*/
#pragma once
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string firstName;
    string lastName;
    string ssn;
    string hideSsn;
    string id;
    
public:
    Employee();

    string getFirstName();
    void setFirstName(string input);

    string getLastName();
    void setLasttName(string input);

    string getId();
    void setId(string input);
    void validateId(string input, bool* methodStatus);

    string getSsn();
    void setSsn(string input);
    void validateSsn(string input, bool* methodStatus);

    void printEmployee(ofstream& ofs);//should pass by reference

};//end of class Employee

#endif