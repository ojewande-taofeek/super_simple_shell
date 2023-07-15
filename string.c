#include "main.h"

char *_strcpy(char *dest, char *src)
{
	int idx;

	for (idx = 0; src[idx]; idx++)
		dest[idx] = src[idx];
	dest[idx] = '\0';
	return (dest);
}


int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}


char *_strcat(char *dest, char *src)
{
	int len, idx;

	for (len = 0; dest[len]; len++)
		;
	idx = 0;
	while (src[idx])
	{
		dest[len] = src[idx];
		len++;
		idx++;
	}
	dest[len] = '\0';
	return (dest);
}
