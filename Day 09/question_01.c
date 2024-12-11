#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char username[30];
    int age;
    int followers;
    int height;
    struct node *left, *right;
};

typedef struct node Node;

Node *getnode(char username[], int age, int followers)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    strcpy(newnode->username, username);
    newnode->age = age;
    newnode->followers = followers;
    newnode->height = 1;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int getBalance(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return height(root->left) - height(root->right);
    }
}

Node *rotateRight(Node *ptr1)
{
    Node *ptr2 = ptr1->left;
    Node *ptr3 = ptr2->right;

    ptr2->right = ptr1;
    ptr1->left = ptr3;

    ptr1->height = max(height(ptr1->left), height(ptr1->right)) + 1;
    ptr2->height = max(height(ptr2->left), height(ptr2->right)) + 1;

    return ptr2;
}

Node *rotateLeft(Node *ptr2)
{
    Node *ptr1 = ptr2->right;
    Node *ptr3 = ptr1->left;

    ptr1->left = ptr2;
    ptr2->right = ptr3;

    ptr2->height = max(height(ptr2->left), height(ptr2->right)) + 1;
    ptr1->height = max(height(ptr1->left), height(ptr1->right)) + 1;

    return ptr1;
}

Node *insert(Node *root, char username[], int age, int followers)
{
    if (root == NULL)
    {
        return getnode(username, age, followers);
    }
    else
    {
        if (root->followers > followers)
        {
            root->left = insert(root->left, username, age, followers);
        }
        else if (root->followers < followers)
        {
            root->right = insert(root->right, username, age, followers);
        }
        else
        {
            return root;
        }

        root->height = max(height(root->left), height(root->right)) + 1;

        int balance = getBalance(root);

        if (balance > 1 && followers < root->left->followers)
        {
            return rotateRight(root);
        }
        if (balance > 1 && followers > root->left->followers)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if (balance < -1 && followers > root->right->followers)
        {
            return rotateLeft(root);
        }
        if (balance < -1 && followers < root->right->followers)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        return root;
    }
}

Node *findMin(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}

Node *Delete_node(Node *root, int followers)
{
    if (root == NULL)
    {
        return root;
    }

    if (followers < root->followers)
    {
        root->left = Delete_node(root->left, followers);
    }
    else if (followers > root->followers)
    {
        root->right = Delete_node(root->right, followers);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMin(root->right);
        root->followers = temp->followers;
        strcpy(root->username, temp->username);
        root->age = temp->age;
        root->right = Delete_node(root->right, temp->followers);
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && followers < root->left->followers)
    {
        return rotateRight(root);
    }
    if (balance > 1 && followers > root->left->followers)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && followers > root->right->followers)
    {
        return rotateLeft(root);
    }
    if (balance < -1 && followers < root->right->followers)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void InOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        InOrderTraversal(root->left);
        printf("Name: %s, Age: %d, Followers: %d\n", root->username, root->age, root->followers);
        InOrderTraversal(root->right);
    }
}

void freeNode(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        freeNode(root->left);
        freeNode(root->right);
        free(root);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, "Alice", 25, 1000);
    root = insert(root, "Bob", 30, 500);
    root = insert(root, "Charlie", 22, 750);
    root = insert(root, "David", 28, 800);
    root = insert(root, "Eve", 29, 1200);

    printf("AVL Tree:\n");
    InOrderTraversal(root);

    root = Delete_node(root, 750);

    printf("\nAVL Tree after deletion:\n");
    InOrderTraversal(root);

    freeNode(root);
    return 0;
}
