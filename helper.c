#include "monty.h"
#include <stdio.h>

/**
 * s_free - frees all malloc'd in stack
 * Return: void
 */

void s_free(void)
{
	stack_t *temp;
	stack_t *head;

	if (traverse->stack)
	{
		head = traverse->stack;

		while (head)
		{
			temp = head->next;
			free(head);
			head = temp;
		}
	}
}

/**
 * _free - frees all malloc'd memory
 * Return: void
 */

void _free(void)
{
	if (traverse != NULL)
	{
		if (traverse->file != NULL)
			fclose(traverse->file);

		if (traverse->line != NULL)
			free(traverse->line);

		if (traverse->input != NULL)
			free(traverse->input);

		s_free();
		free(traverse);
	}
}

/**
 * _error - handles all errors
 * @x: number of error
 * Return: void
 */

void _error(int x)
{
	unsigned int n;
	static char *const errors[] = {
		"Error: malloc failed\n", "USAGE: monty file\n",
		NULL, NULL,
		"usage: push integer\n", "can't pint, stack empty\n",
		"can't pop an empty stack\n", "can't swap, stack too short\n",
		"can't add, stack too short\n", "can't sub, stack too short\n",
		"can't div, stack too short\n", "division by zero\n",
		"can't mul, stack too short\n", "can't mod, stack too short\n",
		"can't pchar, stack empty\n", "can't pchar, value out of range\n"
	};

	if (traverse)
		n = traverse->line_num;

	if (x <= 1)
		dprintf(STDOUT_FILENO, "%s", errors[x]);
	else if (x == 2)
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n",
				traverse->filename);
	else if (x == 3)
		dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", n,
				traverse->input[0]);
	else if (x >= 4)
		dprintf(STDOUT_FILENO, "L%u: %s", n, errors[x]);

	_free();

	exit(EXIT_FAILURE);
}
