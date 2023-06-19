#include "main.h"
/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	char *dest_start = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}

/**
 * _strncat - Concatenates two strings, using at most n bytes from src
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes from src to be concatenated
 *
 * Return: A pointer to the resulting string
 */

char *_strncat(char *dest, char *src, int n)
{
	char *dest_start = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (dest_start);
}

/**
 * _strncpy - Copies a string, using at most n bytes
 * @dest: The destination buffer
 * @src: The source string
 * @n: The maximum number of bytes to be copied
 *
 * Return: A pointer to the destination buffer
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *dest_start = dest;

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (dest_start);
}

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if the strings are equal,
 * a negative value if s1 is less than s2,
 * a positive value if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _memset - Fills memory with a constant byte
 * @s: The memory area to be filled
 * @b: The constant byte to fill the memory with
 * @n: The number of bytes to be filled
 *
 * Return: A pointer to the filled memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *s_start = s;

	while (n > 0)
	{
		*s = b;
		s++;
		n--;
	}
	return (s_start);
}
