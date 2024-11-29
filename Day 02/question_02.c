#include <stdio.h>

int main()
{
    int a = 1;

    printf("\n a) %d", a);
    printf("\n b) %d", a++);
    printf("\n c) %d", a);
    printf("\n d) %d", ++a);
    printf("\n e) %d", a);
    printf("\n f) %d", a--);
    printf("\n g) %d", a);
    printf("\n h) %d", --a);
    printf("\n i) %d", a);

    return 0;
}