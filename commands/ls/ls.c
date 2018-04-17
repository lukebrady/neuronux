#include "stdio.h"
#include "dirent.h"
#include "unistd.h"

int main(int argc, char *argv[]) {
    DIR     *dp;
    struct dirent   *dirp;
    // First, check to see if an appropriate number of args have been supplied.
    if (argc != 2) {
        printf("Error: No directory supplied.\n");
        exit(1);
    }
    // Check to see if the supplied directory can be opened.
    if ((dp == opendir(argv[1])) == NULL) {
        printf("Error: Cannot open %s\n", argv[1]);
    }
    // Loop and print out all directories.
    while ((dirp = readdir(dp)) != NULL) {
        printf("d-- %s", dirp->d_name);
    }
    // Close the directory handle.
    closedir(dp);
    exit(0);
}