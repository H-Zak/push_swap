NAME = push_swap

SRC =   ft_little_sort.c ft_split.c ft_lst_utils.c push.c ft_utils.c ft_sort_int_tab.c rotate.c ft_swap_tab.c reverse_rotate.c swap.c ft_big_sort.c ft_cout.c ft_deplacement.c
		
OBJ = ${SRC:.c=.o}

FLAGS = -g3

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