#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DELIM " \n\t\r\a"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
* struct var_global - Struct that store all global variables,
* @token_l: The second agurment of a command line.
* @line: Line.
* @fp: Fp.
* Description: Simple global variable to analyze the second argument.
*/
typedef struct var_global
{
	char *token_l;
	char *line;
	FILE *fp;
} global_t;
extern global_t g;
global_t g;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int digit(char *var);
void free_listint2(stack_t *head);
void (*match_function(char *function))(stack_t **node, unsigned int line_s);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void sub(stack_t **, unsigned int );
void div(stack_t **, unsigned int );
void mul(stack_t **, unsigned int );

#endif
