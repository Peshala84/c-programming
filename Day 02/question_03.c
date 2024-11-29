#include <stdio.h>

int main()
{
    int m = 40, n = 30, o = 20, p = 10;
    int a;

    a = (m > n && m != 0);
    printf("\n %d > %d && %d != 0 is %d", m, n, m, a);

    a = (o > p || p != 20);
    printf("\n %d > %d || %d != 20 is %d", o, p, p, a);

    a = !(m > n && m != 0);
    printf("\n !(%d > %d && %d != 0) is %d", m, n, m, a);

    return 0;
}