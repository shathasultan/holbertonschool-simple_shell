#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s && s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if equal, negative if s1 < s2, positive if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
 * _strdup - Duplicate a string
 * @str: String to duplicate
 * Return: Pointer to new string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup;
	int len, i;

	if (!str)
		return (NULL);
	len = _strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * _strchr - Locate a character in a string
 * @s: The string
 * @c: The character to find
 * Return: Pointer to first occurrence or NULL
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
