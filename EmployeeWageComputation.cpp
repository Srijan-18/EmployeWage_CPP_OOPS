#include <iostream>
#include <ctime>
using namespace std;

int getAttendance();
void generateDailyWage();
int getWageByAttendanceAndRate(int, int);
int getWorkingHours(int);

int main()
{
    cout << "WELCOME TO EMPLOYEE WAGE COMPUTATION PROGRAM." << endl;
    generateDailyWage();
}

void generateDailyWage()
{
    const int WAGE_RATE = 20;
    int dailyWage = 0;
    int attendance = getAttendance();

    dailyWage = getWageByAttendanceAndRate(attendance, WAGE_RATE);
    cout << "DAILY WAGE OF EMPLOYEE IS: " << dailyWage << endl;
}

int getAttendance()
{
    srand(time(0));

    return rand() % 2;
}

int getWageByAttendanceAndRate(int attendance, int rate)
{
    int workingHours = getWorkingHours(attendance);
    return workingHours * rate;
}

int getWorkingHours(int attendance)
{
    const int PRESENT = 1;
    const int FULL_DAY_HOURS = 8;
    const int ABSENT_HOURS = 0;

    if (attendance == PRESENT)
    {
        cout << "EMPLOYEE IS PRESENT AND ";
        return FULL_DAY_HOURS;
    }
    cout << "EMPLOYEE IS ABSENT AND ";
    return ABSENT_HOURS;
}