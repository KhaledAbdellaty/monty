#include "monty.h"
/**
 * free_stack - a function that frees the stack.
 * @stack: the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
