CC	= gcc

RM	= rm -f

NAME	= libft.a

SRCS = 	ft_memset.c\
				ft_basics_utils.c\
				ft_basics_utils_two.c\
				ft_convert_xxup.c\
				ft_convert.c\
				ft_parse.c\
				ft_printf.c\
				ft_utils.c\
				ft_strtrim.c\
				ft_strmapi.c\
				ft_itoa.c\
				ft_putnbr_fd.c\
				ft_putendl_fd.c\
				ft_putstr_fd.c\
				ft_putchar_fd.c\
				ft_split.c\
				ft_strjoin.c\
				ft_substr.c\
				ft_strdup.c\
				ft_calloc.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memmove.c\
				ft_strlen.c\
				ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_strnstr.c\
				ft_strncmp.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_atoi.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_toupper.c\
				ft_tolower.c\

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -g -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
