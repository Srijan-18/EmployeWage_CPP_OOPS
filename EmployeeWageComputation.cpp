#include <iostream>
#include <ctime>
using namespace std;

class EmployeeWage
{
    const int MAX_WORKING_DAYS = 20;
    const int MAX_WORKING_HOURS = 100;
    const int WAGE_RATE = 20;
    int dailyWage = 0, dailyHours = 0;
    int dayCount = 0, monthlyWage = 0, hoursCount = 0;

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
        cout << "DAILY WAGE OF EMPLOYEE IS: " << dailyWage << endl;

        return dailyWage;
    }

public:
    void generateMonthlyWage();
};

void EmployeeWage::generateMonthlyWage()
{
    srand(time(0)); //setting seed for random function in order to get different random values for attendance.
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

    EmployeeWage employee;
    employee.generateMonthlyWage();

    return 0;
}