#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_EVENTS 10

int main() {
    // Create an epoll instance
    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    // Register stdin (standard input) for monitoring
    int stdin_fd = fileno(stdin);
    struct epoll_event event;
    event.events = EPOLLIN; // Monitor for input readiness
    event.data.fd = stdin_fd;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, stdin_fd, &event) == -1) {
        perror("epoll_ctl");
        close(epoll_fd);
        exit(EXIT_FAILURE);
    }

    // Buffer to store events
    struct epoll_event events[MAX_EVENTS];
    printf("Waiting for input (epoll)...\n");

    while (1) {
        // Wait for events on the monitored file descriptors
        int n = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (n == -1) {
            perror("epoll_wait");
            break;
        }

        // Process each triggered event
        for (int i = 0; i < n; i++) {
            if (events[i].events & EPOLLIN) {
                char buffer[1024];
                ssize_t bytes = read(events[i].data.fd, buffer, sizeof(buffer) - 1);
                if (bytes > 0) {
                    buffer[bytes] = '\0';
                    printf("Read: %s", buffer);
                }
            }
        }
    }

    // Clean up resources
    close(epoll_fd);
    return 0;
}
