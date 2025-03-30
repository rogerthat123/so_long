CC = cc -g
FLAGS = -Wall -Wextra -Werror
NAME = so_long
LIB_NAME = so_long.a
MLX = ./mlx/libmlx_Linux.a
MLXDIR = ./mlx
MLX_FLAGS = -lXext -lX11 -lm
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

SRCS = main.c \
	./map_check/map_check.c ./map_check/map_utils.c ./map_check/map_utils2.c \
	./utils/utils.c ./game/init.c ./game/init_utils.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all: $(LIB_NAME) $(NAME)

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(LIB_NAME)
	ar -rcs $(LIB_NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)


$(NAME): $(OBJS) $(LIB_NAME) $(MLX)
	$(CC) $(FLAGS) $(OBJS) $(LIB_NAME) $(MLX) -o $(NAME) $(MLX_FLAGS)

clean:

	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR) clean
	rm -f $(LIB_NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re



