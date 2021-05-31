#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include "equasions.h"

using namespace std;


int main()
{
    double smallest = std::numeric_limits<double>::max();
    ifstream file("equasions.txt");
    string str;
    double summ=0;
    int has_no_korni=0;
    int is_inf=0;
    double *arr = new double[3];
    double *res;

    while(getline(file, str))
    {
        istringstream ss(str);
        string type;
        ss >> type;
        if(type == "linear")
        {
            ss >> arr[0] >> arr[1];
            LinearEquasion linear(arr);
            linear.show();
            double reslinear = linear.solve();
            cout << reslinear << endl << endl;
            if(isinf(reslinear))
                is_inf += 1;
            else summ += pow(reslinear, 2);
            if(abs(reslinear) < smallest)
                smallest = reslinear;

        }
        else if(type == "quadratic")
        {
            ss >> arr[0] >> arr[1] >> arr[2];
            QuadraticEquasion quad(arr);
            quad.show();
            res = quad.solve();
            for(int i=0; i<res[0]; i++)
            {
                cout << res[i+1] << " ";
                if(isinf(res[i+1]))
                {
                    is_inf += 1;
                    break;
                }
                summ += pow(res[i+1], 2);
                if(abs(res[i+1]) < smallest)
                    smallest = res[i+1];
            }
            cout << endl << endl;
            if(!res[0])
                has_no_korni += 1;
        }
        else{
            ss >> arr[0] >> arr[1] >> arr[2];
            BiquadraticEquasion quad(arr);
            quad.show();
            res = quad.solve();
            for(int i=0; i<res[0]; i++)
            {
                cout << res[i+1] << " ";
                if(isinf(res[i+1]))
                {
                    is_inf += 1;
                    break;
                }
                summ += pow(res[i+1], 2);
                if(abs(res[i+1]) < smallest)
                    smallest = res[i+1];
            }
            cout << endl << endl;
            if(!res[0])
                has_no_korni += 1;
        }
    }

    cout << "Has no roots - " << has_no_korni << endl;
    cout << "Has inf roots - " << is_inf << endl;
    cout << "The smallest abs - " << smallest << endl;
     cout << "Summ of all roots^2 - " << summ << endl;

    /*
    double arr[2] = {2, -15};
    LinearEquasion linear(arr);
    LinearEquasion linear2(linear);
    linear.show();
    linear2.set(1, -5);
    linear2.show();

    cout << linear.solve() << " " << linear2.solve() << endl << endl;

    double arr_q[3] = {1, -5, 1};
    QuadraticEquasion quad(arr_q);
    quad.show();


    //double *res = new double[3];
    double *res = quad.solve();
    for(int i=0; i<res[0]; i++)
    {
        cout << res[i+1] << " ";
    }
    cout << endl << endl;

    double arr_bi[3] = {1, -5, 6.2};
    BiquadraticEquasion biquad(arr_bi);
    biquad.show();
    res = biquad.solve();
    for(int i=0; i<res[0]; i++)
    {
        cout << res[i+1] << " ";
    }
    cout << endl;
    */

    return 0;
}
