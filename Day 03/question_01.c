#include <stdio.h>

int main()
{
    int size, i;
    printf("Read n number of values in an array and display it in reverse oder:\n");
    printf("-----------------------------------------------------------------------");
    printf("\nInput the number of elements to store in the array :");
    scanf("%d", &size);
    printf("Input %d  number of elements in the array:\n", size);
    int numbers[size];
    for (i = 0; i < size; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &numbers[i]);
    }
    printf("\n\n The values store into the array are :\n");
    for (i = 0; i < size; i++)
    {
        printf("   %d", numbers[i]);
    }
    int reverse[size];
    printf("\n\n The values store into the array in reverse are :\n");
    for (i = size - 1; i >= 0; i--)
    {
        printf("   %d", numbers[i]);
    }
    printf("\n");
}