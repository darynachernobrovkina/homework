#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

static const int N = 10;

using std::cout;
using std::cin;
using std::endl;
using std::string;

void print_arr(int arr[], int N)
{
    cout << endl;
    for(int i=0; i<N; i++)
    {
        cout << arr[i] << " ";
    }
}

int find_max(int arr[], int N)
{
    string indexes;
    int maxx=arr[0];
    int multiplied=arr[0];
    for(int i=1; i<N; i++)
    {
        multiplied *= arr[i];
        // cout << i << " " << maxx << " " << multiplied << endl;
        if(multiplied > maxx)
        {
            maxx = multiplied;
        }
    }
    return maxx;
}

int odd_sqrt(int arr[], int N)
{
    cout << endl;
    int counter=0;
    for(int i=0; i<N; i++)
    {
        if(fmod(sqrt(arr[i]), 2) == 1)
        {
            cout << arr[i] << " ";
            counter += 1;
        }
    }
    return counter;
}

int main()
{
    srand(time(0));
    int arr_one[N];
    int arr_two[N];

    for(int i=0; i<N; i++)
    {
        arr_one[i] = rand() % 20 - 10;
        arr_two[i] = rand() % 20 - 10;
    }


    print_arr(arr_one, N);
    print_arr(arr_two, N);
    cout << endl;
    cout << "Max of first array(a1, a1a2, ... ,a1a2..an) - " << find_max(arr_one, N);
    cout << endl << "Odd roots - ";
    cout << endl << "Count - "<< odd_sqrt(arr_two, N);


    return 0;
}
