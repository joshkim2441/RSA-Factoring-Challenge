#include "factors.h"

/**
 * function to find the factor of a number
 * @buff: a pointer to the number address
*/
int find_factor(char *buff)
{
	u_int32_t digit;
	u_int32_t j;

	digit = atoi(buff);

	for (j = 2; j < digit; j++)
	{
		if (digit % j == 0)
		{
			printf("%d=%d*%d\n",digit,digit/j,j);
			break;
		}
	}
	return (0);
}

/**
 * main - entry point
 * @argc: the argument count
 * @argv: the array of arguments
 * Return: 1 if success, 0 if fail
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *buff = NULL;
	size_t counter;
	ssize_t ln;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ln = getline(&buff, &counter, file)) != -1)
	{
		find_factor(buff);
	}
	return (0);
}