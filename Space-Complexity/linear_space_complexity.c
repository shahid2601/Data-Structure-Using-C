/* DATA STRUCTURE & ALGORITHM */

#include <stdio.h>

int sum(int a[], int n)
{
    int i, s = 0;

    printf("Size of Array is %d Bytes\n", sizeof(a) * n);

    for (i = 0; i < n; i++)
    {
        s = s + a[i];
    }

    return s;
}

int main()
{
    int size;
    printf("Enter Size of Array: ");
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int value = sum(arr, size);
    printf("The sum of values in array is %d\n", value);

    return 0;
}