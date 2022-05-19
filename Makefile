SOURCES = 	ft_printf.c ft_printf_utils_1.c ft_printf_hexa.c ft_utoa.c \
			ft_printf_utils_2.c
NAME = libftprintf.a
LIBFT = ./libft/libft.a
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
FLAG = -g -Werror -Wextra -Wall
CC = gcc

all: ${NAME}

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
					@ mkdir -p objs
					@ ${CC} ${FLAG} -c -o $@ $<


${NAME}: ${OBJS} ${LIBFT}
		@ cp ${LIBFT} .
		@ mv libft.a ${NAME}
		@ ar -rcs ${NAME} ${OBJS}

${LIBFT}:
		@ make -C ./libft

tt: 	${NAME}
		@ gcc main.c -L. -lftprintf && ./a.out

clean:
		@ rm -rf ${OBJS_PATH}

fclean: clean
		@ make fclean -C ./libft
		@ rm -f ${NAME} *.a

re:	clean all

.PHONY: all clean fclean re

val: ${NAME}
	gcc -g main.c -L. -lftprintf && valgrind --leak-check=full ./a.out

norma:
	norminette ${SRCS}
		


