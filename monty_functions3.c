#include "monty.h"
/**
 * multi - a function that multiplies the second top
 * element of the stack with the top element of the stack.
 * @stack: the stack.
 * @line_number: the line number.
 */
void multi(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
