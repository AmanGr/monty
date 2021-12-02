#ifndef _LIFO_FIFO_H_
#define _LIFO_FIFO_H_

/* <-------|STANDARD LIBRARIES|-------> */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <ctype.h>

/* <-------|MACROS PREDEFINED|-------> */

#define BUFSIZE 1024
#define LIFO 1
#define FIFO 0
#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define ERROR_MALLOC 0
#define ERROR_USAGE_FILE 1
#define ERROR_OPEN_FILE 2
#define ERROR_UNKNOWN 3
#define ERROR_PUSH 4
#define ERROR_PINT 5
#define ERROR_POP 6
#define ERROR_SWAP 7
#define ERROR_ADD 8
#define ERROR_SUB 9
#define ERROR_DIV 10
#define ERROR_DIV_ZERO 11
#define ERROR_MUL 12
#define ERROR_MOD 13
#define ERROR_STACK_EMPTY 14
#define ERROR_PCHAR_RANGE 15

/* <-------|DATA STRUCTURES|-------> */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct traverser_s - points to all other structs
 * @filename: the filename from argv[1]
 * @stack: pointer to stack
 * @line: input line received from getline
 * @input: lines of the files parsed into separate elements
 * @line_num: the linenumber
 * @file: the input file
 * @order: LIFO or FIFO
 */
typedef struct traverser_s
{
	char *filename;
	stack_t *stack;
	char *line;
	char **input;
	unsigned int line_num;
	FILE *file;
	int order;
} trave_t;

/* <-----| GLOBAL VARIABLES |-----> */

extern trave_t *traverse;
trave_t *traverse;

/* <-------|ERRORS|-------> */
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/* <-------| LISTS |-------> */

void _lifo(stack_t **stack, stack_t *node);
void _fifo(stack_t **queue, stack_t *node);

/* <-------|HELPERS|-------> */

int built_in(void);
int _isDigit(char *c);
void (*_opcode(void))(stack_t **stack, unsigned int x);
int _parse(char *line);
void _free(void);
void s_free(void);
void _error(int x);

/* <-------|STACK FUNCTIONS|-------> */

void _stack(stack_t **stack, unsigned int x);
void _queue(stack_t **stack, unsigned int x);
void _push(stack_t **stack, unsigned int x);
void _pall(stack_t **stack, unsigned int x);
void _pint(stack_t **stack, unsigned int x);
void _pop(stack_t **stack, unsigned int x);
void _swap(stack_t **stack, unsigned int x);
void _add(stack_t **stack, unsigned int x);
void _nop(stack_t **stack, unsigned int x);
void _sub(stack_t **stack, unsigned int x);
void _div(stack_t **stack, unsigned int x);
void _mul(stack_t **stack, unsigned int x);
void _mod(stack_t **stack, unsigned int x);
void _pchar(stack_t **stack, unsigned int x);
void _pstr(stack_t **stack, unsigned int x);
void _rotl(stack_t **stack, unsigned int x);
void _rotr(stack_t **stack, unsigned int x);

#endif /* LIFO_FIFO_H */
