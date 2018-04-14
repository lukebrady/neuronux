#include <stdio.h>
#include <stdlib.h>
// A very simple copy command.
int main(int argc, char *argv[]) {
    // Check to see if enough arguments have been given to the program.
    if (argc != 3) {
        printf("Error: cp <source> <destination>\n");
        exit(EXIT_FAILURE);
    }


}