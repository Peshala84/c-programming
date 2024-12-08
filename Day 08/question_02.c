#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    char character;
    struct Node *next;
} Node;

void insertCharacter(Node *head, char ch);
void isSwapInvariant(Node *head);

int main()
{
    Node *word = malloc(sizeof(Node));
    int n, i;
    char ar[100];
    printf("Enter your word : ");
    scanf("%s", ar);
    word->character = ar[0];
    word->next = word;
    n = strlen(ar);
    for (i = 1; i < n; ++i)
    {
        insertCharacter(word, ar[i]);
    }
    isSwapInvariant(word);
    return 0;
}
// To insert char at the end of circLinkedList
void insertCharacter(Node *head, char ch)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = ch;
    Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
}
// swap invarient check function
void isSwapInvariant(Node *head)
{
    if (head == NULL || head->next == head)
    {
        printf("Swap Invariant\n");
        return;
    }
    Node *first = head;
    Node *last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    if (first->character == last->character)
    {
        printf("Swap Invariant\n");
    }
    else
    {
        printf("Not Swap Invariant\n");
    }
}