#include <stdio.h>

/**
 * is_palindrome - Check if a number is a palindrome
 * @n: The number to check
 *
 * Return: 1 if the number is a palindrome, 0 otherwise
 */
int is_palindrome(int n)
{
	int reversed = 0, original = n;

	while (n != 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return (original == reversed);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int largest_palindrome = 0;

	for (int i = 999; i >= 100; i--)
	{
		for (int j = i; j >= 100; j--)
		{
			int product = i * j;

			if (product > largest_palindrome && is_palindrome(product))
			{
				largest_palindrome = product;
			}
		}
	}

	FILE *file = fopen("102-result", "w");

	fprintf(file, "%d", largest_palindrome);
	fclose(file);

	return (0);
}
