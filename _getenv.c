#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i = 0;
	int length = _strlen(name);

	while (environ[i])
	{
		if (_strncmp(environ[i], name, length) == 0 && environ[i][length] == '=')
		{
			return (environ[i] + length + 1);
		}
		i++;
	}
	return (NULL);
}
