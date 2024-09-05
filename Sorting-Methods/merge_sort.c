/*
    DATA STRUCUTURE & ALGORITHM
    SORTING - SELECTION SORT
*/

#include <stdio.h>

void merge(int *arr, int *leftArray, int ls, int *rightArray, int rs)
{
    int i = 0, j = 0, k = 0;
    while (i < ls && j < rs)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < ls)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rs)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int n)
{
    if (n < 2)
        return;

    int ls = n / 2;
    int rs = n - ls;

    int leftArray[ls], rightArray[rs], i;

    for (i = 0; i < ls; i++)
        leftArray[i] = arr[i];
    for (i = ls; i < n; i++)
        rightArray[i - ls] = arr[i];

    mergeSort(leftArray, ls);
    mergeSort(rightArray, rs);
    merge(arr, leftArray, ls, rightArray, rs);
}

int main()
{
    int size;
    printf("Enter Size Of Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter Values In Array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, size);

    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}