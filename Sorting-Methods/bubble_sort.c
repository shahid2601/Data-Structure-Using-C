/*
    DATA STRUCUTURE & ALGORITHM
    SORTING - BUBBLE SORT
*/

#include <stdio.h>

int main()
{
    int n, temp;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter The Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted Elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}