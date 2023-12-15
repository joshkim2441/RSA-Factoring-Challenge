#include <stdio.h>
#include <stdlib.h>

/*function to find a factor of a number*/
int find_factor(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return (i);
		}
	}
	return (n);
}

/**
 * main - entry point
 * @argc: the argument count
 * @argv: the array of arguments
 * Return: 1 if success, 0 if fail
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Could not open file %s\n", argv[1]);
		return (1);
	}

	int n;
	while (fscanf(file, "%d", &n) == 1)
	{
		int p = find_factor(n);
		int q = n / p;
		printf("%d=%d*%d\n", n, p, q);
	}

	fclose(file);
	return (0);
}