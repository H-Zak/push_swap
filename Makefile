NAME = Push.a

SRC =  ft_strlen.c \ ft_split.c ft_swap.c \ ft_lastadd_back.c \ ft_lastnew.c \ 
ft_atoi.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}
	
${NAME} : ${OBJ}
	ar rc ${NAME} $^

%.o : %.c
	gcc ${CFLAGS} -o $@ -c $<

clean :
	rm -f ${OBJ} 

fclean : clean
	rm -f ${NAME}
re : fclean all

.PHONY: all clean fclean re bonus