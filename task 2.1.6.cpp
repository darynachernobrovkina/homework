#include <iostream>
// #define N 10

static const int N = 10;

double task_sum(double matr[N][N], int n, int m, int k)
{
    double sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i-j == k)
            {
                sum += matr[i][j];
            }
        }
    }
    return sum;
}

void enter_row(double matr[N][N], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        std::cout << "Enter " << m << " elements - ";
        for(int j=0; j<m; j++)
        {
            std::cin >> matr[i][j];
        }
    }
}

void print(double matr[N][N], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n, m, k;
    double sum;

    std::cout << "Enter n and m - ";
    std::cin >> n >> m;

    std::cout << "Enter k - ";
    std::cin >> k;

    double matrix[N][N];

    enter_row(matrix, n, m);
    //print(matrix, n, m);

    sum = task_sum(matrix, n, m, k);

    std::cout << "Sum - " << sum;

    return 0;
}
