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
void print_unsigned_int(char buffer[], int *index_buffer, unsigned int n,
		    int *num_chars);
void print_octal(char buffer[], int *index_buffer, unsigned int n,
		 int *num_chars);
void print_hex(char buffer[], int *index_buffer, unsigned int n,
	       int *num_chars, int uppercase);
void print_special_string(char buffer[], int *index_buffer, const char *str,
			  int *num_chars);
void printing_hex_for_special_string(char buffer[], int *index_buffer,
				      unsigned int n, int *num_chars, int uppercase);
void print_pointer(char buffer[], int *index_buffer, void *ptr,
		   int *num_chars);


#endif /* MAIN_H */
