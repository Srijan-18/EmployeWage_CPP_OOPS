#include <iostream>
#include <ctime>
#include "company.cpp"

using namespace std;

class EmployeeWageCalculator
{
    int dailyWage = 0, dailyHours = 0;
    int dayCount, monthlyWage, hoursCount;
    int MAX_WORKING_DAYS, MAX_WORKING_HOURS, WAGE_PER_HOUR;
    int companyCounter = 0;
    Company company[5];

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
        dailyWage = dailyHours * WAGE_PER_HOUR;
        return dailyWage;
    }

    void updateTotalWageOfCompany(Company *currentCompany)
    {
        currentCompany->totalWage += monthlyWage;
    }

    void displayHeader()
    {
        cout << "\n\tDAY\t\tWORKING HOURS\t\tTODAY'S WAGE" << endl;
        cout << "\t===\t\t=============\t\t============\n"
             << endl;
    }

    void generateEmpWageForCompany(Company *currentCompany)
    {
        currentCompany->displayDetails();

        for (int employee = 0; employee < currentCompany->employeeCounter; employee++)
        {
            updateCalculationParameters(currentCompany->MAX_WORKING_DAYS, currentCompany->MAX_WORKING_HOURS, currentCompany->WAGE_PER_HOUR);
            generateWageForEmployee(&(currentCompany->employees[employee]));
            updateTotalWageOfCompany(currentCompany);
        }
    }

    void updateCalculationParameters(int MaxWorkingDays, int MaxWorkingHours, int WagePerHour)
    {
        dayCount = 0;
        monthlyWage = 0;
        hoursCount = 0;
        MAX_WORKING_DAYS = MaxWorkingDays;
        MAX_WORKING_HOURS = MaxWorkingHours;
        WAGE_PER_HOUR = WagePerHour;
    }

    void generateWageForEmployee(Employee *employee)
    {
        while (dayCount < MAX_WORKING_DAYS && hoursCount < MAX_WORKING_HOURS)
        {
            hoursCount += generatedDailyWorkingHours();
            monthlyWage += getDailyWage();
            dayCount++;
        }
        employee->setMonthlyWage(monthlyWage);
        employee->printDetails();
    }

    void registerEmployees()
    {
        for (int employee = 0; employee < 2; employee++)
            company[companyCounter].registerEmployee("Employee_" + to_string(employee + 1));
    }

public:
    void generateMonthlyWage();
    void registerCompany(Company company);
};

void EmployeeWageCalculator::registerCompany(Company company)
{
    this->company[companyCounter] = company;
    registerEmployees();
    companyCounter++;
}

void EmployeeWageCalculator::generateMonthlyWage()
{
    srand(time(0)); //setting seed for random function in order to get different random values for attendance.

    for (int companyNumber = 0; companyNumber < companyCounter; companyNumber++)
    {
        generateEmpWageForCompany(&company[companyNumber]);
        cout << "\nTOTAL WAGE FOR COMPANY IS: " << company[companyNumber].totalWage << endl;
    }
}

EmployeeWageCalculator* registerCompanies(EmployeeWageCalculator *employee)
{

    int company1Information[3] = {20, 100, 20};
    Company company1("Company1", company1Information);

    int company2Information[3] = {10, 50, 50};
    Company company2("Company2", company2Information);

    employee->registerCompany(company1);
    employee->registerCompany(company2);

    return employee;
}

int main()
{
    cout << "WELCOME TO EMPLOYEE WAGE COMPUTATION PROGRAM." << endl;

    EmployeeWageCalculator employee;

    employee = *registerCompanies(&employee);

    employee.generateMonthlyWage();

    return 0;
}