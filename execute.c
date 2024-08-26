#include "shell.h"
/**
 * execute - execute the commands
 * @command: the command to execute
 *
 * Return: void
 */

void execute(const char *command)
{
	pid_t child_pid;
	int count = 0;
	char *args[140];
	char *token;
	char *full_path;

	token = strtok((char *)command, " ");
	while (token != NULL)
	{
		args[count++] = token;
		token = strtok(NULL, " ");
	}
	args[count] = NULL;

	/* Check if command is an absolute path or exists in PATH */
	if (args[0][0] == '/' || args[0][0] == '.')
	{
		full_path = args[0];
	}
	else
	{
		full_path = find_executable(args[0]);
		if (!full_path)
		{
			perror("command not found");
			return;
		}
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0) /* Child process*/
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	else /* Parent process*/
	{
		wait(NULL);
	}

	if (full_path != args[0])
		free(full_path);
}
