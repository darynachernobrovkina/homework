#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter n - ";
    cin >> n;

    int *arr = new int[n];
    double *arr_d = new double[n];

    for(int i=0; i<n; i++)
    {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i];
    }
    ifstream file_1("file.txt");
    int i=0;
    while(!file_1.eof())
    {
        if(file_1 >> arr_d[i])
        {
            cout << "file[" << i << "]=" << arr_d[i] << endl;
        }
        i++;
        if(i >=n) break;
    }
    file_1.close();
    if(i < n){
        cout << "Not enough data";
    }
    ofstream file_2("file_output.txt");
    for(int i=0; i<n; i++)
    {
        file_2 << pow(arr_d[i], arr[i]) << endl;
    }
    file_2.close();
}
