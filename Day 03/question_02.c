
#include <stdio.h>
int main()
{
    printf("copy the number one array to another array :\n");
    printf("-----------------------------------------------------");
    int i, size;
    int array1[size];
    printf("\nInput the number of elements to be stored in the array :");
    scanf("%d", &size);
    printf("Input %d elements in the array :\n", size);
    for (i = 0; i < size; i++)
    {
        printf("element - %d :", i);
        scanf("%d", &array1[i]);
    }
    printf("The elements stored in the first array are :\n");
    for (i = 0; i < size; i++)
    {
        printf(" %d", array1[i]);
    }
    int array2[size];
    for (i = 0; i < size; i++)
    {
        array2[i] = array1[i];
    }
    printf("\n\n The elements copied into the second array are :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", array2[i]);
    }
    printf("\n");
    return 0;
}
