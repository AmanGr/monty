# include "monty.h"

/**
 * _lifo - adds node at the beginning of a stack_t list
 * @stack: head pointer of stack
 * @node: node to add
 */

void _lifo(stack_t **stack, stack_t *node)
{
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

/**
 * _fifo - adds node at the end of a stack_t list
 * @stack: head pointer of queue
 * @node: node to add
 */

void _fifo(stack_t **stack, stack_t *node)
{
	stack_t *head = *stack;

	node->next = NULL;
	if (!*stack)
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		while (head->next)
			head = head->next;
		head->next = node;
		node->prev = head;
	}
}


/**
 * _stack - switches list/queue to stack
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _stack(stack_t **stack, unsigned int x)
{
	(void)stack;
	(void)x;
	traverse->order = LIFO;
}

/**
 * _queue - switches list/stack to queue
 * @stack: the stack
 * @x: line number
 * Return: void
 */

void _queue(stack_t **stack, unsigned int x)
{
	(void)stack;
	(void)x;
	traverse->order = FIFO;
}
