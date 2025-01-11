#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(int arr[], int left[], int right[], int leftSize, int rightSize)
{
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n)
{
    if (n > 1)
    {
        int mid = n / 2;
        int left[mid];
        int right[n - mid];

        for (int i = 0; i < mid; i++)
            left[i] = arr[i];

        for (int i = mid; i < n; i++)
            right[i - mid] = arr[i];

        mergeSort(left, mid);
        mergeSort(right, n - mid);

        merge(arr, left, right, mid, n - mid);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {15, 80, 34, 57, 78, 90, 13, 59, 39, 10, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);
    printf("\n");

    quickSort(arr, 0, size - 1);
    printf("After Quick Sort: ");
    printArray(arr, size);
    printf("\n");

    heapSort(arr, size);
    printf("After Heap Sort: ");
    printArray(arr, size);
    printf("\n");
    mergeSort(arr, size);
    printf("Final Sorted Array: ");
    printArray(arr, size);

    return 0;
}
