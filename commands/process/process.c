#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[], char *envp[]) {
    int p_succ;
    
    // Check the execve() call to see if it ran successfully.
    if((p_succ = execve(argv[1], NULL, NULL) != 0)) {
        printf("Error: Could not run %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    free(p_succ);
    exit(EXIT_SUCCESS);
}