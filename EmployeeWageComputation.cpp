#include <iostream>
#include <ctime>
#include "EmpWageBuilder.cpp"

using namespace std;

void presentWelcomeMessage()
{
    cout << "WELCOME TO EMPLOYEE WAGE COMPUTATION PROGRAM." << endl;
}

void addCompany(IEmpWageBuilder *employeeWageBuilder)
{
    Company company;
    employeeWageBuilder->registerCompany(company);
}

void presentChoices()
{
    IEmpWageBuilder *employeeWageBuilder = new EmployeeWageBuilder();
    addCompany(employeeWageBuilder);

    const int ADD_COMPANY = 1;
    const int DISPLAY_WAGES = 2;
    bool flag = true;

    while (flag)
    {
        int choice;

        cout << "\n\t\t****\nENTER 1 TO ADD A NEW COMPANY.\nENTER 2 TO DISPLAY WAGES.\nANY OTHER OT EXIT.\n\t\t****\n\nYOUR CHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case ADD_COMPANY:
            addCompany(employeeWageBuilder);
            break;
        case DISPLAY_WAGES:
            employeeWageBuilder->displayWages();
            break;
        default:
            flag = false;
        }
    }
}

int main()
{
    presentWelcomeMessage();

    presentChoices();

    return 0;
}