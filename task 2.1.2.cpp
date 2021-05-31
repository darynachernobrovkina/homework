#include <iostream>
#define N 3

void transpose(double matr[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            int tmp = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = tmp;
        }
    }
}

void print(double matr[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void change(double matr[N][N], int I, int J, double A)
{
    if(I > N-1 || J > N-1 || I < 0 || J < 0)
    {
        std::cout << "Indexes are out of range!" << std::endl;
    }
    else
    {
        matr[I][J] = A;
    }
}

int main()
{
    int I, J;
    double A;
    double matrix[N][N] =
    {
        {1.0, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    transpose(matrix);
    print(matrix);

    std::cout << "Enter I, J and A - ";
    std::cin >> I >> J >> A;

    change(matrix, I, J, A);
    print(matrix);
    return 0;
}
