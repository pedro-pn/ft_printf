SRCS = 	ft_printf.c ft_printf_utils_1.c ft_printf_hexa.c ft_utoa.c \
		ft_printf_utils_2.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

LIBFT = ./libft/libft.a

FLAG = -Werror -Wextra -Wall

all: ${NAME}

%.o:%.c
	${CC} ${FLAG} -fPIE -c -o $@ $^

${NAME}: ${OBJS} ${LIBFT}
		cp ${LIBFT} .
		mv libft.a ${NAME}
		ar -rcs ${NAME} ${OBJS}

${LIBFT}:
		make -C ./libft

tt: ${NAME}
	gcc main.c -L. -lftprintf && ./a.out

clean:
		make fclean -C ./libft
		rm *.o *.a

re:	clean all

val: ${NAME}
	gcc -g main.c -L. -lftprintf && valgrind --leak-check=full ./a.out

		


