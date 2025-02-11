#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

typedef struct s_server
{
	int			bit;
	uint32_t	message_length;
	int			receiving_length;
	char		*message;
	size_t		char_index;
	char		current_char;
}				t_server;

#endif