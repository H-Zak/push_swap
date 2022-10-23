# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbily <fbily@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 18:36:51 by fbily             #+#    #+#              #
#    Updated: 2022/10/23 18:52:31 by fbily            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC_PATH = ./srcs/
SRC =   ft_little_sort.c ft_split.c ft_lst_utils.c push.c ft_utils.c rotate.c ft_swap_tab.c reverse_rotate.c swap.c ft_big_sort.c ft_cout.c ft_deplacement.c ft_check.c ft_pos.c ft_utils_little_sort.c
SRCS = $(addprefix ${SRC_PATH}, ${SRC})
		
OBJ_PATH	= obj/
OBJ = ${SRC:.c=.o}
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

DEPS = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

INC = -I./includes/

FLAGS = -Wall -Werror -Wextra -MMD -MP -g3

${NAME} : ${OBJS}
	gcc ${FLAGS} $(OBJS) -o ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	gcc ${FLAGS} ${INC} -o $@ -c $<
	
all : ${NAME}

clean :
	rm -rf ${OBJ_PATH}

fclean : clean
	rm -rf ${NAME}
	
re : fclean all

-include ${DEPS}

.SECONDARY : $(OBJ)

.PHONY: all clean fclean re