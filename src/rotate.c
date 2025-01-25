#include "../push_swap.h"

void	rotate_a(t_list **lsta, int print)
{
	t_list	*first_to_last;
	t_list	*second_to_last;

	if (!(*lsta) || !(*lsta)->next)
		return ;
	first_to_last = *lsta;
	second_to_last = lst_last(*lsta);
	*lsta = first_to_last->next;
	second_to_last->next = first_to_last;
	first_to_last->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list	**lstb, int print)
{
	t_list	*first_to_last;
	t_list	*second_to_last;

	if (!(*lstb) || !(*lstb)->next)
		return ;
	first_to_last = (*lstb);
	second_to_last = lst_last(*lstb);
	(*lstb) = first_to_last->next;
	second_to_last->next = first_to_last;
	first_to_last->next = NULL;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rotate(t_list **lstb, t_list **lsta)
{
	if (!(*lsta) || !(*lstb) || !(*lsta)->next || !(*lstb)->next)
		return ;
	write(1, "rr\n", 3);
	rotate_a(lsta, 0);
	rotate_b(lstb, 0);
}
