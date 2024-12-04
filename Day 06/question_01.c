
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

struct Stack
{
    char names[MAX_SIZE][50];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char *name)
{
    if (isFull(stack))
    {
        printf("Stack overflow!");
        printf("\n");
        return;
    }
    strcpy(stack->names[++stack->top], name);
}

void popDisplay(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!");
        printf("\n");
        return;
    }
    printf("\n\n   Names with marks greater than 70:\n");
    while (!isEmpty(stack))
    {
        printf("     ");
        printf("%s", stack->names[stack->top--]);
    }
}

int main()
{
    char names[][20] = {"Sanduni", "Kasun", "Vihaga", "Khushi", "Ravindi"};
    int marks[] = {68, 88, 90, 50, 95};
    int a;
    printf("ALL STUDENTS");
    printf("\n");

    for (a = 0; a < MAX_SIZE; a++)
    {
        printf("%s\t", names[a]);
    }
    printf("\n");

    struct Stack stack;
    initialize(&stack);

    for (a = 0; a < MAX_SIZE; a++)
    {
        if (marks[a] > 70)
        {
            push(&stack, names[a]);
        }
    }
    printf("\n");
    popDisplay(&stack);
    return 0;
}
