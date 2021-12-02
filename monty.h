#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include "structs.h"

/* macros */
#define DELIMITERS "\n\t\r "

/* struct search function */
int opcode_struct(char *opcode, stack_t **stack, unsigned int line_number);

/* stack functions */
void push(stack_t **stack, unsigned int line_number, char *n);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* print functions */
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/* calc functions */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/* utility functions */
size_t stack_length(stack_t **stack);
void free_stack(stack_t **stack);
void free_all(stack_t *stack, char *line, FILE *fp);
void frees(stack_t *head);


#endif /* MONTY_H */
