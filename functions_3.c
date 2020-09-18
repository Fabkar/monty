#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to stack's head.
 * @line_number: line.
 * Return: Nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_listint2(*stack);
		free(g.line);
		fclose(g.fp);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += tmp;
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to stack's head.
 * @line_number: line.
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}
/**
 * sub - sub the top two elements of the stack.
 * @stack: pointer to stack's head.
 * @line_number: line.
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_listint2(*stack);
		free(g.line);
		fclose(g.fp);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= tmp;
}

/**
 * div - divide second element of stack by top element
 * @stack: pointer to head of stack
 * @line_number: line number
 *
 * Return: void
 */
void div(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	m_pop(stack, line_number);
	if (n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}
