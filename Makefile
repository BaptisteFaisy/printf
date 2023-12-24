NAME = libftprintf.a
SRCS		= c.c main.c p.c s.c x.c X.c d.c u.c

OBJS = ${SRCS:.c=.o}

CC	= gcc -Wall -Wextra -Werror -L libft.a

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJS} ft_printf.h 
			ar rcs ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)
fclean: clean 
	rm -f $(NAME) libftprintf.a
# fcleanlibft:
# 	cd libft && $(MAKE) fclean
# libft2:
# 	cd libft && $(MAKE) && mv libft.a .. && mv ./libft.h ..

re: fclean all
