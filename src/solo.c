#include "../push_swap.h"

void	sort_two_numbers(t_list **lsta)
{
	int	first_index;
	int	second_index;

	if (!(*lsta) || !(*lsta)->next)
		return ;
	first_index = (*lsta)->index;
	second_index = (*lsta)->next->index;
	if (first_index > second_index)
		swap_a(lsta, 1);
}

t_list	*find_highest_node(t_list *lst)
{
	int		max_node;
	t_list	*highest_node;

	if (!lst)
		return (NULL);
	max_node = INT_MIN;
	highest_node = NULL;
	while (lst)
	{
		if (lst->content > max_node)
		{
			max_node = lst->content;
			highest_node = lst;
		}
		lst = lst->next;
	}
	return (highest_node);
}

void	sort_three_numbers(t_list **lsta)
{
	t_list	*highest_node;

	if (!(*lsta))
		return ;
	highest_node = find_highest_node(*lsta);
	if ((*lsta) == highest_node)
		rotate_a(lsta, 1);
	else if ((*lsta)->next == highest_node)
		reverse_rotate_a(lsta, 1);
	if ((*lsta)->content > (*lsta)->next->content)
		swap_a(lsta, 1);
}

void	push_smallests_at_the_bottom(t_list	**lsta)
{
	t_list	*first_smallest_node;
	t_list	*second_smallest_node;
	t_list	*tmp;

	if (!(*lsta) && !(*lsta)->next)
		return ;
	first_smallest_node = find_smallest_node(*lsta);
	second_smallest_node = find_second_smallest_node(*lsta);
	tmp = *lsta;
	tmp = tmp->next;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if ((tmp == second_smallest_node) && (tmp->next == first_smallest_node))
		{
			reverse_rotate_a(lsta, 1);
			reverse_rotate_a(lsta, 1);
		}
	}
}

void	sort_five_numbers(t_list **lsta, t_list **lstb)
{
	t_list	*smallest_node;
	int		count;
	int		stack_size;

	if (!(*lsta) || !(*lsta)->next)
		return ;
	count = 0;
	stack_size = lst_size(lsta);
	push_smallests_at_the_bottom(lsta);
	while (count++ < stack_size - 3)
	{
		smallest_node = find_smallest_node(*lsta);
		while (*lsta != smallest_node)
			rotate_a(lsta, 1);
		push_b(lsta, lstb);
	}
	sort_three_numbers(lsta);
	if (stack_size == 5)
	{
		smallest_node = find_smallest_node(*lstb);
		if (*lstb == smallest_node)
			swap_b(lstb, 1);
		push_a(lsta, lstb);
	}
	push_a(lsta, lstb);
}
