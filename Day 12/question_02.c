#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int maxindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxindex])
            {
                maxindex = j;
            }
        }
        if (i != maxindex)
        {
            int temp = arr[i];
            arr[i] = arr[maxindex];
            arr[maxindex] = temp;
        }
    }
}

void merge(int arr[], int left[], int right[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] >= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}
void mergeSort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int mid = n / 2, left[mid], right[n - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i + mid];
    }

    for (int i = 0; i < n - mid; i++)
    {
        right[i] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);

    merge(arr, left, right, mid, n - mid);
}
int main()
{
    int arr[] = {46, 52, 71, 8, 32, 65};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n / 2);

    mergeSort(arr + n / 2, n - n / 2);

    merge(arr, arr, arr + n / 2, n / 2, n - n / 2);

    printf("******************************************************\n: ");
    printf("sorted array in descending order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}