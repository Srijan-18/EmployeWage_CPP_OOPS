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
            dailyHours = PART_TIME_HOURS;
            break;
        case FULL_TIME:
            dailyHours = FULL_DAY_HOURS;
            break;
        default:
            dailyHours = ABSENT_HOURS;
        }

        return dailyHours;
    }

    int getDailyWage()
    {
        dailyWage = dailyHours * company.WAGE_PER_HOUR;
        cout << "\t " << dayCount + 1 << "\t\t     " << dailyHours << "\t\t\t     " << dailyWage << endl;

        return dailyWage;
    }

    void updateTotalWageOfCompany(int changeInValue)
    {
        company.totalWage += changeInValue;
    }

    void displayHeader()
    {
        cout << "\n\tDAY\t\tWORKING HOURS\t\tTODAY'S WAGE" << endl;
        cout << "\t===\t\t=============\t\t============\n"
             << endl;
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

    company.displayDetails();
    displayHeader();
    
    while (dayCount < company.MAX_WORKING_DAYS && hoursCount < company.MAX_WORKING_HOURS)
    {
        hoursCount += generatedDailyWorkingHours();
        monthlyWage += getDailyWage();
        dayCount++;
    }

    cout << "\nMONTHLY WAGE OF EMPLOYEE IS: " << monthlyWage << endl;

    updateTotalWageOfCompany(monthlyWage);
    cout << "TOTAL WAGE FOR COMPANY IS: " << company.totalWage << endl;
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