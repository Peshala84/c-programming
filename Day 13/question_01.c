#include <stdio.h>
int main()
{
    int i, arr[] = {43, 17, 29, 8, 56, 32, 41};
    printf("Before sort array : ");
    for (i = 0; i < 7; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    int j, temp;
    for (i = 0; i < 7; i++)
    {
        for (j = i + 1; j < 7; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    int k, l;
    for (k = 1; k < 7; k++)
    {
        int c = arr[k];
        l = k - 1;

        while (c > arr[l] && l >= 0)
        {
            arr[l + 1] = arr[l];
            l--;
        }
        arr[l + 1] = c;
    }
    printf("After sort the array : ");
    for (k = 0; k < 7; k++)
    {
        printf("%d\t", arr[k]);
    }
    return 0;
}
