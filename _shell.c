#include "main.h"

int main(int argc, char *argv[])
{	
	char *buffer = NULL, *buffer_copy, *file_path, *file_name;
	size_t n = 0;
	int read_n, status;
	(void) argc;
	pid_t child_pid;

	put_prompt();
	while ((read_n = getline(&buffer, &n, stdin)) != EOF)
	{
		if (read_n > 0)
		{
			buffer_copy = malloc(sizeof(char) * read_n);
			if (buffer_copy == NULL)
			{
				perror("Error: ");
				continue;
			}
			_strcpy(buffer_copy, buffer);
			
			argv = break_line(buffer_copy, read_n);
			file_name = argv[0];
			file_path = path_name(file_name);
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error: ");
			}
			if (child_pid == 0)
			{
			//	put_prompt();
				 (executor(argv));
			}
			put_prompt();
			if (child_pid > 0)	
			{
				wait(&status);
				put_prompt();
			}
		}
		else
			put_prompt();
	}
	free(buffer);
	return (0);
}
