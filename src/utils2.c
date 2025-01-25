#include "../push_swap.h"

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i + 1);
}

t_list	*find_smallest_node(t_list *lst)
{
	int		min_node;
	t_list	*smallest_node;

	if (!lst)
		return (NULL);
	min_node = INT_MAX;
	smallest_node = NULL;
	while (lst)
	{
		if (lst->content < min_node)
		{
			min_node = lst->content;
			smallest_node = lst;
		}
		lst = lst->next;
	}
	return (smallest_node);
}

t_list	*find_second_smallest_node(t_list *lsta)
{
	t_list	*first_smallest_node;
	int		second_smallest_value;
	t_list	*second_smallest_node;
	t_list	*tmp;

	first_smallest_node = find_smallest_node(lsta);
	second_smallest_value = INT_MAX;
	second_smallest_node = NULL;
	tmp = lsta;
	while (tmp)
	{
		if ((tmp != first_smallest_node)
			&& (tmp->content < second_smallest_value))
		{
			second_smallest_value = tmp->content;
			second_smallest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (second_smallest_node);
}

int	find_highest_nb(t_list *lst)
{
	int	highest_num;

	highest_num = lst->content;
	lst = lst->next;
	while (lst)
	{
		if (lst->content > highest_num)
			highest_num = lst->content;
		lst = lst->next;
	}
	return (highest_num);
}

int	find_highest_index(t_list *lst, int max)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == max)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}