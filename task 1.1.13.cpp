#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x1, x2, y1, y2;
    double x3, x4, y3, y4;
    double final_x1, final_x2, final_y1, final_y2;
    cout << "Enter coords of first rectangle (left_x, lefty, right_x, right_y) - ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter coords of second rectangle - ";
    cin >> x3 >> y3 >> x4 >> y4;

    if(x1 <= x3)
    {
       final_x1 = x1;
    }
    else final_x1 = x3;

    if(x2 <= x4)
    {
       final_x2 = x4;
    }
    else final_x2 = x2;

    if(y1 <= y3)
    {
       final_y1 = y1;
    }
    else final_y1 = y3;

    if(y2 <= y4)
    {
       final_y2 = y4;
    }
    else final_y2 = y2;

    cout << "Coords of final rectangle (left_bottom) and (right_up) " << endl;
    cout << "("<< final_x1 << ", " << final_y1 << ") (" << final_x2 << ", " << final_y2 << ")";
    return 0;
}
