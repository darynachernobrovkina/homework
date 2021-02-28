#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double n, a0=1, a1=1, a2=3, next_a, counter=4;
    double poslid;

    cout << "Enter n - ";
    cin >> n;
    poslid = a0 / 3;
    if(n == 0)
    {
        cout << "Result - " << poslid;
        return 0;
    }
    poslid *= a1 / 3;
    if(n == 1)
    {
        cout << "Result - " << poslid;
        return 0;
    }
    poslid *= a2 / 3;
    if(n == 2)
    {
        cout << "Result - " << poslid;
        return 0;
    }

    for(int i=3; i<=n; i++)
    {
        next_a = a0 + a1 / counter;
        a0 = a1;
        a1 = a2;
        a2 = next_a;
        poslid *= next_a / 3;
        counter *= 2;
        // cout << poslid << endl;
    }
    cout << "Result - " << poslid;
    return 0;
}
