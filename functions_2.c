#include "monty.h"
/**
 * digit - Function to evaluate if is a number.
 * @var: pointer to second argument of a command line.
 * Return: 1 if is a number else 0.
 */
int digit(char *var)
{
    int i = 0;

    for (; var[i] != '\0'; i++)
    {
        if (var[i] <= 48 || var[i] >= 57)
            return (0);
    }
    return (1);
}
/**
 * pint - function
 * @stack: stack
 * @line_s: line
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int line_s)
{
    stack_t *head;
    (void) line_s;
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