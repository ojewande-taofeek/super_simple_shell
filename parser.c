#include "main.h"


char **break_line(char *buffer_copy, size_t read_n)
{
	char **word, *buffer_tok, *token, *delm = " \n";
	int idx = 0;

	buffer_tok = malloc(sizeof(char) * read_n);
	if (buffer_tok == NULL)
	{
		perror("Error");
		_exit(-1);
	}
	_strcpy(buffer_tok, buffer_copy);

	token = strtok(buffer_tok, delm);
	while (token != NULL)
	{
		idx++;
		token = strtok(NULL, delm);
	}
	idx++;

	word = malloc(sizeof(char) * (idx + 1));
	if (word == NULL)
	{
		perror("Error");
		_exit(-1);
	}
	token = strtok(buffer_copy, delm);
	idx = 0;
	for (; token != NULL; idx++)
	{
		word[idx] = _strdup(token);
		if (word[idx] == NULL)
		{
			perror("Error");
			_exit(-1);
		}
		token = strtok(NULL, delm);
	}
	word[idx] = NULL;
	return (word);
}
