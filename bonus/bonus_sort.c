#include "../push_swap.h"

void	bonus_pa(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!(*lstb))
		return ;
	temp = (*lstb);
	(*lstb) = (*lstb)->next;
	temp->next = (*lsta);
	(*lsta) = temp;
}

void	bonus_pb(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!(*lsta))
		return ;
	temp = (*lsta);
	(*lsta) = (*lsta)->next;
	temp->next = (*lstb);
	(*lstb) = temp;
}

void	bonus_rrr(t_list **lsta, t_list **lstb)
{
	if (!(*lsta) || !(*lstb) || !(*lsta)->next || !(*lstb)->next)
		return ;
	reverse_rotate_a(lsta, 0);
	reverse_rotate_b(lstb, 0);
}

void	bonus_ss(t_list **lsta, t_list **lstb)
{
	if (!(*lsta) || !(*lstb))
		return ;
	swap_a(lsta, 0);
	swap_b(lstb, 0);
}

void	bonus_rr(t_list **lstb, t_list **lsta)
{
	if (!(*lsta) || !(*lstb) || !(*lsta)->next || !(*lstb)->next)
		return ;
	rotate_a(lsta, 0);
	rotate_b(lstb, 0);
}
