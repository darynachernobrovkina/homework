#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

double soft_plus(double x)
{
    return log(1 + exp(x));
}

double soft_plus_derivative(double x)
{
    return exp(x) / (exp(x) + 1);
}

int main()
{
    double x;

    cout << "Enter x value - ";
    cin >> x;

    cout << "SoftPlus(x) = " << soft_plus(x) << endl;
    cout << "SoftPlus'(x) = " << soft_plus_derivative(x);
    return 0;
}
