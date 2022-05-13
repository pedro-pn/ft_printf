SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

LIBFT = ./Libft/libft.a

FLAG = -Werror -Wextra -Wall

all: ${NAME}

%.o:%.c
	${CC} ${FLAG} -fPIE -c -o $@ $^

${NAME}: ${OBJS} ${LIBFT}
		cp ${LIBFT} .
		mv libft.a ${NAME}
		ar -rcs ${NAME} ${OBJS}

${LIBFT}:
		make -C ./Libft

tt: ${NAME}
	gcc main.c -L. -lftprintf && ./a.out

clean:
		rm *.o *.a

		


