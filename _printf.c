#include "main.h"
#include <unistd.h>

void _buffer(char buffer[], int *index_buffer);









void _buffer(char buffer[], int *index_buffer)
{
	if (*index_buffer > 0)
		write(1, &buffer[0], *index_buffer);

	*index_buffer = 0;
}
