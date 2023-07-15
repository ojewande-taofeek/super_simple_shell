#include "main.h"


int put_char(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

void put_prompt()
{
	char *prompt = "#cisfun$ ";
	int idx = 0;

	while (prompt[idx])
	{
		put_char(prompt[idx]);
		idx++;
	}
}
