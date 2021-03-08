#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double eps=0.00000001;
    double x, poslid=0, a;
    int counter=0;

    cout << "Enter x - ";
    cin >> x;
    a = -1;

    do
    {
        counter += 1;
        a = a * (-x / counter);
        cout << a << endl;
        poslid += a;

    }while(fabs(a) > eps);

    cout << "ln(1+x) = " << poslid;

    return 0;
}
