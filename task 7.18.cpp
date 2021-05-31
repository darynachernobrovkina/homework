#include <iostream>
#include <cmath>
#include <stdbool.h>

using namespace std;


class Point
{
private:
    double x, y;
    double starterSpeedX, starterSpeedY;
    double accelerationX, accelerationY;
public:
    Point()
    {
        this->x = 0;
        this->y = 0;
        this->starterSpeedX = 0;
        this->starterSpeedY = 0;
        this->accelerationX = 0;
        this->accelerationY = 0;
    }
    Point(double x, double y, double starterSpeedX, double starterSpeedY, double accelerationX, double accelerationY)
    {
        this->x = x;
        this->y = y;
        this->starterSpeedX = starterSpeedX;
        this->starterSpeedY = starterSpeedY;
        this->accelerationX = accelerationX;
        this->accelerationY = accelerationY;
    }

    double getSpeedX(int time__)
    {
        return this->starterSpeedX + this->accelerationX * time__;
    }
    double getSpeedY(int time__)
    {
        return this->starterSpeedY + this->accelerationY * time__;
    }

    double getX(int time_)
    {
        double newX = this->x;
        for(int i=0; i<time_; i++)
        {
            newX += getSpeedX(i);
        }
        return newX;
    }

    double getY(int time_)
    {
        double newY = this->y;
        for(int i=0; i<time_; i++)
        {
            newY += getSpeedY(i);
        }
        return newY;
    }

    int input()
    {
        cout << "X, Y - ";
        cin >> this->x >> this->y;
        cout << "Velocity X, Y - ";
        cin >> this->starterSpeedX >> this->starterSpeedY;
        cout << "Acceleration X, Y - ";
        cin >> this->accelerationX >> this->accelerationY;
        cout << endl;
    }

    void show(int time_)
    {
        cout << "{ "<<this->getX(time_)<<", "<<this->getY(time_)<<" }" << "| V: ( " << this->getSpeedX(time_) << ", " << this->getSpeedY(time_) << " )" << endl;
    }

    bool isColinear(const Point &point)
    {
        double speedRatioX = this->starterSpeedX / point.starterSpeedX;
        double speedRatioY = this->starterSpeedY / point.starterSpeedY;
        double accRatioX = this->accelerationX / point.accelerationX;
        double accRatioY = this->accelerationY / point.accelerationY;
        if(speedRatioX == speedRatioY && speedRatioX == accRatioX && speedRatioX == accRatioY)
        {
            return true;
        }
        else{
            return false;
        }
    }

    double countDistance(Point point, int time_)
    {
        return sqrt(pow(this->getX(time_) - point.getX(time_), 2) + pow(this->getY(time_) - point.getY(time_), 2));
    }
};


int main()
{
    Point point(1.0, 2.0, 1.3, 2, 0.4, 0.5);
    Point point2(-2.0, -2.0, 2.6, 4, 0.8, 1);

    //point.input();
    //point2.input();

    cout << "Point 1: " << endl;
    point.show(0);
    point.show(1);
    point.show(2);
    point.show(3);

    cout << endl;
    cout << "Point 2: " << endl;
    point2.show(0);
    point2.show(1);
    point2.show(2);
    point2.show(3);

    cout << endl;

    cout << "Distance at 0: " << point.countDistance(point2, 0) << endl;
    cout << "Distance at 1: " << point.countDistance(point2, 1) << endl;
    cout << "Distance at 2: " << point.countDistance(point2, 2) << endl;

    cout << point.isColinear(point2);
    return 0;
}



