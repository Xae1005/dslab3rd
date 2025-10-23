#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full!\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("%d deleted from Stack\n", stack[top]);
        top--;
    }
}

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAX - 1);
}

void traverse()
{
    int i;
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack: ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed into the stack: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Stack empty: %s\n", isEmpty() ? "True" : "False");
            break;
        case 4:
            printf("Stack full: %s\n", isFull() ? "True" : "False");
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
