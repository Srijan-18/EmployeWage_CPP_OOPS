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
    int employeeCounter;

public:
    Employee employees[5];

    Company()
    {
    }

    Company(string companyName, int companyInformation[])
    {
        this->companyName = companyName;
        MAX_WORKING_DAYS = companyInformation[0];
        MAX_WORKING_HOURS = companyInformation[1];
        WAGE_PER_HOUR = companyInformation[2];
        totalWage = 0;
        employeeCounter = 0;
    }

    void setEmployeeMonthlyWage(int monthlyWage)
    {
        employees[employeeCounter - 1].setMonthlyWage(monthlyWage);
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

    int getEmployeeCounter()
    {
        return this->employeeCounter;
    }

    int getTotalWage()
    {
        return this->totalWage;
    }

    void displayDetails()
    {
        cout << "\n====================== " << this->companyName << " ======================\n"
             << endl;
        cout << "MAXIMUM WORKING DAYS: " << this->MAX_WORKING_DAYS << endl;
        cout << "MAXIMUM WORKING HOURS: " << this->MAX_WORKING_HOURS << endl;
        cout << "WAGE PER HOUR: " << this->WAGE_PER_HOUR << endl;
    }

    void registerEmployee(string name)
    {
        employees[employeeCounter].setEmployeeName(name);
        employeeCounter++;
    }

    void displayEmployeesDetails()
    {
        for (int employee = 0; employee < employeeCounter; employee++)
            employees[employee].printDetails();
    }
};