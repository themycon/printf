#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *index_buffer);


#endif /* MAIN_H */
