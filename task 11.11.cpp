#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

class Employee
{
private:
    int hours;
    double hourlyPay;

public:
    Employee()
    {
        this->hours = 0;
        this->hourlyPay = 0;
    }
    Employee(int hrs, double pay)
    {
        this->hours = hrs;
        this->hourlyPay = pay;
    }

    double calcSalary()
    {
        return this->hours * this->hourlyPay;
    }
};

int main()
{
    srand(time(NULL));
    double sum = 0;
    vector<Employee *> employees;
    for (size_t i = 0; i < 10; i++)
    {
        int randHours = rand() % 8 + 2;
        double randSalary = (rand() % 10) + (1.0 / (rand() % 20 + 1)) + 2;
        employees.push_back(new Employee(randHours, randSalary));
    }
    for (std::vector<Employee *>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        sum += (*it)->calcSalary();
        cout << (*it)->calcSalary() << endl;
    }

    cout << endl;
    cout << "Sum = " << sum;

    return 0;
}
