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
 * c_print - print function for printing texts
 * @text: the string to be printed
 *
 * Return: void
 */
void c_print(const char *text)
{
	write(STDOUT_FILENO, text, _strlen(text));
}


/**
 * display_prompt - prints the prompt
 *
 * Return: void
 */
void display_prompt(void)
{
	c_print("simple_shell$ ");
}
