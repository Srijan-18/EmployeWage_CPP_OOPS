#include <iostream>
#include "company.cpp"

using namespace std;

class IEmpWageBuilder
{

public:
    virtual void registerCompany(Company company) = 0;
    virtual void generateMonthlyWage() = 0;
};