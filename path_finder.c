#include "main.h"

char *path_name(char *file_name)
{
	char *path, *path_copy, *token, *delm = ":", *final_path;
	int token_len, file_len;
	struct stat buf;

	file_len = _strlen(file_name);
	path = getenv("PATH");
	if (path)
	{
		path_copy = malloc(sizeof(char) * _strlen(path));
		if (path_copy == NULL)
		{
			perror("Error: ");
			_exit(-1);
		}
		_strcpy(path_copy, path);
		
		token = strtok(path_copy, delm);
		while (token != NULL)
		{
			token_len = _strlen(token);
			final_path = malloc(sizeof(char) * (token_len + file_len + 2));

			if (final_path == NULL)
			{
				perror("Error: ");
				_exit(-1);
			}
			_strcpy(final_path,token);
			_strcat(final_path, "/");
			_strcat(final_path, file_name);
			_strcat(final_path, "\0");
			if (stat(final_path, &buf) == 0)
			{
				free(path_copy);
				return (final_path);
			}
			else
			{
				free(final_path);
				token = strtok(NULL, delm);
			}
		}
		free(path_copy);
		if (stat(file_name, &buf) == 0)
			return (file_name);
		return (NULL);
	}
	return (NULL);
}
