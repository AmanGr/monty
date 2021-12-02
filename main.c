#include "monty.h"
#include <stdio.h>

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments traverse (file path expected)
 * Return: 0 always - success!
 */

int main(int argc, char **argv)
{
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_number);

	traverse = NULL;
	if (argc != 2)
		_error(ERROR_USAGE_FILE);

	built_in();
	traverse->filename = argv[1];
	traverse->file = fopen(traverse->filename, "r");

	if (traverse->file == NULL)
		_error(ERROR_OPEN_FILE);

	while (getline(&traverse->line, &n, traverse->file) > 0)
	{
		traverse->line_num++;

		if (_parse(traverse->line) == EXIT_FAILURE)
			continue;

		execute = _opcode();
		execute(&traverse->stack, traverse->line_num);
	}
	_free();
	return (EXIT_SUCCESS);
}
