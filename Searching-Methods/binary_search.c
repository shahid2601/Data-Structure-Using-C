/*
    DATA STRUCTURE & ALGORITHM
    SEARCHING - BINARY SEARCH
*/

#include <stdio.h>

int main()
{
    int lr = 0, up = 5, mid, f = 0, item; // LR - LOWER/ LEFT PART, UP - UPPER/ RIGHT PART, MID - MIDDLE VALUE AFTER DIVIDED LR + UP BY 2
    int arr[6] = {10, 20, 30, 40, 50, 60}; // CREATED AN ARRAY OVER HERE
    printf("Enter Searching Element: "); // DISPLAYED A MESSAGE TO TAKE INPUT
    scanf("%d", &item); // TAKING INPUT FROM THE USER

    while (lr <= up) // USING WHILE LOOP WITH IF ELSE CONDITION TO FIND THE ELEMENT USING BINARY SEARCH
    {
        mid = (lr + up) / 2;
        if (arr[mid] == item)
        {
            f = 1; break;
        }
        if (arr[mid] < item)
        {
            lr = mid + 1;
        } else
        {
            up = mid - 1;
        }
    }
    if (f == 1)
    {
        printf("Item Found At %d", mid);
    } else
    {
        printf("Item Not Found");
    }
    
    return 0;
}