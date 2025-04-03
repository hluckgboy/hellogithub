#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

#define TIMEOUT 5 // 5 seconds

int main() {
    // Initialize the file descriptor set
    fd_set readfds;
    struct timeval tv; // Timeout structure
    int stdin_fd = fileno(stdin); // File descriptor for standard input

    FD_ZERO(&readfds);           // Clear the set
    FD_SET(stdin_fd, &readfds);  // Add stdin to the set

    // Set the timeout value
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    printf("Waiting for input (select)...\n");

    // Wait for events on the monitored file descriptors
    while(1){
        int ret = select(stdin_fd + 1, &readfds, NULL, NULL, &tv);
        if (ret == -1) {
            perror("select"); // Handle error
            exit(EXIT_FAILURE);
        } else if (ret == 0) {
            printf("Timeout occurred! No data within 5 seconds.\n");
        } else {
            // Check if stdin is ready for reading
            if (FD_ISSET(stdin_fd, &readfds)) {
                char buffer[1024];
                ssize_t bytes = read(stdin_fd, buffer, sizeof(buffer) - 1);
                if (bytes > 0) {
                    buffer[bytes] = '\0';
                    printf("Read: %s", buffer);
                }
            }
        }
    }
    return 0;
}
