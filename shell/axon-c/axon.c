/* 
* Axon is neuronux's shell. This will most likely be re-written in Go,
* but I wanted to write it in C first for learning purposes.
* Command to start shell will be ax.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define LSH_RL_BUFSIZE 1024

char *ax_read_line(void)
{
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Read a character
    c = getchar();

    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


// The main shell loop;
int axon_loop() {
    int status;
    do {
        printf("ax ~> ");
        ax_read_line();
    } while(status);
}

int main() {
    // Call the axon_loop function to execute the shell.
    axon_loop();
    // Once shell execution is complete return 0.
    exit(EXIT_SUCCESS);
}