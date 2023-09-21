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

/**
 * mod - a function that multiplies the second top
 * element of the stack with the top element of the stack.
 * @stack: the stack.
 * @line_number: the line number.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * comment - a function that treat this line as a comment.
 */
void comment(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
