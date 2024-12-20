#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;
void createlist(int n);
void displaylist();

int main()
{
    int n;
    printf("Enter number of size : ");
    scanf("%d", &n);

    createlist(n);

    displaylist();
    return 0;
}
void createlist(int n)
{

    int i, num;
    struct node *temp, *newnode;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory can't be allocated ");
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
            newnode == (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("memory can't be allocated");
                break;
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
void displaylist()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("memory is allocated ");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("data = %d\t ", temp->data);
            temp = temp->next;
        }
    }
}
