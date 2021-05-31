#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, k, element;
    cout << "Enter x - ";
    cin >> x;
    cout << "Enter number of the element that you want to calculate - ";
    cin >> k;
    element = x;
    for(int i=1; i<k; i++)
    {
        element *= x * x / ((2*i + 1) * (2*i));
    }
    cout << "K-th element - " << element;

    return 0;
}
