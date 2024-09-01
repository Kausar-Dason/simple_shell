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
	char *args[140];
	char *full_path;

	parse_command((char *)command, args);
	full_path = get_full_path(args[0]);

	if (!full_path)
	{
		perror("command not found");
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0) /* Child process*/
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
		if (full_path != args[0])
			free(full_path);
	}
}

/**
 * get_full_path - Determines the full path of a command.
 * @command: The command to find the full path for.
 *
 * Return: The full path to the executable or NULL if the command is not found
 */
char *get_full_path(char *command)
{
	if (command[0] == '/' || command[0] == '.')
		return (command);
	else
		return (find_executable(command));
}

/**
 * parse_command - Tokenizes a command string into individual arguments.
 * @command: The command string entered by the user.
 * @args: Array to store the arguments after tokenization.
 *
 * Return: void
 */
void parse_command(char *command, char **args)
{
	char *token;
	int count = 0;

	token = strtok(command, " ");
	while (token)
	{
		args[count++] = token;
		token = strtok(NULL, " ");
	}
	args[count] = NULL;
}
