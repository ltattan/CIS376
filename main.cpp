/*
* Names:
    •Basmalah Algahmi
    •Thomas Metaxas
    •Khodr Salman
    •Ahsan Virk
* Description: The program will calculate and display employee payments for a company,
  as well as store various information having to do with employees into an output file.
*/
using namespace std;
#include <iostream>
#include <fstream> 
#include "Employee.h"
#include "SalaryEmployeePay.h"
#include "HourlyEmployeePay.h"
#include "AgencyCompanyPay.h"

float getUserChoice();
void validateData(Employee employee, string& fName, string& lName, string& ssn, string& id);
int main()
{
    int intInput;
    string stringInput, Lname, ssn, id, sentinel = "y";
    bool methodStatus = false;
    float userChoice;
    Employee employee;
    SalaryEmployeePay salaryEmployee;
    HourlyEmployee hourlyEmployee;
    HourlyEmployeePay hourlyEmployeePay;
    AgencyCompanyPay agencyEmployeePay;
   
    ofstream ofs("pay.dat");
    do
    {
        if (ofs.is_open())//check if open file
        {
            userChoice = getUserChoice();
            validateData(employee, stringInput, Lname, ssn, id);
          
            switch (int(userChoice))//swtich accept just int so change float to int
            {
            case 1://regular employee
                employee.setFirstName(stringInput);
                employee.setLasttName(Lname);
                employee.setSsn(ssn);
                employee.setId(id);
                employee.printEmployee(ofs);//print data to screen and file.
                break;
            case 2://salaryEmploye
                salaryEmployee.setFirstName(stringInput);
                salaryEmployee.setLasttName(Lname);
                salaryEmployee.setSsn(ssn);
                salaryEmployee.setId(id);

                //get annual pay and validate it
                cout << "Enter employee's annual pay: ";
                cin >> stringInput;
                salaryEmployee.setAnnualPay(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value greater than 0: ";
                    cin >> stringInput;
                    salaryEmployee.setAnnualPay(stringInput, &methodStatus);
                }
                //get the tax rate
                cout << "Enter tax rate(1-3): ";
                cin >> stringInput;
                salaryEmployee.setTaxRateCode(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter tax rate code 1-3: ";
                    cin >> stringInput;
                    salaryEmployee.setTaxRateCode(stringInput, &methodStatus);
                }
                //print to screen and file
                salaryEmployee.printSalaryEmployeePay(ofs);
                break;
                //end case salaryEmployee
            case 3://Hourly employee
                hourlyEmployee.setFirstName(stringInput);
                hourlyEmployee.setLasttName(Lname);
                hourlyEmployee.setSsn(ssn);
                hourlyEmployee.setId(id);
               
                cout << "Enter employee's number of hours worked: ";
                cin >> intInput;
                hourlyEmployee.setNumberOfHours(intInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 1-60: ";
                    cin >> intInput;
                    hourlyEmployee.setNumberOfHours(intInput, &methodStatus);
                }
                //get weekly pay and validate it
                cout << "Enter employee's weekly pay in 40 hours: ";
                cin >> stringInput;
                hourlyEmployee.setWeeklyPay(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 400-3000: ";
                    cin >> stringInput;
                    hourlyEmployee.setWeeklyPay(stringInput, &methodStatus);
                }
                //print to screen and file
                hourlyEmployee.printHourlyEmployee(ofs);
                break;
            case 4:
                hourlyEmployeePay.setFirstName(stringInput);
                hourlyEmployeePay.setLasttName(Lname);
                hourlyEmployeePay.setSsn(ssn);
                hourlyEmployeePay.setId(id);
             
                //get number of hours and validate it
                cout << "Enter employee's number of hours worked: ";
                cin >> intInput;
                hourlyEmployeePay.setNumberOfHours(intInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 1-60: ";
                    cin >> intInput;
                    hourlyEmployeePay.setNumberOfHours(intInput, &methodStatus);
                }
                //get weekly pay and validate it
                cout << "Enter employee's weekly pay(in 40 hours & before tax): ";
                cin >> stringInput;
                hourlyEmployeePay.setWeeklyPay(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 400-3000: ";
                    cin >> stringInput;
                    hourlyEmployeePay.setWeeklyPay(stringInput, &methodStatus);
                }
                //get the tax rate
                cout << "Enter tax rate: ";
                cin >> stringInput;
                hourlyEmployeePay.setTaxRateCode(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter tax rate code 1-3 ";
                    cin >> stringInput;
                    hourlyEmployeePay.setTaxRateCode(stringInput, &methodStatus);
                }
                //get the work status (Full-Part) and validate
                cout << "Enter work status(F (Full-time) / P (Part-time)): ";
                cin >> stringInput;
                hourlyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, work status must be 'F' for full time or 'P' for part time: ";
                    cin >> stringInput;
                    hourlyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                }
                hourlyEmployeePay.printHourlyEmployeePay(ofs);
                break;
            case 5:
                agencyEmployeePay.setFirstName(stringInput);
                agencyEmployeePay.setLasttName(Lname);
                agencyEmployeePay.setSsn(ssn);
                agencyEmployeePay.setId(id);
                
                //get number of hours and validate it
                cout << "Enter employee's number of hours worked: ";
                cin >> intInput;
                agencyEmployeePay.setNumberOfHours(intInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 1-60: ";
                    cin >> intInput;
                    agencyEmployeePay.setNumberOfHours(intInput, &methodStatus);
                }
                //get weekly pay and validate it
                cout << "Enter employee's weekly pay(40 hours & before tax): ";
                cin >> stringInput;
                agencyEmployeePay.setWeeklyPay(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 400-3000: ";
                    cin >> stringInput;
                    agencyEmployeePay.setWeeklyPay(stringInput, &methodStatus);
                }
                //get the tax rate
                cout << "Enter tax rate: ";
                cin >> stringInput;
                agencyEmployeePay.setTaxRateCode(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter tax rate code 1-3 ";
                    cin >> stringInput;
                    agencyEmployeePay.setTaxRateCode(stringInput, &methodStatus);
                }
               
                cout << "Enter work status(F (Full-time) / P (Part-time)): ";
                cin >> stringInput;
                agencyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, work status must be 'F' for full time or 'P' for part time: ";
                    cin >> stringInput;
                    agencyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                }
                cout << "Enter name of the company: ";
                cin >> stringInput;
                agencyEmployeePay.setCompanyToPay(stringInput);
                agencyEmployeePay.printAgencyEmployeePay(ofs);
                break;
            default:
                ofs << endl << endl;
                break;
            }//end switch 
            
        }//end if statement( if file is open)

        //if fail to open file
        else
        {
            cout << "Error, file could not be opened\n";
            goto endloop;
        }
    endloop:
        cout << "Would you like to continue? y/n: ";
        cin >> sentinel;
        while (sentinel != "Y" && sentinel != "y" && sentinel != "N" && sentinel != "n")
        {
            cout << "Would you like to continue? y/n: ";
            cin >> sentinel;
        }

    } while (sentinel == "Y" || sentinel == "y");//end do while loop

    cout << endl << "Thank you!" << endl;
    if (ofs.is_open())
        ofs.close();

    return 0;

}//end main method

