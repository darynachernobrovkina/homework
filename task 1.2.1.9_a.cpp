#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double n, x, x_past=-99, x_past2=-99;
    cout << "Enter n - ";
    cin >> n;

    for(int i=3; i<=n; i++)
    {
        x = x_past + x_past2 + 100;
        cout << "X - " << x << endl;
        x_past2 = x_past;
        x_past = x;
    }

    cout << "Result - " << x;
    return 0;
}
