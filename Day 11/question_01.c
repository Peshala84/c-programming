#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void createlist(int n);
void reverselist();
void displaylist();
int main()
{
    int n, i;
    printf("Enter size of linked list : ");
    scanf("%d", &n);

    createlist(n);

    reverselist();

    displaylist();

    return 0;
}

void createlist(int n)
{
    struct node *newnode, *temp;
    int num, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory is full");
    }
    else
    {
        printf("Enter node 1 : ");
        scanf("%d", &num);
        head->data = num;
        head->next = NULL;

        temp = head;

        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("memory is full ");
            }
            else
            {
                printf("Enter node %d : ", i);
                scanf("%d", &num);

                newnode->data = num;
                newnode->next = NULL;

                temp->next = newnode;
                temp = temp->next;
            }
        }
    }
}
void reverselist()
{
    struct node *prevnode, *curnode;

    if (head != NULL)
    {
        prevnode = head;
        curnode = head->next;
        head = head->next;

        prevnode->next = NULL;

        while (head != NULL)
        {
            head = head->next;
            curnode->next = prevnode;

            prevnode = curnode;
            curnode = head;
        }
        head = prevnode;
    }
}
void displaylist()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("memory is full");
    }
    else
    {
        temp = head;
        printf("\nThe entered in the list are : ");
        while (temp != NULL)
        {
            printf("data-%d\n", temp->data);
            temp = temp->next;
        }
    }
}
