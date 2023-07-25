#ifndef ALXHELL_H
#define ALXHELL_H

#define DELLS 0
#define DIDA 1
#define BUF 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>
#include <inttypes.h>
#include <errno.h>


extern char **environ;

int number_of_words(char *str, char *separator);
char **fill_argum(char *buf, char *separator);
int prompt(char **buff);
int process(char **argv, char **av, char *buf, int count);
int _strlen(char *str);
char *_strtok(char *string, const char *cutter);
char *find_in_path(char **firstarg);
void free_mem(const unsigned int n, ...);
void free_array(char **arr);
int _strcmp(char *s1, char *s2);
void printenv(void);
int check_built_ins(char **av, char *buff, int count);
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *update_path(char *path, char *pwd);
char *_strstr(char *haystack, char *needle);
char *check_pwd(char **pwd, char **path);
void handler(int sig __attribute__((unused)));
int change_direct(char **av, int count);
void print_err(char **argv, int count, char **av);
int shell_main(char **argv, int count);
int write_int_err(int number);
void clear_screen(void);


/* printf */
#define BUFSIZE 1024
/**
 * struct type - structure type
 * @c: character to check
 * @ptr_f: pointer of function
 */
typedef struct type
{
	char c;
	int (*ptr_f)(va_list);
} type;
int _printf(const char *format, ...);
int _prints(va_list);
int _printc(va_list);
int _printd(va_list);
int write_int(int);
int _printb(va_list);
int _printu(va_list);
int write_unint(unsigned int);
int _printb(va_list);
int _printo(va_list);
int write_octal(unsigned int);
int (*get_spec_funct(char))(va_list);
int _printx(va_list);
int write_x(unsigned long int);
int _printX(va_list);
int write_X(unsigned int);
int _printp(va_list);
int _printS(va_list);
int _printR(va_list);
int _printr(va_list);
int write_rev(char *);
int check_spec(const char *format, int i, va_list arglist);
int _echo(char **av);
int _help(char **av);

#endif
