#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command = NULL;
	size_t size = 0;

	while (1)
	{
		display_prompt();
		read_input(&command, &size);
		if (command == NULL)
		{
			free(command);
			break;
		}

		execute(command);

		command = NULL;
	}

	return (0);
}
