#include "Alxhell.h"

#define MAX_COMMAND_LENGTH 1024

/**
 * execute_command - Execute the given command in a separate process.
 * @command: Parse the command into arguments
 */

void execute_command(char *command)
{
char *args[MAX_COMMAND_LENGTH];
char *token;
pid_t pid;
int i = 0;
token = strtok(command, " ");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
pid = fork();
if (pid < 0)
{
perror("Forking error");
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("Execution error");
}
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
