#include "monty.h"
/**
 * digit - Function to evaluate if is a number.
 * @var: pointer to second argument of a command line.
 *  @line_number: counter line.
 * Return: 1 if is a number else 0.
 */
int digit(char *var, unsigned int line_number)
{
	int i = 0;

	if (var[0] == '-')
	{
		if (var[1] == '\0')
		{
			printf("L%u: usage: push integer\n", line_number);
			return (0);
		}
		i = 1;
	}
	for (; var[i] != '\0'; i++)
	{
		if (var[i] < 48 || var[i] > 57)
			return (0);
	}
	return (1);
}
/**
 * pint - function
 * @stack: Pointer to stack's head.
 * @line_s: line
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int line_s)
{
	stack_t *head;

	head = *stack;

	if (head == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_s);
		free_listint2(*stack);
		free(g.line);
		fclose(g.fp);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);

}
/**
 * pop - function to remove the top element from stack.
 * @stack: pointer to stack's head.
 * @line_s: line.
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_s)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_s);
		free_listint2(*stack);
		free(g.line);
		fclose(g.fp);
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}

/**
 * swap -  swaps the top two elements of the stack.
 * @stack: pointer to stack's head.
 * @line_number: line.
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	if ((*stack) == NULL || ((*stack)->next == NULL))
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		free_listint2(*stack);
		free(g.line);
		fclose(g.fp);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;

	if (tmp->next)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack) = (*stack)->prev;
}

