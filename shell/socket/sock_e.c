#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

struct Socket {
    int fileDescriptor;
};

// Function that creates a Unix socket and binds.
int createUnixSocket(char *path, int port) {
    struct sockaddr s;
    int s_fd;
    int c_fd;
    
    s_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (bind(s_fd, &s, sizeof(struct sockaddr)) == -1) {
        printf("Error: Could not bind to Unix socket.\n");
        exit(EXIT_FAILURE);
    }
    c_fd = connect(s_fd, &s, sizeof(struct sockaddr));
    return c_fd;
}