float getUserChoice() {

    float userChoice = 0;
    string stringInput;
    while (true)
    {
        cout << "1- Employee \n"
            << "2- Salary employee pay \n"
            << "3- Hourly employee \n"
            << "4- Hourly employee pay \n"
            << "5- Agency employee pay \n"
            << "which type of employee would you like to create?\n";
        cin >> stringInput;
        try
        {
            userChoice = stof(stringInput);//change string to float, catch if was string or char
            if (userChoice > 0 && userChoice < 6 && userChoice == int(userChoice))//check if int and in range
                break;
            else
            {
                cout << "Error, invalid input. Enter a value 1-5" << endl;
                continue;
            }
        }
        catch (const exception& e)
        {
            cout << "Error, invalid input. Enter a value 1-5" << endl;
            continue;
        } //catch if char or string
    }//end while loop to validae user input of the menu 1-5
    return userChoice;
}

void validateData(Employee employee, string& fName, string& lName, string& ssn, string& id)
{
    bool methodStatus = false;
    cout << "Enter employee's first name: ";
    cin >> fName;

    cout << "Enter employee's last name: ";
    cin >> lName;

    cout << "Enter employee's ssn: ";
    cin >> ssn;
    employee.validateSsn(ssn, &methodStatus);
    while (!methodStatus)//while not valid input
    {
        cout << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx (x:number): ";
        cin >> ssn;
        employee.validateSsn(ssn, &methodStatus);
    }//end while loop to validate user input for ssn

    cout << "Enter employee's id: ";
    cin >> id;
    employee.validateId(id, &methodStatus);
    while (!methodStatus)
    {
        cout << "Enter id of format xxx-L (x:number, L:letter a-m): ";
        cin >> id;
        employee.validateId(id, &methodStatus);
    }//end while loop to validate user input for ssn
}




