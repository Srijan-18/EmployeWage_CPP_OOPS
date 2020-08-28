#include <iostream>
#include "employee.cpp"

using namespace std;

class Company
{
    string companyName;
    int MAX_WORKING_DAYS;
    int MAX_WORKING_HOURS;
    int WAGE_PER_HOUR;
    int totalWage;
    int employeeCount;

    void takeInputForCompanyInformations()
    {
        cout << "\nENTER THE NAME OF THE COMPANY: ";
        cin >> this->companyName;
        cout << "\nENTER THE MAXIMUM WORKING DAYS IN A MONTH : ";
        cin >> this->MAX_WORKING_DAYS;
        cout << "\nENTER THE  MAXIMUM WORKING HOURS IN A MONTH : ";
        cin >> this->MAX_WORKING_HOURS;
        cout << "\nENTER THE WAGE PER HOUR : ";
        cin >> this->WAGE_PER_HOUR;
    }

    void displayEmployeesDetails()
    {
        for (int employee = 0; employee < employeeCount; employee++)
            employees[employee].printDetails();
    }

public:
    Employee employees[3];

    Company()
    {
        takeInputForCompanyInformations();
        this->totalWage = 0;
        this->employeeCount = 0;
    }

    void setEmployeeMonthlyWage(int monthlyWage)
    {
        employees[employeeCount - 1].setMonthlyWage(monthlyWage);
    }

    void setTotalWage(int updatedValue)
    {
        this->totalWage = updatedValue;
    }

    int getMaxWorkingDays()
    {
        return this->MAX_WORKING_DAYS;
    }

    int getMaxWorkingHours()
    {
        return this->MAX_WORKING_HOURS;
    }

    int getWagePerHour()
    {
        return this->WAGE_PER_HOUR;
    }

    int getEmployeeCount()
    {
        return this->employeeCount;
    }

    int getTotalWage()
    {
        return this->totalWage;
    }
    
    string getCompanyName()
    {
        return this->companyName;
    }

    void displayDetails()
    {
        cout << "\n====================== "
             << "COMPANY NAME: " << this->companyName << " ======================\n"
             << endl;
        cout << "MAXIMUM WORKING DAYS: " << this->MAX_WORKING_DAYS << endl;
        cout << "MAXIMUM WORKING HOURS: " << this->MAX_WORKING_HOURS << endl;
        cout << "WAGE PER HOUR: " << this->WAGE_PER_HOUR << endl;

        displayEmployeesDetails();

        cout << "\nTOTAL WAGE FOR COMPANY IS: " << this->totalWage << endl;
    }

    void registerEmployee(string name)
    {
        this->employees[this->employeeCount].setEmployeeName(name);
        this->employeeCount++;
    }
};