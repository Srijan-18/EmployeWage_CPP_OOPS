#include <iostream>
#include <ctime>
#include <vector>
#include "IEmpWageBuilder.cpp"

using namespace std;

class EmployeeWageBuilder : public IEmpWageBuilder
{
    int dailyWage = 0, dailyHours = 0;
    int dayCount, monthlyWage, hoursCount;
    int MAX_WORKING_DAYS, MAX_WORKING_HOURS, WAGE_PER_HOUR;
    int companyCounter = 0;
    vector<Company> companies;

    inline int getAttendance()
    {
        return rand() % 3;
    }

    inline int getDailyWorkingHours()
    {
        const int FULL_TIME = 1;
        const int PART_TIME = 2;
        const int FULL_DAY_HOURS = 8;
        const int PART_TIME_HOURS = 4;
        const int ABSENT_HOURS = 0;

        switch (getAttendance())
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

    inline int getDailyWage()
    {
        dailyWage = dailyHours * WAGE_PER_HOUR;
        return dailyWage;
    }

    void generateEmpWageForCompany(Company *currentCompany)
    {
        for (int employee = 0; employee < currentCompany->getEmployeeCount(); employee++)
        {
            updateCalculationParameters(*currentCompany);
            generateWageForEmployee(&(currentCompany->employees[employee]));
            updateTotalWageOfCompany(currentCompany);
        }
    }

    inline void updateTotalWageOfCompany(Company *currentCompany)
    {
        currentCompany->setTotalWage(currentCompany->getTotalWage() + monthlyWage);
    }

    inline void updateCalculationParameters(Company currentCompany)
    {
        dayCount = 0;
        monthlyWage = 0;
        hoursCount = 0;
        MAX_WORKING_DAYS = currentCompany.getMaxWorkingDays();
        MAX_WORKING_HOURS = currentCompany.getMaxWorkingHours();
        WAGE_PER_HOUR = currentCompany.getWagePerHour();
    }

    void generateWageForEmployee(Employee *employee)
    {
        while (dayCount < MAX_WORKING_DAYS && hoursCount < MAX_WORKING_HOURS)
        {
            hoursCount += getDailyWorkingHours();
            dailyWage = getDailyWage();
            employee->updateDailyWage(dailyWage);
            monthlyWage += dailyWage;
            dayCount++;
        }

        employee->setMonthlyWage(monthlyWage);
    }

    void registerEmployees()
    {
        for (int employee = 0; employee < 2; employee++)
            companies[companyCounter].registerEmployee("Employee_" + to_string(employee + 1));
    }

    int getTotalWageForCompany(string companyName)
    {
        for (int companyCount = 0; companyCount < companies.size(); companyCount++)
            if (companies[companyCount].getCompanyName() == companyName)
                return companies[companyCount].getTotalWage();
        return -1;
    }

public:
    void generateMonthlyWage();
    void registerCompany(Company company);
    void displayWages();
    void printTotalWage();
};

void EmployeeWageBuilder::registerCompany(Company company)
{
    companies.push_back(company);
    registerEmployees();
    companyCounter++;
    this->generateMonthlyWage();
}

void EmployeeWageBuilder::generateMonthlyWage()
{
    srand(time(0)); //setting seed for random function in order to get different random values for attendance.

    for (int companyNumber = 0; companyNumber < companyCounter; companyNumber++)
    {
        generateEmpWageForCompany(&companies[companyNumber]);
    }
}

void EmployeeWageBuilder::displayWages()
{
    for (int companyCount = 0; companyCount < companies.size(); companyCount++)
        companies[companyCount].displayDetails();
}

void EmployeeWageBuilder::printTotalWage()
{
    string companyName;
    cout << "ENTER COMPANY NAME: ";
    cin >> companyName;
    int totalWage = getTotalWageForCompany(companyName);
    (totalWage != -1) ? cout << "\nTOTAL WAGE FOR " << companyName << " IS : " << totalWage << endl : cout << "\nNO SUCH COMPANY PRESENT" << endl;
}