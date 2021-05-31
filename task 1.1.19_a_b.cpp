#include <iostream>

using namespace std;

double onestep(double x)
{
    if(x >= 0) return 1;
    else return 0;
}

double onestep_derivative(double x)
{
    return 0;
}

double relu(double x)
{
    if(x > 0) return x;
    else return 0;
}
double relu_derivative(double x)
{
    if(x > 0) 1;
    else return 0;
}

int main()
{
    double x;

    cout << "Enter x :";
    cin >> x;
    cout << "Result of onestep " << onestep(x) << endl;
    cout << "Result of onestep_derivative " << onestep_derivative(x) << endl;
    cout << "Result of relu " << relu(x) << endl;
    cout << "Result of relu_derivative " << relu_derivative(x) << endl;

    return 0;
}
