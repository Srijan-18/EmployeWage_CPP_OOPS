#include <iostream>
#include <ctime>
#include "company.cpp"

using namespace std;

class EmployeeWageCalculator
{
    int dailyWage = 0, dailyHours = 0;
    int dayCount, monthlyWage, hoursCount;
    Company company;

    inline int getAttendance()
    {
        return rand() % 3;
    }

    inline int generatedDailyWorkingHours()
    {
        const int FULL_TIME = 1;
        const int PART_TIME = 2;
        const int FULL_DAY_HOURS = 8;
        const int PART_TIME_HOURS = 4;
        const int ABSENT_HOURS = 0;

        int attendance = getAttendance();

        switch (attendance)
        {
        case PART_TIME:
            cout << "EMPLOYEE IS PRESENT PART TIME AND ";
            dailyHours = PART_TIME_HOURS;
            break;
        case FULL_TIME:
            cout << "EMPLOYEE IS PRESENT FULL TIME AND ";
            dailyHours = FULL_DAY_HOURS;
            break;
        default:
            cout << "EMPLOYEE IS ABSENT AND ";
            dailyHours = ABSENT_HOURS;
        }

        return dailyHours;
    }

    int getDailyWage()
    {
        dailyWage = dailyHours * company.WAGE_PER_HOUR;
        cout << "CURRENT DAY'S WAGE OF EMPLOYEE IS: " << dailyWage << endl;

        return dailyWage;
    }

public:
    void generateMonthlyWage();
    void registerCompany(Company company);
};

void EmployeeWageCalculator::registerCompany(Company company)
{
    dayCount = 0;
    monthlyWage = 0;
    hoursCount = 0;
    this->company = company;
}

void EmployeeWageCalculator::generateMonthlyWage()
{
    srand(time(0)); //setting seed for random function in order to get different random values for attendance.

    cout << "\n====================== " << company.companyName << " ======================\n"
         << endl;

    while (dayCount < company.MAX_WORKING_DAYS && hoursCount < company.MAX_WORKING_HOURS)
    {
        hoursCount += generatedDailyWorkingHours();
        monthlyWage += getDailyWage();
        dayCount++;
    }
    cout << "MONTHLY WAGE OF EMPLOYEE IS: " << monthlyWage << endl;
}

int main()
{
    cout << "WELCOME TO EMPLOYEE WAGE COMPUTATION PROGRAM." << endl;

    Company company1("Company1", 20, 100, 20);
    Company company2("Company2", 10, 50, 50);

    EmployeeWageCalculator employee;
    employee.registerCompany(company1);
    employee.generateMonthlyWage();

    employee.registerCompany(company2);
    employee.generateMonthlyWage();

    return 0;
}