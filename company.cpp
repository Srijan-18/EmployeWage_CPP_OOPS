#include <iostream>

using namespace std;

class Company
{
public:
    string companyName;
    int MAX_WORKING_DAYS;
    int MAX_WORKING_HOURS;
    int WAGE_PER_HOUR;
    int totalWage;
    Company()
    {
    }

    Company(string companyName, int maxWorkingDays, int maxWorkingHours, int WagePerHour)
    {
        this->companyName = companyName;
        MAX_WORKING_DAYS = maxWorkingDays;
        MAX_WORKING_HOURS = maxWorkingHours;
        WAGE_PER_HOUR = WagePerHour;
        totalWage = 0;
    }
};