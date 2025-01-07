CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft/inc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = double_lst.c \
	  list_addition.c \
	  list_manipulation.c \
	  list_utils.c \
	  main.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = push_swap

.PHONY: all clean fclean re libft

all: libft $(NAME)

# Build the main executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/project.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -c $< -o $@

# Build libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files and libft
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# Fully clean the project
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

