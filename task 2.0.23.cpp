#include <iostream>
#include <ctime>

static const int N = 6;

using std::cout;
using std::cin;
using std::endl;

void print_arr(int arr[], int N)
{
    cout << endl;
    for(int i=0; i<N; i++)
    {
        cout << arr[i] << " ";
    }
}

double zalik(int arr[], int N)
{
    int maxx=arr[0], minn=arr[0];
    double summ=0;
    for(int i=0; i<N; i++)
    {
        if(arr[i] > maxx)
        {
            maxx = arr[i];
        }
        if(arr[i] < minn)
        {
            minn = arr[i];
        }
        summ += arr[i];
    }
    summ = summ - maxx - minn;
    return summ / (N - 2);
}

int main()
{
    srand(time(0));
    int arr[N];
    for(int i=0; i<N; i++)
    {
        arr[i] = rand() % 10 + 1;
    }

    print_arr(arr, N);
    cout << endl;
    cout << "Result - " << zalik(arr, N) << endl;

    return 0;
}
