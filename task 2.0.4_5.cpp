#include <iostream>
#include <cmath>
#define N 5

int find_max(int *mas, int size_of)
{
    int maxx=mas[0];
    for(int i=0; i<size_of; i++)
    {
        if (mas[i] > maxx)
        {
            maxx = mas[i];
        }
    }

    return maxx;
}

void even_odd(int *mas, int size_of)
{
    int even=0, odd=0;
    for(int i=0; i<size_of; i++)
    {
        if (mas[i] % 2 == 0)
        {
            even += mas[i];
        }
        else
        {
            odd += mas[i];
        }
    }
    std::cout << "Sum of even - " << even << std::endl;
    std::cout << "Sum of odd - " << odd << std::endl;
}

int main()
{
    int mas[N];
    int sum=0, maxx;
    for(int i=0; i<N; i++)
    {
        std::cin >> mas[i];
    }

    maxx = find_max(mas, N);
    std::cout << "Max - " << maxx << std::endl;
    std::cout << "Enter another 5 elements - ";
    for(int i=0; i<N; i++)
    {
        std::cin >> mas[i];
    }
    even_odd(mas, N);
    return 0;
}
