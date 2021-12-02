#include "monty.h"

/**
 * _isDigit - checks if every char in a string is a digit
 * @c: char to be checked
 *
 * Return: TRUE else FALSE
 */
int _isDigit(char *c)
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == '-' && i == 0)
			i++;
		if (isdigit(c[i]) == FALSE)
			return (FALSE);
	}

	return (TRUE);
}


/**
 * built_in - builds global struct of most used variables
 * Return: EXIT_SUCCESS else EXIT_FAILURE
 */

int built_in(void)
{
	traverse = malloc(sizeof(trave_t));
	if (!traverse)
		_error(ERROR_MALLOC);

	traverse->input = malloc(sizeof(char *) * 3);
	if (!traverse->input)
	{
		free(traverse);
		_error(ERROR_MALLOC);
	}

	traverse->stack = NULL;
	traverse->line = NULL;
	traverse->line_num = 0;
	traverse->order = LIFO;

	return (EXIT_SUCCESS);
}

/**
 * _opcode - matches function to opcodes
 * Return: correct function
 */

void (*_opcode(void))(stack_t **stack, unsigned int x)
{
	char *input_opcode;
	instruction_t *i;
	static instruction_t instructions[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod},
		{"pchar", _pchar}, {"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr}, {"stack", _stack}, {"queue", _queue},
		{NULL, NULL}
	};

	i = instructions;
	input_opcode = traverse->input[0];

	while (i->opcode && strncmp(i->opcode, input_opcode, strlen(input_opcode)))
		i++;

	if (!i->f)
		_error(ERROR_UNKNOWN);

	return (i->f);
}

/**
 * _parse - parses line/getline into input global variable
 * @line: input line
 * Return: EXIT_SUCCESS
 */

int _parse(char *line)
{
	char *delim, *s;
	int len, i;

	delim = "\n ";
	s = traverse->line;
	len = strlen(s);

	for (i = 0; s[i] == delim[0] || s[i] == delim[1]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);

	traverse->input[0] = strtok(line, delim);

	if (traverse->input[0][0] == '#')
		return (EXIT_FAILURE);

	traverse->input[1] = strtok(NULL, delim);

	return (EXIT_SUCCESS);
}
