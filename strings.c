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

/**
 * _strncmp - Compare two strings up to n characters.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if equal
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @d: The destination buffer.
 * @s: The source string to copy.
 *
 * Return: A pointer to the destination string `dest`.
 */
char *_strcpy(char *d, const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		d[i] = s[i];
	}
	d[i] = '\0';

	return (d);
}

/**
 * *_strcat - a function that concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int i;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return (dest);
}
