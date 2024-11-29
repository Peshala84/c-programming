
#include <stdio.h>
int main()
{
    int i, element, x, array[] = {20, 40, 4, 55, 30};
    printf("Enter element to delete\n");
    scanf("%d", &element);
    for (i = 0; i < 5; i++)
    {
        if (array[i] == element)
        {
            x = i;
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (i >= x)
        {
            array[i] = array[i + 1];
        }
    }
    printf("New Array:");
    for (i = 0; i < 4; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
    return 0;
}
