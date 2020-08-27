#include <iostream>
#include <ctime>
#include "EmpWageBuilder.cpp"

using namespace std;

void presentWelcomeMessage()
{
    cout << "WELCOME TO EMPLOYEE WAGE COMPUTATION PROGRAM." << endl;
}

void registerCompanies(IEmpWageBuilder *employeeWageBuilder)
{

    int company1Information[3] = {20, 100, 20};
    Company company1("Company1", company1Information);

    int company2Information[3] = {10, 50, 50};
    Company company2("Company2", company2Information);

    employeeWageBuilder->registerCompany(company1);
    employeeWageBuilder->registerCompany(company2);
}

int main()
{
    presentWelcomeMessage();

    IEmpWageBuilder *employeeWageBuilder = new EmployeeWageBuilder();
    registerCompanies(employeeWageBuilder);
    employeeWageBuilder->generateMonthlyWage();

    return 0;
}