#include "main.h"

void executor(char **argv)
{
	char *file_name, *file_path;

	if (argv)
	{
		file_name = argv[0];
	
		file_path =  path_name(file_name);

		if (execve(file_path, argv, NULL) == -1)
		{
			perror("Error");
			_exit(EXIT_FAILURE);
		}
	}
}
		
	
