#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

// A very simple copy command.
int main(int argc, char *argv[]) {
    // Define the inpit file-descriptor, output file-descriptor
    // and the flags supplied to the command.
    int inputFD, outputFD, openFlags;
    mode_t filePerm;
    ssize_t numRead;
    char buf[BUF_SIZE];
    // Check to see if enough arguments have been given to the program.
    if (argc != 3 || strcmp(argv[1] == "--help")) {
        printf("cp <source> <destination>\n");
        exit(EXIT_FAILURE);
    }
    // Open the input file-descriptor.
    inputFD = open(argv[1], O_RDONLY);
    if (inputFD == -1) {
        printf("Error: Could not open input file.");
        exit(EXIT_FAILURE);
    }
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
               S_IROTH | S_IWOTH;
    // Open the output file-descriptor.
    outputFD = open(argv[2], openFlags, filePerm);
    if (outputFD == -1) {
        printf("Error: Could not open input file.");
        exit(EXIT_FAILURE);
    }
    // Transfer data until error is encountered or data is done.
    while
}