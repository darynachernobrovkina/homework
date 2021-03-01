#include <iostream>
#include <cmath>
#define N 10

using namespace std;

int input(double mas[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> mas[i];
    }
}

void output(const double mas[], int size)
{
    cout << "Mas -";
    for(int i=0; i<size; i++)
    {
        cout << " " << mas[i];
    }
}

int scal_sum(const double mas1[], const double mas2[], double mas3[], int size)
{
    for(int i=0; i<size; i++)
    {
        mas3[i] = mas1[i] + mas2[i];
    }
    return 0;
}

double scal_mult(const double mas1[], const double mas2[], int size)
{
    double mult=0;
    for(int i=0; i<size; i++)
    {
        mult += mas1[i] * mas2[i];
    }
    return mult;
}

int main(){

    double mas1[N];
    double mas2[N];
    double mas3[N];

    unsigned n;
    double dob;

    do
    {
        cout << "N = ";
        cin >> n;
    }while(n==0 || n>10);


    input(mas1,n);
    input(mas2,n);

    dob = scal_mult(mas1, mas2, n);

    scal_sum(mas1, mas2, mas3, n);

    cout << "Dobutok = " << dob << endl;

    output(mas3,n);
}
