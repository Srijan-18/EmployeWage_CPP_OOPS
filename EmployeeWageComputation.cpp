#include <iostream>
#include <ctime>
using namespace std;

void printAttendance();

int main()
{
    cout << "WELCOME TO EMPLOYEE WAGE COMPUTATION PROGRAM." << endl;
    printAttendance();
}

void printAttendance()
{
    srand(time(0));

    const int PRESENT = 1;

    int attendance = rand() % 2;
    attendance == PRESENT ? cout << "EMPLOYEE IS PRESENT" << endl: cout << "EMPLOYEE IS ABSENT" << endl;
}