SOURCES = 	ft_printf.c ft_printf_utils_1.c ft_printf_hexa.c ft_utoa.c \
			ft_printf_utils_2.c
SOURCES_BONUS = ft_printf_bonus.c ft_printf_utils_1_bonus.c \
				ft_printf_hexa_bonus.c ft_utoa_bonus.c \
				ft_printf_utils_2_bonus.c ft_printf_utils_3_bonus.c \
				ft_printf_utils_4_bonus.c
NAME = libftprintf.a
BONUS = libftprintf.a
LIBFT = ./libft/libft.a
SRCS_PATH = srcs
OBJS_PATH = objs
BONUS_PATH = src_bonus
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
SRCS_BONUS = ${addprefix ${BONUS_PATH}/, ${SOURCES_BONUS}}
OBJS_BONUS = ${addprefix ${OBJS_PATH}/, ${SOURCES_BONUS:.c=.o}}
FLAG = -g -Werror -Wextra -Wall
CC = gcc

all: ${NAME}

bonus: ${BONUS}

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
					@ mkdir -p objs
					@ ${CC} ${FLAG} -c -o $@ $<

${OBJS_PATH}/%.o:	${BONUS_PATH}/%.c
					@ mkdir -p objs
					@ ${CC} ${FLAG} -c -o $@ $<

${NAME}: ${OBJS} ${LIBFT}
		@ cp ${LIBFT} .
		@ mv libft.a ${NAME}
		@ ar -rcs ${NAME} ${OBJS}

${BONUS}: ${OBJS_BONUS} ${LIBFT}
		@ cp ${LIBFT} .
		@ mv libft.a ${BONUS}
		@ ar -rcs ${BONUS} ${OBJS_BONUS}

${LIBFT}:
		@ make -C ./libft

tt: 	${NAME}
		@ gcc main.c -L. -lftprintf && ./a.out

ttb: 	${BONUS}
		@ gcc main2.c -L. -lftprintf_bonus && ./a.out

clean:
		@ rm -rf ${OBJS_PATH}

fclean: clean
		@ make fclean -C ./libft
		@ rm -f ${NAME} *.a

re:	clean all

.PHONY: all clean fclean re bonus

val: ${NAME}
	gcc -g main.c -L. -lftprintf && valgrind --leak-check=full ./a.out

norma:
	norminette ${SRCS}
		


