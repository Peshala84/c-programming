#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Node
{
    char character;
    struct Node *prev;
    struct Node *next;
} Node;

void insertCharacter(Node *head, char ch);
bool isPalindrome(Node *head);

int main()
{
    Node *word = (Node *)malloc(sizeof(Node));
    int n, i;
    char ar[100];
    printf("Type your word : ");
    scanf("%s", ar);
    word->character = ar[0];
    word->prev = NULL;
    word->next = NULL;
    n = strlen(ar);
    for (i = 1; i < n; ++i)
    {
        insertCharacter(word, ar[i]);
    }
    if (isPalindrome(word))
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a Palindrome\n");
    }
    return 0;
}
// Character insertion function
void insertCharacter(Node *head, char ch)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = ch;
    newNode->next = NULL;

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Palindrome check function
bool isPalindrome(Node *head)
{
    Node *start = head;
    Node *end = head;
    // finding end of DoLinkList
    while (end->next != NULL)
    {
        end = end->next;
    }
    // compare characters from start to end
    while (start != end && start->prev != end)
    {
        if (start->character != end->character)
        {
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}