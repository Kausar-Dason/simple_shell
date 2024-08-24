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
	int count = 0;
	char *args[140];
	char *token;

	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0) /* Child process*/
	{
		token = strtok((char *)command, " ");
		while (token != NULL)
		{
			args[count++] = token;
			token = strtok(NULL, " ");
		}
		args[count] = NULL;
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	else /* Parent process*/
	{
		wait(NULL);
	}
}
