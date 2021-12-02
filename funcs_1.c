#include "monty.h"

/**
 * _mod - prints the renainder of the second top element of the
 *        stack by the top element of the stack.
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _mod(stack_t **stack, unsigned int x)
{
	int modulo;

	if (*stack == NULL || (*stack)->next == NULL)
		_error(ERROR_MOD);

	if ((*stack)->n == 0)
		_error(ERROR_DIV_ZERO);

	modulo = (*stack)->next->n % (*stack)->n;

	_pop(stack, x);
	(*stack)->n = modulo;
}

/**
 * _pchar - prints the char type of the head node integer
 * @stack: the stack
 * @x: line number
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int x)
{
	(void)x;

	if (!stack || !*stack)
		_error(ERROR_STACK_EMPTY);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		_error(ERROR_PCHAR_RANGE);

	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the char type of the head node integer
 * @stack: the stack
 * @x: line number
 * Return: void
 */

void _pstr(stack_t **stack, unsigned int x)
{
	stack_t *copy;

	(void)x;

	for (copy = *stack; copy; copy = copy->next)
	{
		if (copy->n < 1 || copy->n > 127)
			break;
		printf("%c", copy->n);
	}
	putchar('\n');
}

/**
 * _rotl - rotates the stack top to bottom
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _rotl(stack_t **stack, unsigned int x)
{
	int end;
	stack_t *copy;

	(void)x;

	if (stack && *stack)
	{
		end = (*stack)->n;

		for (copy = *stack; copy->next; copy = copy->next)
			copy->n = copy->next->n;
		copy->n = end;
	}
}

/**
 * _rotr - rotates the stack bottom to top
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _rotr(stack_t **stack, unsigned int x)
{
	int next, current;
	stack_t *copy;

	(void)x;

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}
