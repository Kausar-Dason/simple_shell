#include "shell.h"

/**
 * _strlen - a function that returns the length of a string
 * @s: the string to be measured
 *
 * Return: The length of string
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return (length);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 *
 */
char *_strdup(char *str)
{
	int len, a = 0;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	dup = malloc(sizeof(char) * len);

	if (dup == NULL)
		return (NULL);

	while (a < len)
	{
		dup[a] = str[a];
		a++;
	}

	return (dup);
}




