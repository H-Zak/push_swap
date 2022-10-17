
#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
    long    content;
    int cost_a;
    int cost_b;
    int index;
    int pos;
    int target_pos;
    struct	s_list	*next;
	struct	s_list	*prev; //check not use yet
}			t_list;

#endif
