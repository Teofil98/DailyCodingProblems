#include <stdio.h>
#include <stdlib.h>

int sum(int array[], int size)
{
    int sum_including_prev = array[0];
    int sum_excluding_prev = 0;
    int sum_excluding_current;
    int sum_including_current;

    int i;
    for(i = 1; i < size; i++)
    {
        sum_excluding_current = (sum_excluding_prev > sum_including_prev) ? sum_excluding_prev : sum_including_prev;
        sum_including_current = array[i] + sum_excluding_prev;

        sum_excluding_prev = sum_excluding_current;
        sum_including_prev = sum_including_current;
    }

    return ((sum_including_current > sum_excluding_current) ? sum_including_current : sum_excluding_current);
}

int main()
{
    int n;
    int* array;

    printf("Size of array: ");
    scanf("%d",&n);

    array = (int*) malloc(sizeof(int) * n);



    printf("Array: ");

    int i;
    for(i = 0; i < n; i++)
        scanf("%d",&array[i]);

    printf("Maximum sum: %d",sum(array,n));

    return 0;
}
