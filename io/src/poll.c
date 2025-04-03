#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <unistd.h>

#define TIMEOUT 5000 // 5 seconds

int main() {
    // Set up the pollfd structure to monitor stdin
    struct pollfd fds[1];
    fds[0].fd = fileno(stdin); // File descriptor for standard input
    fds[0].events = POLLIN;    // Monitor for input readiness

    printf("Waiting for input (poll)...\n");

    while (1)
    {
        // Wait for events with a timeout
        int ret = poll(fds, 1, TIMEOUT);
        if (ret == -1) {
            perror("poll"); // Handle error
            exit(EXIT_FAILURE);
        } else if (ret == 0) {
            printf("Timeout occurred! No data within 5 seconds.\n");
        } else {
            // Check if stdin is ready for reading
            if (fds[0].revents & POLLIN) {
                char buffer[1024];
                ssize_t bytes = read(fds[0].fd, buffer, sizeof(buffer) - 1);
                if (bytes > 0) {
                    buffer[bytes] = '\0';
                    printf("Read: %s", buffer);
                }
            }
        }
    }
    
    return 0;
}
