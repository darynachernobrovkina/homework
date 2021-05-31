#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** alloc_array(int n, int m)
{
    int **arr = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
        arr[i] = (int *)calloc(m, sizeof(int));

    return arr;
}

void print_arr(int **arr, int n, int m)
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int ** delete_even_columns(int **arr, int n, int m, int *new_columns)
{
    int col_counter;
    if(m % 2 == 0)
    {
        *new_columns = m / 2;
    }
    else
    {
        *new_columns = m / 2 + 1;
    }
    int **new_arr = alloc_array(n, *new_columns);

    for(int i=0; i<n; i++)
    {
        col_counter = 0;
        for(int j=0; j<m; j++)
        {
            if(j % 2 == 0)
            {
                new_arr[i][col_counter] = arr[i][j];
                col_counter += 1;
            }
        }
    }
    return new_arr;
}


int main()
{
    srand(time(0));
    int **arr, **new_arr, new_columns;
    int n, m;
    printf("Enter N and M - ");
    scanf("%d %d", &n, &m);

    arr = alloc_array(n, m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    print_arr(arr, n, m);

    new_arr = delete_even_columns(arr, n, m, &new_columns);
    print_arr(new_arr, n, new_columns);

    return 0;
}
