#include "shell.h"

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
