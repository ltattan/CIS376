/*
* This class .cpp define the functions in the header file;
1- it assigns all data types to ""
2- has setters and getters functions
3- Checks if the input is valid
4- prints to screen and file that pass by reference
Data Format: 
 •	Social Security Number, in the format xxx-xx-xxxx, where x is a digit within the range 
  0 through 9
 •	Employee number, in the format xxx-L, where x is a digit within the range 0 through 9, 
  and the L is a letter within the range A through M. 
*/

#include "Employee.h"
#include <fstream> 

Employee::Employee()
{
    firstName = ""; lastName = ""; ssn = ""; id = "";hideSsn = ""; 
}

string Employee::getFirstName() { return firstName; }
void Employee::setFirstName(string input) { firstName = input; }

string Employee::getLastName() { return lastName; }
void Employee::setLasttName(string input) { lastName = input; }

string Employee::getId() { return id; }
void Employee::setId(string input){ id = input; }
void Employee::validateId(string input,bool *methodStatus)
{
    * methodStatus = false;
    if (input.length() == 5)//Id is 5 char- dont check unless the length is 5
    {
        for (int i = 0; i <= 4;i++)
        {
            if (i == 3)//  i=3 will be infinit loop; 
            {
                if (input[i] != '-') //check if it is "-"
                    goto endloop;
            }
            else if (i == 4)//check if a-m and then change it to capital letter
            {
                switch (input[i])
                {
                case 'A':case'a':
                    input[i] = 'A';
                    break;
                case 'B':case'b':
                    input[i] = 'B';
                    break;
                case 'C':case'c':
                    input[i] = 'C';
                    break;
                case 'D':case'd':
                    input[i] = 'D';
                    break;
                case 'E':case'e':
                    input[i] = 'E';
                    break;
                case 'F':case'f':
                    input[i] = 'F';
                    break;
                case 'G':case'g':
                    input[i] = 'G';
                    break;
                case 'H':case'h':
                    input[i] = 'H';
                    break;
                case 'I':case'i':
                    input[i] = 'I';
                    break;
                case 'J':case'j':
                    input[i] = 'J';
                    break;
                case 'K':case'k':
                    input[i] = 'K';
                    break;
                case 'L':case'l':
                    input[i] = 'L';
                    break;
                case 'M':case'm':
                    input[i] = 'M';
                    break;
                default:
                    goto endloop;
                }//end switch statement

            }//end else if (i==4)
            else if(i<=2)//check if numbers
            {
                if (!isdigit(input[i] ))
                    goto endloop;   
            }   
        }//end for loop

        *methodStatus = true; //assign to true if reach this point. 
        
    endloop:
        //mistake if dont put anything
        if (*methodStatus == true)  //* go to that bool and check if true
            return;
    }//end outer if statement
   
}//end of setId function

string Employee::getSsn() { return hideSsn; }
//here no loop until it is right, it checks the one entered and if wrong, it keep the bool false

void Employee::setSsn(string input){
    ssn = input;
    hideSsn = input;
    for (int i = 0; i <= 5;i++)//not out, just if true
    {
        if (i != 3)
            hideSsn[i] = 'x';
    }
}

void Employee::validateSsn(string input, bool* methodStatus)
{
    *methodStatus = false;
    
    for (int i = 0; i <= 10;i++)
    {
        if (i == 3 || i==6)// check the hyphen sign
        {
            if (input[i] != '-')
                goto endloop;
        }
        else 
        {
            if (!isdigit(input[i]))
                goto endloop;
            if (i == 10)
                *methodStatus = true;
        }
    }//end of for loop

    endloop:
    if (*methodStatus == true)  //go to that bool and check if true
    {
        return;
    }//end of endloop

}//end method set ssn

void Employee::printEmployee(ofstream& ofs)
{
    //print to screen and file.
    // Print SS# in this format e.g. xxx-xx-1234
    cout << " Data for regular Employee: " << endl;
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Ssn: " << hideSsn << endl;
    cout << "Id: " << id << endl;
    ofs << " Data for regular Employee: " << endl;
    ofs << "First name: " << firstName <<endl;
    ofs << "Last name: " << lastName << endl;
    ofs << "Ssn: " << hideSsn << endl;
    ofs << "Id: " << id << endl;

    ofs.flush();
}
//end class Emoplyee.cpp
