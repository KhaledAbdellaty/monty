#include "monty.h"
/**
 * exec_push - a function that exectue push method.
 * @token: the token.
 * @stack: the stack.
 * @line_number: the line number.
 */
void exec_push(const char *token, stack_t **stack,
		unsigned int line_number, char *line)
{
	int value;

	token = strtok(NULL, " ");
	if (!token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(line);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
	push(stack, value);
}
/**
 * exec_instractions - executes the corresponding instruction.
 * @token: token.
 * @stack: the stack.
 * @instructions: the list of instruction_s struct.
 * @line_number: the line number.
 */
void exec_instractions(const char *token, stack_t **stack,
		instruction_t instructions[], unsigned int line_number,
		char *line)
{
	instruction_t *instruction = NULL;
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(token, instructions[i].opcode) == 0)
		{
			instruction = &instructions[i];
			break;
		}
		i++;
	}
	if (!instruction)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
		free(line);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	instruction->f(stack, line_number);
}
/**
 * execute_monty_file - a function that reads the file
 * and executes the corresponding instruction
 * based on the line content.
 * @file: the monty file path.
 * @instructions: a list of corresponding instructions.
 */
void execute_monty_file(const char *file, instruction_t instructions[])
{
	char *line = NULL, *token = NULL;
	size_t line_size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	fp = fopen(file, "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &line_size, fp) != -1)
	{
		line_number++;
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		token = strtok(line, " ");
		if (token != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				exec_push(token, &stack, line_number, line);
			}
			else
			{
				exec_instractions(token, &stack, instructions, line_number, line);
			}
		}
	}
	free(line);
	fclose(fp);
	free_stack(stack);
}
