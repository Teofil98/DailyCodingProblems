#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,inArray[100], outArray[100], product = 1;

    fputs("Number of elements in array: ",stdout);
    scanf("%d",&n);

    fputs("The elements of the array: ",stdout);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&inArray[i]);
        product *= inArray[i];
    }

    for(int i = 0; i < n; i++)
        outArray[i] = product/inArray[i];

    fputs("The output array is: ",stdout);
    for(int i = 0; i < n; i++)
        printf("%d ",outArray[i]);



    return 0;
}
