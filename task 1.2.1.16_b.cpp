#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double n, a, b, a_past=1, b_past=1;
    double poslid=1;

    cout << "Enter n - ";
    cin >> n;

    for(int i=2; i<=n; i++)
    {
        a = (pow(b_past, 1.0 / 2) + a_past) / 5;
        b = 2 * b_past + 5 * pow(a_past, 2);
        // cout << "a - " << a << " | b - " << b << endl;
        poslid = poslid * a * b;
        a_past = a;
        b_past = b;
    }
    cout << "Result - " << poslid;
    return 0;
}

