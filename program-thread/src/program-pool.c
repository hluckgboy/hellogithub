#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define PROCESS_POOL_SIZE 4 // Define the number of processes in the process pool

// Example task function
void exampleTask(int taskId) {
    printf("Task %d is being processed by process %d\n", taskId, getpid());
    sleep(1); // Simulate task processing time
}

// Worker process function
void workerProcess(int readPipe) {
    int taskId;
    while (read(readPipe, &taskId, sizeof(taskId)) > 0) {
        exampleTask(taskId);
    }
    exit(0); // Exit when no more tasks are available
}

// Function to add a task to the process pool
void addTask(int taskId, int pipes[][2]) {
    int processIndex = taskId % PROCESS_POOL_SIZE; // Distribute tasks among processes
    write(pipes[processIndex][1], &taskId, sizeof(taskId));
}

// Function to delete a task (not applicable in this simple example as tasks are processed immediately)
// Placeholder for future implementation if task queueing is added

// Function to destroy the process pool
void destroyProcessPool(int pipes[][2], pid_t pids[]) {
    // Close all write ends to signal workers to exit
    for (int i = 0; i < PROCESS_POOL_SIZE; i++) {
        close(pipes[i][1]);
    }

    // Wait for all worker processes to finish
    for (int i = 0; i < PROCESS_POOL_SIZE; i++) {
        waitpid(pids[i], NULL, 0);
    }

    printf("Process pool destroyed.\n");
}

int main() {
    int pipes[PROCESS_POOL_SIZE][2]; // Pipes for communication with worker processes
    pid_t pids[PROCESS_POOL_SIZE];   // Array to store process IDs

    // Create the process pool
    for (int i = 0; i < PROCESS_POOL_SIZE; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(1);
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process: close the write end and start the worker
            close(pipes[i][1]);
            workerProcess(pipes[i][0]);
        } else {
            // Parent process: close the read end and store the child PID
            close(pipes[i][0]);
            pids[i] = pid;
        }
    }

    // Submit tasks to the process pool
    for (int i = 0; i < 10; i++) {
        addTask(i, pipes);
    }

    // Destroy the process pool
    destroyProcessPool(pipes, pids);

    return 0;
}
