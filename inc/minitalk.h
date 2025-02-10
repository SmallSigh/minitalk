#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_message_info
{
	char		*message;
	uint32_t	message_length;
	char		current_char;
	size_t		char_index;
	int			receiving_length;
	int			bit;
}				t_message_info;

#endif