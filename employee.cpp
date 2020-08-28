#include <iostream>

using namespace std;

class Employee
{
    int monthlyWage;
    string employeeName;
    vector<int> dailyWage;

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

    inline void updateDailyWage(int todaysWage)
    {
        dailyWage.push_back(todaysWage);
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
        cout << "\nEMPLOYEE NAME: " << this->employeeName << endl;
        
        for(int dayCounter = 0; dayCounter < dailyWage.size(); dayCounter++)
            cout << "\nDAY: " << dayCounter + 1 << "\t\t WAGE FOR TODAY: " << dailyWage[dayCounter] << endl;

        cout << "\n\t\t*** MONTHLY WAGE: " << this->monthlyWage << " ***" << endl;
    }
};