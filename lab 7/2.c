#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory overflow! Cannot push\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = top;
    printf("%d deleted from Stack\n", top->data);
    top = top->next;
    free(temp);
}

int isEmpty()
{
    return top == NULL;
}

void traverse()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Push\n2. Pop\n3. IsEmpty\n4. Traverse\n5. Exit\n");
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
            traverse();
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}
