#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int d)
{
    clock_t startTime = clock();

    while(clock() - startTime < d);
}

void printKenobi()
{
    printf("Hello there!\n");
}

void printGrievous()
{
    printf("General Kenobi!\n");
}

void schedule(void (*f)(),int n)
{
    delay(n);
    f();
}

int main()
{
    schedule(printKenobi,2000);
    schedule(printGrievous,1000);
    return 0;
}
