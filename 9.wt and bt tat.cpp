#include <stdio.h>
int main() {
    int processes[][2] = {{0, 2}, {1, 4}, {2, 8}};
    int num_processes = sizeof(processes) / sizeof(processes[0]);
    int waiting_times[num_processes]; 
    int turnaround_times[num_processes];
    int current_time = 0;  
    for (int i = 0; i < num_processes; i++) {
        waiting_times[i] = current_time; 
        current_time += processes[i][1]; 
        turnaround_times[i] = current_time; 
    }
    float average_waiting_time = 0.0; 
    float average_turnaround_time = 0.0; 
    for (int i = 0; i < num_processes; i++) {
        average_waiting_time += waiting_times[i]; 
        average_turnaround_time += turnaround_times[i];
    }
    average_waiting_time /= num_processes;  
    average_turnaround_time /= num_processes; 

    printf("Average waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);

    return 0;
}
