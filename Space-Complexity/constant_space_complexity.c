/* DATA STRUCTURE & ALGORITHM */

#include <stdio.h>

int square(int n)
{
    printf("%d Bytes\n", sizeof(int));
    printf("%d Bytes\n", sizeof(n));
    return n*n;
}

int main()
{
    int num;
    printf("Enter a Number: ");
    scanf("%d", &num);
    int value = square(num);
    printf("%d\n", value);

    return 0;
}