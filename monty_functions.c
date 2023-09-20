#include "monty.h"

/**
 * pall - a function that prints all the
 * values on the stack.
 * @stack: the stack.
 * @line_number: is a flag to check if is
 * the stack is empty, or not.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (line_number == 0)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - a function that pushes an element to the stack.
 * @stack: the stack.
 * @value: the n value.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pint - a function that prints the value at the
 * top of the stack.
 * @stack: the stack.
 * @line_number: the number of line in the
 * Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - a function that removes the
 * top element of the stack.
 * @stack: the stack.
 * @line_number: the number of line in the
 * Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
