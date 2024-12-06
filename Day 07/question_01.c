#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int stdId;
    char name[16];
    float gpa;
    struct student *next;
} student;

int deleteStudent();
student *listToArray();
void printList();
void printArray();

void addStudent(student **head, int stdId, const char *name, float gpa)
{
    student *newStudent = (student *)malloc(sizeof(student));
    newStudent->stdId = stdId;
    strncpy(newStudent->name, name, 15);
    newStudent->name[15] = '\0';
    newStudent->gpa = gpa;
    newStudent->next = NULL;

    if (*head == NULL)
    {
        *head = newStudent;
        return;
    }

    if (stdId < (*head)->stdId)
    {
        newStudent->next = *head;
        *head = newStudent;
        return;
    }

    student *current = *head;
    while (current->next != NULL && current->next->stdId < stdId)
    {
        current = current->next;
    }

    newStudent->next = current->next;
    current->next = newStudent;
}

int main()
{
    student *head = NULL;
    addStudent(&head, 1, "Alice", 3.9);
    addStudent(&head, 2, "Bob", 3.7);
    addStudent(&head, 3, "Charlie", 3.5);
    addStudent(&head, 4, "David", 3.6);
    addStudent(&head, 5, "Eva", 3.8);
    addStudent(&head, 6, "Frank", 3.1);
    addStudent(&head, 7, "Grace", 3.4);
    addStudent(&head, 8, "Hank", 3.3);
    addStudent(&head, 9, "Ivy", 3.2);
    addStudent(&head, 10, "Jack", 3.0);

    printf("List after adding:\n");
    printList(head);

    printf("Delete the 1st Student in the list:\n");
    deleteStudent(&head, 1);
    printList(head);

    printf("Delete the Student with the ID: 5 from the list:\n");
    deleteStudent(&head, 5);
    printList(head);

    printf("Delete the last Student from the list:\n");
    deleteStudent(&head, 10);
    printList(head);

    printf("Delete Student: ID 11\n");
    int status = deleteStudent(&head, 11);
    if (status)
    {
        printf("Status: Success\n");
    }
    else
    {
        printf("Status: Failure, student not found.\n");
    }
    printf("\n");

    printf("List to Array:\n");
    student *array = listToArray(head);
    printArray(array, 7);

    free(array);

    return 0;
}

int deleteStudent(student **head, int stdId)
{
    if (*head == NULL)
    {
        return 0;
    }
    if ((*head)->stdId == stdId)
    {
        student *temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }
    student *current = *head;
    while (current->next != NULL && current->next->stdId != stdId)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        return 0;
    }
    student *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return 1;
}
student *listToArray(student *head)
{
    int count = 0;
    student *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    student *array = (student *)malloc(count * sizeof(student));

    current = head;
    for (int i = 0; i < count; i++)
    {
        array[i] = *current;
        current = current->next;
    }
    return array;
}
void printList(student *head)
{
    student *current = head;
    while (current != NULL)
    {
        printf("ID: %d, Name: %s, GPA: %.1f\n", current->stdId, current->name, current->gpa);
        current = current->next;
    }
    printf("\n");
}
void printArray(student *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] -> ID: %d, Name: %s, GPA: %.1f\n", i, array[i].stdId, array[i].name, array[i].gpa);
    }
    printf("\n");
}
