#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int n, int bt[], int wt[], int prio[]) {
    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculating waiting time for each process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to sort processes by priority and calculate average time
void findAvgTime(int processes[], int n, int bt[], int prio[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Sorting processes based on priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prio[i] > prio[j]) {
                // Swap priority
                int tempPrio = prio[i];
                prio[i] = prio[j];
                prio[j] = tempPrio;

                // Swap burst time
                int tempBt = bt[i];
                bt[i] = bt[j];
                bt[j] = tempBt;

                // Swap process numbers
                int tempProc = processes[i];
                processes[i] = processes[j];
                processes[j] = tempProc;
            }
        }
    }

    findWaitingTime(n, bt, wt, prio);
    findTurnAroundTime(n, bt, wt, tat);

    // Display processes along with all details
    printf("Processes\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], prio[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {10, 5, 8};
    int priority[] = {2, 1, 3};  // Priority of processes

    findAvgTime(processes, n, burst_time, priority);

    return 0;
}
