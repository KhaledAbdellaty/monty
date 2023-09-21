#include "monty.h"

/**
 * main - the entry point
 * @argc: the number of the arguments.
 * @argv: the vector arguments.
 * Return: EXIT_SUCCESS, or EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"pint", &pint},
		{"pop", &pop},
		{"pall", &pall},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &divide},
		{"mul", &multi},
		{"mod", &mod},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	execute_monty_file(argv[1], instructions);
	return (EXIT_SUCCESS);
}
