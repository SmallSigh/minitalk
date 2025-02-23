having trouble with Makefile

compile with:

for client_side

cc client.c printf/ft_printf.c printf/printBasics.c printf/printHex.c printf/printNumbers.c -o client

for server_side

cc server.c printf/ft_printf.c printf/printBasics.c printf/printHex.c printf/printNumbers.c -o server

if after receiving message length there is no message, the sleep needs to be adjusted.