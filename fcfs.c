// A program in C for Scheduling algorithm using First Come First Serve
#include <stdio.h>

struct Process
{
    int pid;
    int burst_time;
    int arrival_time;
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
        p[i].pid = i + 1;
    }

    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    float total_waiting = 0, avg_waiting_time;
    float total_turnaround_time = 0, avg_turnaround_time;
    for (i = 1; i < n; i++)
    {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average waiting time = %f.\nAverage turnaround time = %f.\n", total_waiting / n, (total_turnaround_time + p[0].turnaround_time) / n);

    return 0;
}