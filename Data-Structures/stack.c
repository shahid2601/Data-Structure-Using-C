#include <stdio.h>

#define MAX_SIZE 5
int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Overflow!!\n");
    }
    else
    {
        stack[++top] = item;
        printf("Item Inserted.\n", item);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow!!\n");
    }
    else
    {
        int item = stack[top--];
        printf("Item Deleted.\n", item);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack Is Empty!!\n");
    }
    else
    {
        printf("Stack Elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, item;
    printf("1. Push\n2. Pop\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value To Push: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;
            break;

        default:
            printf("Invalid Choice!!\n");
        }
    }

    return 0;
}