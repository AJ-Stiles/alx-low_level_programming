#include "main.h"

/**
 * _memcpy - Copies memory area
 * @dest: The destination memory area
 * @src: The source memory area
 * @n: The number of bytes to be copied
 *
 * Return: A pointer to the destination memory area
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *dest_start = dest;

	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return (dest_start);
}

/**
 * _strchr - Locates a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 *
 * Return: A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to be analyzed
 * @accept: The string containing the characters to match
 *
 * Return: The number of bytes in the initial segment of s
 * consisting only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s && _strchr(accept, *s))
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to be searched
 * @accept: The string containing the characters to search for
 *
 * Return: A pointer to the first occurrence in s of any character from accept,
 * or NULL if no such character is found
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		if (_strchr(accept, *s))
			return (s);
		s++;
	}
	return (NULL);
}

/**
 * _strstr - Locates a substring in a string
 * @haystack: The string to be searched
 * @needle: The substring to be found
 *
 * Return: A pointer to the first occurrence of the substring in the string,
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (haystack);
		haystack++;
	}
	return (NULL);
}
