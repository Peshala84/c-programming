#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
int top = -1;
char stack[MAX_SIZE];
char str[100];

bool isEmpty()
{
    return top == -1;
}
bool isFull()
{
    return top == MAX_SIZE - 1;
}

void push(char a)
{
    if (isFull())
    {
        printf("Stack overflow error!");
    }
    else
    {
        stack[++top] = str[top];
    }
}
char pop()
{
    if (isEmpty())
    {
        printf("Stack underflow error!");
    }
    else
    {
        return stack[top--];
    }
}
char peek()
{
    if (isEmpty())
    {
        printf("Stack is empty!");
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    int i;
    char str[] = "abcde";
    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }
    printf("String pused to stack: %s\n", str);
}