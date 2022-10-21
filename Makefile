NAME = push_swap

SRC =   ft_little_sort.c ft_split.c ft_lst_utils.c push.c ft_utils.c rotate.c ft_swap_tab.c reverse_rotate.c swap.c ft_big_sort.c ft_cout.c ft_deplacement.c ft_check.c ft_pos.c ft_utils_little_sort.c
		
OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra -g3

${NAME} : ${OBJ}
	$(CC) ${FLAGS} $(OBJ) -o ${NAME}

%.o : %.c
	gcc ${FLAGS} -c $< -o $@

all : ${NAME}

clean :
	rm -f ${OBJ} 

fclean : clean
	rm -f ${NAME}
re : fclean all

.PHONY: all clean fclean re