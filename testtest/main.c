#include "test.h"

t_list	*ft_lstnew(int content)
{
	t_list	*first;

	first = malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->content = content;
	first->next = NULL;
	first->prev = NULL; // check
	return (first);
}

void	print_list(t_list *a)
{
		printf("%ld", a->content);
}

void test_1(t_list **a)
{
	t_list	*tmp;

	tmp =(*a);
	tmp->content = 1;
}

void test(t_list **a)
{
	test_1(a);
}

void	bis(t_list **a, t_list *b)
{
	//ft_push_swap(argv, &a, &b);
	//*b = *a;
	test(a);

}

int	main (int argc, char** argv) //commencer par faire la size et la fonction size renverra vers la fonction de trie efficace donc : 3, 5 ou plus
{
	t_list	*a;
	t_list	*b;
	int i;

	a = NULL;
	b = NULL;
	i = 2;
	a = ft_lstnew(i);
	bis(&a, b);
	print_list(a);

}



