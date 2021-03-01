#include <iostream>
#include <cmath>
#define N 100

int* enter_mas()
{
    int* mas;
    mas = (int *)calloc(100, sizeof(int));
    for(int i=0; i<100; i++)
    {
        std::cout << "a[" << i << "] = ";
        std::cin >> mas[i];
        if (mas[i] == 0)
        {
            break;
        }
    }
    return mas;
}

int summ_of_mas(int *mas, int size_of)
{
    int summ=0;
    for(int i=0; i<size_of; i++)
    {
        summ += mas[i];
        if(mas[i] == 0)
        {
            break;
        }
    }

    return summ;
}

int main()
{
    int *mas;
    int sum=0, maxx;
    mas = enter_mas();
    for(int i=0; i<N; i++)
    {
        std::cout << mas[i] << " ";
        if(mas[i] == 0)
        {
            break;
        }
    }
    sum = summ_of_mas(mas, N);
    std::cout << std::endl << "Sum - " << sum << std::endl;
    return 0;
}
