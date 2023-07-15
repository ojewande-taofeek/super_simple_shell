#ifndef MAIN_H
#define MAIN_H


/* HEADERS */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>


/* UTILITIES PROTOTYPES */

int put_char(char c);
void put_prompt();

/* PARSER PROTOTYPE */
char **break_line(char *buffer_copy, size_t read_n);

/* EXE PROTOTYPE */
void executor(char **argv);
/* STRING PROTOTYPES */

char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

/* PATH_FINDER PROTOTYPE */

char *path_name(char *file_name);

#endif /* MAIN_H */
