#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
    double x, y ,z, a;
    int different=0, same=0, bigger_than_average=0, bigger_than_a=0, average;

    cout << "Enter numbers : X, Y, Z - ";
    cin >> x >> y >> z;
    cout << "Enter value A - ";
    cin >> a;

    average = (x + y + z) / 3;

    if(x==y)
    {
        same += 1;
    }
    else
    {
        different += 1;
    }
    if(x==z)
    {
        same += 1;
    }
    else
    {
        different += 1;
    }
    if(y==z)
    {
        same += 1;
    }
    else
    {
        different += 1;
    }
    if(same and same!=3) same++;

    if(x > average)
    {
        bigger_than_average += 1;
    }
    if(y > average)
    {
        bigger_than_average += 1;
    }
    if(z > average)
    {
        bigger_than_average += 1;
    }
    if(x > a)
    {
        bigger_than_a += 1;
    }
    if(y > a)
    {
        bigger_than_a += 1;
    }
    if(z > a)
    {
        bigger_than_a += 1;
    }
    cout << endl;
    cout << "Same-different: " << same << "-" << different << endl;
    cout << "Bigger than average - " << bigger_than_average << endl;
    cout << "Bigger than 'a' - " << bigger_than_a;


    return 0;
}
