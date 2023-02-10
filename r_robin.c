// round robin scheduling
#include <stdio.h>

struct Process
{
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    int n, i, j, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    struct Process p[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }

    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n)
    {
        for (i = 0; i < n; i++)
        {
            if (p[i].remaining_time > 0)
            {
                if (p[i].remaining_time > quantum)
                {
                    current_time += quantum;
                    p[i].remaining_time -= quantum;
                }
                else
                {
                    current_time += p[i].remaining_time;
                    p[i].waiting_time = current_time - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time = current_time - p[i].arrival_time;
                    p[i].remaining_time = 0;
                    completed_processes++;
                }
            }
        }
    }

    float avg_waiting = 0, sum_waiting = 0;
    float avg_turnaround = 0, sum_turnaround = 0;
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
        sum_waiting += p[i].waiting_time;
        sum_turnaround += p[i].turnaround_time;
    }
    printf("\nAverage Waiting time = %.2f", (sum_waiting / n));
    printf("\nAverage Turnaround time = %.2f\n", (sum_turnaround / n));
    return 0;
}