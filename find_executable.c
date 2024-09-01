#include "shell.h"

/**
 * find_executable - Search for command in the PATH environment variable.
 * @command: The command to search for.
 *
 * Return: The full path to the command if found, otherwise NULL.
 */
char *find_executable(const char *command)
{
	struct stat st;
	char *full_path;
	char *cmd_path = _getenv("PATH");
	char *path_cpy = _strdup(cmd_path);
	char *dir = strtok(path_cpy, ":");

	if (cmd_path == NULL)
		return (NULL);

	while (dir != NULL)
	{
		full_path = construct_full_path(dir, command);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_cpy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}

/**
 * construct_full_path - a function constructs the full path to an executable
 *		command by concatenating a directory path and the command name.
 * @dir: a constant pointer to a string representing the directory path.
 * @command: a constant pointer to a string representing the command name.
 *
 * Return: the resulting full path as a dynamically allocated string.
 */
char *construct_full_path(const char *dir, const char *command)
{
	int dir_len = _strlen(dir);
	int command_len = _strlen(command);
	char *full_path = malloc(dir_len + command_len + 2);

	if (full_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(full_path, dir);

	if (dir_len > 0 && full_path[dir_len - 1] != '/')
	{
		strcat(full_path, "/");
	}
	_strcat(full_path, command);

	return (full_path);
}

