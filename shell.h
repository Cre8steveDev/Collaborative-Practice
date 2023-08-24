#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/**Error printing functions */
void zerror(char *prog, int count, char *cmd);
void _puts(char *str);
int _putchar(char c);
void free_array(int argc, char *argv[]);

/*Global Variable*/
extern char **environ;
int exit_num;
int execn(char **args, char **argv);
int extra_execn(char **args, char **argv, char *fullcmd);
char *get_full_path(char *paths, char *cmd);
char *_getpath(void);
void fix_comments(char *buffer);
int handle_builtins(char **args, char *progname, char *buffer);

char **tokenizah(char *string);

#endif
