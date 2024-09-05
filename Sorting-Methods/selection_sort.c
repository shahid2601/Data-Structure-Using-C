/*
    DATA STRUCUTURE & ALGORITHM
    SORTING - SELECTION SORT
*/

#include <stdio.h>

int main()
{
    int i, j, n, m, loc, temp;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Values In Array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        m = arr[i];
        loc = i + 1;
        for (j = i + 1; j < n; j++)
        {
            if (m > arr[j])
            {
                m = arr[j];
                loc = j;
            }
        }
        if (arr[loc] < arr[i])
        {
            temp = arr[loc];
            arr[loc] = arr[i];
            arr[i] = temp;
        }
    }

    printf("Sorted Elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}