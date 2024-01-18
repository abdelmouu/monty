#include "monty.h"
/**
 * _strcmp - Compares two strings.
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 * Return: 0 if s1 and s2 are equal,
 *         a value other than 0 if they are different.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _sch - Searches for a character inside a string.
 * @s: String to review.
 * @c: Character to find.
 * Return: 1 if the character is found, 0 if not.
 */
int _sch(char *s, char c)
{
	int ct = 0;

	while (s[ct] != '\0')
	{
		if (s[ct] == c)
		{
			break;
		}
		ct++;
	}
	if (s[ct] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - Function that cuts a string into tokens
 * based on the specified delimiters.
 * @s: String to be partitioned.
 * @d: Delimiters.
 * Return: First partitioned substring.
 */
char *_strtoky(char *s, char *d)
{
	static char *ult;
	int i = 0, j = 0;

	if (!s)
		s = ult;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ult = s + i + 1;
			*ult = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ult = s + i + 1;
			*ult = '\0';
			ult++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
