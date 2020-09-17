#include "monty.h"
/**
* push - function to add a integer on top of stack.
* @stack: Pointer to head of steack.
* @line_number: Line count.
* Return: void.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	char *var = NULL;
	int i = 0;

	var = g->token_l;

	if (digit(var) == 0)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(var);

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	node->n = i;
	node->next = *stack;
	node->prev = NULL;
	if (*stack == NULL)
		(*stack) = node;
	else
	{
		(*stack)->prev = node;
		(*stack) = node;
	}
}

/**
 * pall - function to delete a integer from top of stack.
 * @stack: pointer to head of stack.
 * @line_number: line counter.
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;
	(void)(line_number);
	head = *stack;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
/**
* free_listint2 - free a listin_t list.
* @head: Pointer to head of the linked list.
* Return: Nothing.
*/
void free_listint2(stack_t **head)
{
	stack_t *aux;

	if (!head)
		return;
	while (*head != NULL)
	{
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
	head = NULL;
}
