#include <iostream>

using namespace std;

class Employee
{
    int monthlyWage;
    string employeeName;

public:
    Employee()
    {
        this->employeeName = "NONAME";
        this->monthlyWage = 0;
    }

    void setEmployeeName(string name)
    {
        this->employeeName = name;
    }

    void setMonthlyWage(int monthlyWage)
    {
        this->monthlyWage = monthlyWage;
    }

    string getEmployeeName()
    {
        return this->employeeName;
    }

    int getMonthlyWage()
    {
        return this->monthlyWage;
    }
    
    void printDetails()
    {
        cout << "\nEMPLOYEE NAME: " << this->employeeName << "\t\tMONTHLY WAGE: " << this->monthlyWage << endl;
    }
};