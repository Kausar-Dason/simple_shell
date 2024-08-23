#include "shell.h"

/**
 * read_input - Reads a command from standard input.
 * @command: Pointer to the command buffer.
 * @size: Pointer to the size of the buffer.
 *
 * Return: The command entered by the user, or NULL if there is an error.
 */
char *read_input(char **command, size_t *size)
{
	/* Read command */
	if (getline(command, size, stdin) == -1)
	{
		if (feof(stdin))
			c_print("\n"); /* Handle Ctrl+D */
		return (NULL);
	}

	/* Remove newline character from command */
	(*command)[strcspn(*command, "\n")] = '\0';

	return (*command);
}
