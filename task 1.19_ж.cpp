#include <iostream>
#include <cmath>

using namespace std;

double soft_exp(double a, double x)
{
    if(a < 0)
    {
        return -log(1 - a * (x+a)) / a;
    }
    else if(a > 0)
    {
        return (exp(a*x) - 1) / a + a;
    }
    else
    {
        return x;
    }
}
double soft_exp_derivative(double a, double x)
{
    if(a < 0)
    {
        return 1.0 / (1 - a * (x + a));
    }
    else if(a > 0)
    {
        return exp(a*x);
    }
    else
    {
        return 1;
    }
}

int main()
{
    double x, a;
    cout << "Enter a and x - ";
    cin >> a >> x;
    cout << "Result of softexp - " << soft_exp(a, x) << endl;
    cout << "Result of softexp derivative - " << soft_exp_derivative(a, x);
    return 0;
}
