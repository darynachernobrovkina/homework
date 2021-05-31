#include <iostream>
using namespace std;

bool is_prime(int number)
{
    bool is_prime = true;
    if (number == 0 || number == 1)
    {
        is_prime = false;
    }
    else
    {
        for (int i = 2; i <= number / 2; ++i)
        {
            if (number % i == 0)
            {
                is_prime = false;
                break;
            }
        }
    }
    return is_prime;
}

int main() {
    int n;


    cout << "Enter n: ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        if(is_prime(i))
        {
            cout << "Number " << i << " is prime" << endl;
        }
    }

    return 0;
}
