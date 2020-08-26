#include <iostream>
#include <ctime>
using namespace std;

int getDailyWage();
int getWageByAttendanceAndRate(int, int);
inline int getWorkingHours(int);
void generateMonthlyWage(int);

int main()
{
    cout << "WELCOME TO EMPLOYEE WAGE COMPUTATION PROGRAM." << endl;
    
    const int MAX_WORKING_DAYS = 20;
    generateMonthlyWage(MAX_WORKING_DAYS);

    return 0;
}

void generateMonthlyWage(int MAX_WORKING_DAYS)
{
    srand(time(0)); //setting seed for random function in order to get different random values for attendance.
    int dayCount = 0, monthlyWage = 0;

    while (dayCount < 20)
    {
        monthlyWage += getDailyWage();
        dayCount++;
    }

    cout << "MONTHLY WAGE OF EMPLOYEE IS: " << monthlyWage << endl;
}

int getDailyWage()
{
    const int WAGE_RATE = 20;
    int dailyWage = 0;
    int attendance = rand() % 3;

    dailyWage = getWageByAttendanceAndRate(attendance, WAGE_RATE);
    cout << "DAILY WAGE OF EMPLOYEE IS: " << dailyWage << endl;

    return dailyWage;
}

int getWageByAttendanceAndRate(int attendance, int rate)
{
    int workingHours = getWorkingHours(attendance);
    return workingHours * rate;
}

inline int getWorkingHours(int attendance)
{
    const int FULL_TIME = 1;
    const int PART_TIME = 2;
    const int FULL_DAY_HOURS = 8;
    const int PART_TIME_HOURS = 4;
    const int ABSENT_HOURS = 0;

    switch (attendance)
    {
    case PART_TIME:
        cout << "EMPLOYEE IS PRESENT PART TIME AND ";
        return PART_TIME_HOURS;

    case FULL_TIME:
        cout << "EMPLOYEE IS PRESENT FULL TIME AND ";
        return FULL_DAY_HOURS;

    default:
        cout << "EMPLOYEE IS ABSENT AND ";
        return ABSENT_HOURS;
    }
}