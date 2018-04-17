package main

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
	"strings"
	"syscall"
)

// AxonLoop is the REPL for the ax shell.
func AxonLoop() {
	var cmdReader *bufio.Reader
	var cmdString string
	var cmd []string
	env := os.Environ()

	// Read in the command from the user from STDIN.
	cmdReader = bufio.NewReader(os.Stdin)
	fmt.Printf("ax ~> ")
	cmdString, _ = cmdReader.ReadString(' ')
	cmd = strings.Split(cmdString, " ")
	binary, lookErr := exec.LookPath(cmd[0])
	if lookErr != nil {
		panic(lookErr)
	}
	err := syscall.Exec(binary, cmd[1:], env)
	if err != nil {
		panic("Test")
	}
}

// Call the AxonLoop in the main function to start the shell's execution.
func main() {
	AxonLoop()
}
