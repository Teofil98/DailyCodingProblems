#include <stdio.h>
#include <stdlib.h>

int calculateInterpretations(char mapping[], int size)
{
    int interpretations = 0;

    if(size == 0)
        return 0;

    if(size == 1)
        return 1;


    if(mapping[0] <= '2' && mapping[1] <= '6')
        return 2 + calculateInterpretations(mapping + 2, size - 2);

    return 1 + calculateInterpretations(mapping + 1, size - 1);
}

int main()
{
    char *mapping;
    int n;

    printf("Number of characters: ");
    scanf("%d",&n);
    printf("\n");

    mapping = (char*) malloc(sizeof(char) * n);

    printf("Mapping: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%c",&mapping[i]);
    }

    printf("Number of possible interpretations: %d",calculateInterpretations(mapping,n));

    return 0;
}
