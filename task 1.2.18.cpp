#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double deposit, stavka=0.15, expected, counter=0;
    cout << "Enter the deposit and the expected amount - ";
    cin >> deposit >> expected;

    while(deposit < expected)
    {
        // cout << deposit << endl;
        deposit += deposit * stavka;
        counter += 1;
    }
    cout << endl << "You must wait " << counter << " years";

    return 0;
}
