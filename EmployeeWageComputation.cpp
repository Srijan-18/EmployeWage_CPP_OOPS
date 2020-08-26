#include <iostream>
#include <ctime>

using namespace std;

class Company
{
public:
    string companyName;
    int MAX_WORKING_DAYS;
    int MAX_WORKING_HOURS;
    int WAGE_PER_HOUR;

    Company(string companyName, int maxWorkingDays, int maxWorkingHours, int WagePerHour)
    {
        this->companyName = companyName;
        MAX_WORKING_DAYS = maxWorkingDays;
        MAX_WORKING_HOURS = maxWorkingHours;
        WAGE_PER_HOUR = WagePerHour;
    }
};

class EmployeeWageCalculator
{
    int MAX_WORKING_DAYS;
    int MAX_WORKING_HOURS;
    int WAGE_RATE;
    int dailyWage = 0, dailyHours = 0;
    int dayCount, monthlyWage, hoursCount;
    string companyName;

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
        dailyWage = dailyHours * WAGE_RATE;
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
    MAX_WORKING_DAYS = company.MAX_WORKING_DAYS;
    MAX_WORKING_HOURS = company.MAX_WORKING_HOURS;
    WAGE_RATE = company.WAGE_PER_HOUR;
    companyName = company.companyName;
}

void EmployeeWageCalculator::generateMonthlyWage()
{
    srand(time(0)); //setting seed for random function in order to get different random values for attendance.

    cout << "\n====================== " << companyName << " ======================\n"
         << endl;

    while (dayCount < MAX_WORKING_DAYS && hoursCount < MAX_WORKING_HOURS)
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