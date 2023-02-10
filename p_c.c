

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
int buffer[MAX_ITEMS];
int empty, full = 0, mutex = 1; // Semaphores
int item, itemC, n;
int in = 0, out = 0;

int wait(int s)
{
    return --s;
}

int signal(int s)
{
    return ++s;
}

void producer()
{
    mutex = wait(mutex);
    empty = wait(empty);
    full = signal(full);
    printf("Enter an item: ");
    scanf("%d", &item);
    buffer[in] = item;
    in = (in + 1) % n;
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    itemC = buffer[out];
    printf("Consumed item = %d \n", itemC);
    out = (out + 1) % n;
    mutex = signal(mutex);
}

int main()
{
    printf("Enter the value of n: ");
    scanf("%d", &n);
    empty = n;

    int choice;
    printf("\nChoices: \n1. Producer \n2. Consumer \n3. Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (mutex == 1 && empty != 0)
                producer();
            else
                printf("Buffer is full \n");
            break;
        case 2:
            if (mutex == 1 && full != 0)
                consumer();
            else
                printf("Buffer is empty \n");
            break;
        default:
            exit(0);
            break;
        }
    }
}