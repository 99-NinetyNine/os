// A program in C for scheduling using priority scheduling
#include <stdio.h>

struct Process
{
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].pid = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].priority > p[j + 1].priority)
            {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    float avg_waiting = 0, sum_waiting = 0;
    float avg_turnaround = 0, sum_turnaround = 0;

    for (i = 0; i < n; i++)
    {
        current_time += p[i].burst_time;
        p[i].waiting_time = current_time - p[i].arrival_time - p[i].burst_time;
        p[i].turnaround_time = current_time - p[i].arrival_time;
        sum_waiting += p[i].waiting_time;
        sum_turnaround += p[i].turnaround_time;
    }

    printf("Process ID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("\nAverage Waiting time = %.2f", (sum_waiting / n));
    printf("\nAverage Turnaround time = %.2f\n", (sum_turnaround / n));
    return 0;
}