CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I printf

SRC_DIR = .
OBJ_DIR = o_files
PRINTF_DIR = printf

CLIENT_SRC = client.c
SERVER_SRC = server.c
PRINTF_SRC =	$(PRINTF_DIR)/ft_printf.c \
				$(PRINTF_DIR)/printBasics.c \
				$(PRINTF_DIR)/printHex.c \
				$(PRINTF_DIR)/printNumbers.c

CLIENT_OBJ = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRC:.c=.o))
SERVER_OBJ = $(addprefix $(OBJ_DIR)/, $(SERVER_SRC:.c=.o))
PRINTF_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(PRINTF_SRC:.c=.o)))

CLIENT_EXE = client
SERVER_EXE = server

all: $(CLIENT_EXE) $(SERVER_EXE)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(CLIENT_EXE): $(CLIENT_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_EXE): $(SERVER_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(CLIENT_EXE) $(SERVER_EXE)

re: fclean all

.PHONY: all clean fclean re