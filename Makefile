NAME = push_swap

SRC =   ft_atoi.c ft_split.c ft_lastadd_back.c ft_lastnew.c push.c ft_atol.c ft_lstadd_front.c ft_sort_int_tab.c rotate.c ft_swap_tab.c reverse_rotate.c ft_stack_size.c swap.c ft_lstsize_bonus.c
		
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