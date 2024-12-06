#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Train
{
    int trainId;
    char destination[50];
    struct Train *next;
} Train;

void addTrain(Train **schedule, int trainId, const char *destination)
{
    Train *newTrain = (Train *)malloc(sizeof(Train));
    newTrain->trainId = trainId;
    strncpy(newTrain->destination, destination, 49);
    newTrain->destination[49] = '\0';
    newTrain->next = NULL;

    if (*schedule == NULL)
    {
        *schedule = newTrain;
        return;
    }

    Train *current = *schedule;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newTrain;
}

Train *departTrain(Train **schedule)
{

    if (*schedule == NULL)
    {
        return NULL;
    }

    Train *departedTrain = *schedule;
    *schedule = (*schedule)->next;
    departedTrain->next = NULL;

    return departedTrain;
}

Train *nextTrain(Train *schedule)
{

    if (schedule == NULL)
    {
        return NULL;
    }

    return schedule;
}

void printSchedule(Train *schedule)
{
    Train *current = schedule;
    while (current != NULL)
    {
        printf("ID: %d, Destination: %s\n", current->trainId, current->destination);
        current = current->next;
    }
    printf("\n");
}

int main()
{

    Train *schedule = NULL;

    addTrain(&schedule, 101, "New York");
    addTrain(&schedule, 102, "Los Angeles");
    addTrain(&schedule, 103, "Chicago");

    printf("Current Schedule:\n");
    printSchedule(schedule);

    Train *departedTrain = departTrain(&schedule);
    while (departedTrain != NULL)
    {
        printf("Departing train: ID = %d, Destination = %s\n", departedTrain->trainId, departedTrain->destination);
        free(departedTrain);
        departedTrain = departTrain(&schedule);
    }

    printf("Current Schedule:\n");
    printSchedule(schedule);

    Train *next = nextTrain(schedule);
    if (next != NULL)
    {
        printf("The next train is: ID = %d, Destination = %s\n", next->trainId, next->destination);
    }
    else
    {
        printf("No trains in the schedule.\n");
    }

    return 0;
}