#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *index_buffer);
void print_char(char buffer[], int *index_buffer, char c, int *num_chars);
void print_string(char buffer[], int *index_buffer, char *s, int *num_chars);
void print_int(char buffer[], int *index_buffer, int n, int *num_chars);
void int_to_str(int n, char str[]);
void print_binary(char buffer[], int *index_buffer, unsigned int n,
		  int *num_chars);


#endif /* MAIN_H */
