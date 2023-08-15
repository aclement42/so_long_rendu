NAME        	=   so_long

CC          	=   gcc

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find lib/mlx -type d) \
					$(shell find lib/libft -type d)
LIB_DIR			=	lib/libft lib/mlx
OBJ_DIR			=	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

LINUXFLAG	=	-lm -lX11 -lXext

# library -----------------------------------------------------------

LIB			=	ft mlx_Linux

SRC			= 	so_long.c\
				error_walls.c\
				error_map.c\
				error_map2.c\
				get_next_line_bis.c\
				get_next_line_bis_utils.c\
				path_map.c\
				free.c\
				process.c\
				

				
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror -g

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib)) \
				$(LINUXFLAG)


# main part ---------------------------------------------------------

all:
	@make -s $(NAME)

install:
	@$(foreach dir, $(LIB_DIR), make -s -C $(dir) > /dev/null 2>&1;)

re-install:
	@$(foreach dir, $(LIB_DIR), make -s -C $(dir) > /dev/null 2>&1 re;)

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -s -C $(dir) > /dev/null 2>&1 fclean;)

$(NAME): install $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

re:	fclean all

clean:
	@$(foreach file, $(OBJ), rm -rf $(file))

fclean:	clean
	@rm -f $(NAME)

.PHONY: all install re-install re clean flcean