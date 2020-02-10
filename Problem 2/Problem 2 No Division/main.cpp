#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,inArray[100], outArray[100], product, left[100],right[100];

    fputs("Number of elements in array: ",stdout);
    scanf("%d",&n);

    fputs("The elements of the array: ",stdout);
    for(int i = 0; i < n; i++)
        scanf("%d",&inArray[i]);

    product = 1;
    left[0] = product;
    for(int i = 0; i < n - 1; i++)
    {
        product *= inArray[i];
        left[i+1] = product;
    }

    product = 1;
    right[n-1] = product;
    for(int i = n-1; i > 0; i--)
    {
        product *= inArray[i];
        right[i-1] = product;
    }

    for(int i = 0; i < n; i++)
        outArray[i] = left[i] * right[i];

    fputs("The output array is: ",stdout);
    for(int i = 0; i < n; i++)
        printf("%d ",outArray[i]);


    return 0;
}
