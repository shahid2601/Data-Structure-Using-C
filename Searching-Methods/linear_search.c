/*
    DATA STRUCTURE & ALGORITHM
    SEARCHING - LINEAR SEARCH
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item, i = 0;
    int arr[6] = {29, 74, 96, 48, 16, 67}; // CREATED AN ARRAY OVER HERE
    printf("Enter Searching Value: "); // DISPLAYED A MESSAGE TO TAKE INPUT
    scanf("%d", &item); // TAKING INPUT FROM THE USER

    while (i<6) // USING WHILE LOOP WITH IF ELSE CONDITION TO FIND THE ELEMENT USING LINEAR SEARCH
    {
        if (arr[i] == item)
        {
            printf("Item Found At Position %d", i);
            exit(0);
        }
        i++;
    }
    if (i >= 6)
    {
        printf("Item Not Found", i);
        exit(0);
    }
    
    return 0;
}