#include <iostream>
#include <cmath>

using namespace std;
double fact_func(int n)
{
    double fact = 1;
    for(int i = 1; i<=n; i++)
    {
        fact *= i;
    }
    return fact;
}

double fact_2n(int n)
{
    double fact=1, fact2=1;
    fact = fact_func(2*n);
    return fact_func(fact);
}

double fact_2n_plus(int n)
{
    double fact=1, fact2=1;
    fact = fact_func(2*n + 1);
    return fact_func(fact);
}

double fact_fact_fact(int n)
{
    double facted;
    facted = fact_func(n);
    return facted * fact_func(facted) * fact_func(fact_func(n+1));
}

int main()
{
    int n;
    cout << "Enter n - ";
    cin >> n;

    cout << "(2*n)!! = " << fact_2n(n) << endl;
    cout << "(2*n + 1)!! = " << fact_2n_plus(n) << endl;
    cout << "n!n!!(n + 1)!! = " << fact_fact_fact(n);
    return 0;
}
