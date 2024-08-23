#include "shell.h"
/**
 * execute - execute the commands
 * @command: the command to execute
 *
 * Return: void
 */

void execute(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0) /* Child process*/
	{
		execlp(command, command, (char *)NULL);
		perror("Error");
		exit(EXIT_FAILURE);
	}

	else /* Parent process*/
	{
		wait(NULL);
	}
}
