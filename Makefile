# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I inc/libft -I inc/printf -I inc

# Directories
SRC_DIR_CLIENT = client
SRC_DIR_SERVER = server
OBJ_DIR = OBJ_FILES
LIBFT_DIR = inc/libft
PRINTF_DIR = inc/printf

# Source files
CLIENT_SRCS = $(wildcard $(SRC_DIR_CLIENT)/*.c)
SERVER_SRCS = $(wildcard $(SRC_DIR_SERVER)/*.c)
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
PRINTF_SRCS = $(wildcard $(PRINTF_DIR)/*.c)

# Object files
CLIENT_OBJS = $(patsubst $(SRC_DIR_CLIENT)/%.c, $(OBJ_DIR)/%.o, $(CLIENT_SRCS))
SERVER_OBJS = $(patsubst $(SRC_DIR_SERVER)/%.c, $(OBJ_DIR)/%.o, $(SERVER_SRCS))
LIBFT_OBJS = $(patsubst $(LIBFT_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIBFT_SRCS))
PRINTF_OBJS = $(patsubst $(PRINTF_DIR)/%.c, $(OBJ_DIR)/%.o, $(PRINTF_SRCS))

# Executables
CLIENT_EXEC = client_exec  # Renamed to avoid conflict with the client directory
SERVER_EXEC = server_exec  # Renamed to avoid conflict with the server directory

# Rules
all: $(CLIENT_EXEC) $(SERVER_EXEC)

$(CLIENT_EXEC): $(CLIENT_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(SERVER_EXEC): $(SERVER_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR_CLIENT)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR_SERVER)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC)

re: fclean all

.PHONY: all clean fclean re