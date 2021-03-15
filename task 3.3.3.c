#include <stdio.h>
#include <math.h>

int * alloc_memory(int n)
{
    int *arr;
    arr = (int *)calloc(n, sizeof(int));

    return arr;
}

void free_memory(int *arr)
{
    free(arr);
}

int * vect_diff(int *arr, int *arr_2, int n)
{
    int *new_arr;
    new_arr = alloc_memory(n);
    for(int i=0; i<n; i++)
    {
        new_arr[i] = arr[i] - arr_2[i];
    }
    return new_arr;
}

void print_arr(int * arr, int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    int *arr, *arr_2, *new_arr;

    printf("Enter n - ");
    scanf("%d", &n);

    arr = alloc_memory(n);
    arr_2 = alloc_memory(n);

    printf("First vector:\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter value- ");
        scanf("%d", &arr[i]);
    }

    printf("Second vector:\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter value - ");
        scanf("%d", &arr_2[i]);
    }

    print_arr(arr, n);
    print_arr(arr_2, n);

    new_arr = vect_diff(arr, arr_2, n);
    print_arr(new_arr, n);

    free_memory(arr);
    free_memory(arr_2);
    free_memory(new_arr);

    return 0;
}
