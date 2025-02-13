#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct s_server
{
    int         bit;
    uint32_t    message_length;
    int         receiving_length;
    char        *message;
    size_t      char_index;
    char        current_char;
}   t_server;

void    handle_message_length(t_server *server_info, int received_bit)
{
    server_info->message_length |= (received_bit << (31 - server_info->bit));
    server_info->bit++;
    if (server_info->bit == 32)
    {
        // Print the received message length
        printf("Received message length: %d\n", server_info->message_length);
        
        // Allocate memory for the message based on the received length
        server_info->message = malloc(server_info->message_length + 1);
        if (!server_info->message)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        server_info->message[server_info->message_length] = '\0';
        server_info->receiving_length = 0;
        server_info->bit = 0;
    }
}

void    handle_message_data(t_server *server_info, int received_bit)
{
    server_info->current_char |= (received_bit << (7 - server_info->bit));
    server_info->bit++;
    if (server_info->bit == 8)
    {
        server_info->message[server_info->char_index] = server_info->current_char;
        // printf("%c", server_info->current_char);  // Print the received character
        server_info->char_index++;
        server_info->bit = 0;
        server_info->current_char = 0;
        if (server_info->char_index == server_info->message_length)
        {
            printf("\nFull message received: %s\n", server_info->message);
            free(server_info->message);

            // Reset server state
            server_info->message = NULL;
            server_info->message_length = 0;
            server_info->char_index = 0;
            server_info->bit = 0;
            server_info->current_char = 0;
            server_info->receiving_length = 1;  // Ready to receive new length
        }
    }
}

void    signal_handler(int signum, siginfo_t *info, void *context)
{
    static t_server server_info = {0, 0, 1, NULL, 0, 0};
    int received_bit;

    (void)info;
    (void)context;
    received_bit = (signum == SIGUSR1) ? 1 : 0;
    if (server_info.receiving_length)
        handle_message_length(&server_info, received_bit);
    else
        handle_message_data(&server_info, received_bit);
}

int main(void)
{
    struct sigaction sa;
    pid_t pid;

    pid = getpid();
    printf("Server PID = <%d>\n", pid);

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();  // Wait indefinitely for signals
}
