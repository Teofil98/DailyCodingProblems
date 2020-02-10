#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//Put all negatives numbers at the beginning of the array and return their count
int sortNegatives(int array[],int size)
{
    int nb = 0;

    for(int i = 0; i < size; i++)
    {
        if(array[i] <= 0)
        {
            swap(&array[i],&array[nb]);
            nb++;
        }
    }

    return nb;
}

int findFirstPositive(int array[], int size)
{

    for(int i = 0; i < size; i++)
    {
        //printf("Element %d on position %d\n",array[i],i);
        if( abs(array[i]) - 1 < size)
            if(array[ abs(array[i]) - 1 ] > 0)
            {
                //printf("Make element %d on position %d negative\n", array[ abs(array[i]) - 1], abs(array[i]) - 1);
                array[ abs(array[i]) - 1] = -array[ abs(array[i]) - 1 ];
            }
    }

    int j = 0;
    while(j < size && array[j] < 0)
    {
        j++;
    }

    return (j + 1);
}

int main()
{
    int n;

    printf("Size of array: ");
    scanf("%d",&n);

    int *array = (int*) malloc(n * sizeof(int));

    printf("Array: ");

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }


    int nbNegatives = sortNegatives(array,n);

    int firstNumber = findFirstPositive(array + nbNegatives, n - nbNegatives);

    printf("First missing positive integer is: %d\n",firstNumber);


    return 0;
}
