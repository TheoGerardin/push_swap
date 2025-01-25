#include "../push_swap.h"

void	swap_a(t_list **lsta, int print)
{
	t_list	*temp;

	if (!(*lsta) || !(*lsta)->next)
		return ;
	temp = (*lsta);
	(*lsta) = temp->next;
	temp->next = (*lsta)->next;
	(*lsta)->next = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **lstb, int print)
{
	t_list	*temp;

	if (!(*lstb) || !(*lstb)->next)
		return ;
	temp = (*lstb);
	(*lstb) = temp->next;
	temp->next = (*lstb)->next;
	(*lstb)->next = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	swap_ab(t_list **lsta, t_list **lstb)
{
	if (!(*lsta) || !(*lstb))
		return ;
	swap_a(lsta, 0);
	swap_b(lstb, 0);
}
