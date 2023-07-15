#include "main.h"

int main(void)
{	
	char *buffer = NULL, *buffer_copy, *file_path, *file_name, **args;
	size_t n = 0;
	ssize_t read_n;
	int status, idx;
	pid_t child_pid;

	put_prompt();
	while ((read_n = getline(&buffer, &n, stdin)) != -1)
	{
		if (read_n > 0)
		{
			buffer_copy = malloc(sizeof(char) * (read_n + 1));
			if (buffer_copy == NULL)
			{
				perror("Error");
				continue;
			}
			_strcpy(buffer_copy, buffer);
			
			args = break_line(buffer_copy, read_n);
			if (args == NULL)
			{
				free(buffer_copy);
				put_prompt;
				continue;
			}
			file_name = args[0];
			file_path = path_name(file_name);
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
			}
			else if (child_pid == 0)
			{
				 if (file_path != NULL)
					executor(args);
				else
					_exit(EXIT_FAILURE);
			}
			else	
				wait(&status);
			put_prompt();
			free(file_path);
	//		free(buffer_copy);
			for (int idx = 0; args[idx] != NULL; idx++)
				free(args[idx]);
			free(args);
		}
		else
			put_prompt();
	}
	free(buffer);
	return (0);
}
