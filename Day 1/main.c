#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,i,n,j;
    int a[100];
    int ok = 0;

    puts("The number k: ");
    scanf("%d",&k);

    puts("The length of the list: ");
    scanf("%d",&n);
    puts("The list: ");
    for(i = 0; i <n; i++)
        scanf("%d",&a[i]);

    for(i = 0; i < n - 1; i++)
    {
        int remainder;
        if(a[i] <= k)
        {
            remainder = k - a[i];
            for(j = i+1; j < n; j++)
            {
                if(a[j] == remainder)
                {
                    ok = 1;
                    goto endLoop;
                }
            }
        }
    }

    endLoop: if(ok == 1)
                puts("TRUE");
              else puts("FALSE");

    return 0;
}
