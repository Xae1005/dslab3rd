#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1, size = 0, maxsize = 0;

void enqueue(int value)
{
    if (rear == maxsize - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        front = rear = -1; 
    }
    else
    {
        printf("Element deleted\n");
        front++;
    }
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return (rear == maxsize - 1);
}

void traverse()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    printf("Enter the size of Queue: ");
    scanf("%d", &maxsize);
    if (maxsize > MAX)
    {
        printf("Exceeds maximum queue size.\n");
        return 1;
    }

    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Queue empty: %s\n", isEmpty() ? "True" : "False");
            break;
        case 4:
            printf("Queue full: %s\n", isFull() ? "True" : "False");
            break;
        case 5:
            traverse();
            break;
        case 6:
            return 0;
        }
    }

    return 0;
}
