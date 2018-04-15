#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int c_succ;
    // Check if input is correct.
    if (argc != 2) {
        printf("chroot <root>\n");
        exit(EXIT_FAILURE);
    }
    // Chroot and check if successful.
    if ((c_succ = chroot(argv[1])) == -1) {
        printf("Error: Change root failed.\n");
        exit(EXIT_FAILURE);
    }
    // Fork a process in the t
    exit(EXIT_SUCCESS);
}