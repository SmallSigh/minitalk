#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void	send_bit(pid_t server_pid, int bit)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	usleep(100);  // Small delay to prevent signals from being lost
}

void	send_number(pid_t server_pid, int num)
{
	int	bit;

	for (bit = 31; bit >= 0; bit--)  // Send as a 32-bit integer
		send_bit(server_pid, (num >> bit) & 1);
}

void	send_message(pid_t server_pid, char *message)
{
	int	i;
	int	bit;

	i = 0;
	while (message[i])
	{
		for (bit = 7; bit >= 0; bit--)  // Send each character as 8 bits
			send_bit(server_pid, (message[i] >> bit) & 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}

	pid_t	server_pid = atoi(argv[1]);
	int		message_length = 0;

	while (argv[2][message_length])  // Count message length
		message_length++;

	printf("Sending length: %d\n", message_length);
	send_number(server_pid, message_length);  // Send message length in binary

	printf("Sending message: %s\n", argv[2]);
	send_message(server_pid, argv[2]);  // Send actual message in binary

	return (0);
}
