#include <stdio.h>

// Function to find waiting time of all processes
void findWaitingTime(int n, int bt[], int wt[], int quantum) {
    int rem_bt[n];  // Remaining burst time of each process
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    int t = 0; // Current time

    // Keep traversing processes in round robin manner until all of them are done
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findAvgTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(n, bt, wt, quantum);

    findTurnAroundTime(n, bt, wt, tat);

    // Display processes along with all details
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {24, 3, 3};
    int quantum = 4;

    findAvgTime(processes, n, burst_time, quantum);

    return 0;
}
