#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

// Function to handle errors and print the message
void print_error(char *command)
{
    perror(command);  // Print the error message
}

// Function to execute a command
void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();  // Create a new process

    if (pid == -1)  // Error occurred in forking
    {
        print_error("fork");
        return;
    }

    if (pid == 0)  // Child process
    {
        if (execve(command, (char *[]) {command, NULL}, NULL) == -1)  // Execute the command
        {
            print_error(command);  // If execution fails, print error
            exit(EXIT_FAILURE);
        }
    }
    else  // Parent process
    {
        wait(&status);  // Wait for the child process to finish
    }
}

// Main function to start the shell
int main(void)
{
    char *line = NULL;  // To hold the user input
    size_t len = 0;
    ssize_t read;
    char prompt[] = "#cisfun$ ";

    while (1)
    {
        // Display prompt
        write(STDOUT_FILENO, prompt, strlen(prompt));

        // Read command from user
        read = getline(&line, &len, stdin);
        if (read == -1)  // EOF or error
        {
            free(line);
            break;
        }

        // Remove newline character at the end of the command
        line[read - 1] = '\0';

        // If the input is empty, prompt again
        if (strlen(line) == 0)
        {
            continue;
        }

        // Check for exit command
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        // Execute the command
        execute_command(line);
    }

    return 0;
}
