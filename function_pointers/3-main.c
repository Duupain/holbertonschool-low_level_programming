#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry of program
 * @argc: Number arguments
 * @argv: Array of arguments
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int a, b;
	char *op;
	int (*op_func)(int, int);

	if (argc == 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		op = argv[2];
		op_func = get_op_func(op);

		if (op[1] == '\0' && op_func != NULL)
		{
			if (b == 0 && (*op == '/' || *op == '%'))
			{
				printf("Error\n");
				exit(100);
			}

			printf("%d\n", op_func(a, b));
		}
		else
		{
			printf("Error\n");
			exit(99);
		}
	}
	else
	{
		printf("Error\n");
		exit(98);
	}

	return (0);
}
