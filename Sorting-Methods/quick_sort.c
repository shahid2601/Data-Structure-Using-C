/*
    DATA STRUCUTURE & ALGORITHM
    SORTING - SELECTION SORT
*/

#include <stdio.h>

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1, temp;
        for (int j = low; j <= high - 1; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;
        quickSort(a, low, i);
        quickSort(a, i + 2, high);
    }
}

int main()
{
    int i, j, n, low, high, pivot, temp;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Values In Array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}