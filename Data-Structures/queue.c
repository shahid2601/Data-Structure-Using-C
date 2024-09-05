#include <stdio.h>

#define MAX_SIZE 3
int queue[MAX_SIZE];
int front = -1, rear = -1;

int main()
{
    int choice, item;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while (1)
    {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (rear == MAX_SIZE - 1)
            {
                printf("Overflow\n");
            }
            else
            {
                printf("Enter The Element: ");
                scanf("%d", &item);

                if (front == -1)
                {
                    front = rear = 0;
                }
                else
                {
                    rear++;
                }
                queue[rear] = item;
                printf("Item Inserted...\n");
            }
            break;
        case 2:
            if (front == -1)
            {
                printf("Underflow\n");
            }
            else
            {
                item = queue[front];
                if (front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front++;
                }
                printf("Item Deleted: %d", item);
            }
            printf("\n");
            break;
        case 3:
            if (front == -1)
            {
                printf("Queue Is Empty\n");
            }
            else
            {
                printf("Queue Elements: ");
                for (int i = front; i <= rear; i++)
                {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
            break;
        case 4:
            printf("Exit\n");
            return 0;

        default:
            printf("Invalid Choice...");
        }
    }

    return 0;
}