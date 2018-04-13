#include <stdio.h>
#include <unistd.h>
#include <syscall.h>
#include <sys/types.h>

int main (int argc, char *argv[]) {
	int success;
	// Check to see if there have been enough arguments supplied.
	if (argc != 2) {
		printf("Error: mkdir <dirname>\n");
		exit(1);
	}
	// Attempt to create a directory with the mkdir system call.
	if ((success = mkdir(argv[1], 0777)) != 0) {
		printf("Error: There was an error creating %s.\n",argv[1]);
		exit(1);
	}
	exit(0);
}