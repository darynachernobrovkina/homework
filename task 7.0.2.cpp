#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
    double x;
    double y;
public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
        void show()
    {
        cout << "(" << this->x << "," << this->y << ")"<< endl;
    }

    int input()
    {
        cout << "x, y = ";
        cin >> this->x >> this->y;
    }
}
