#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    scanf("%d\n", &n);
    int num[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < n; i++)
    {
        sum = sum + num[i];
    }
    printf("%d\n", sum);
}
