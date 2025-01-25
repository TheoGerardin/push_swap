#include "../push_swap.h"

int	lst_size(t_list **lst)
{
	size_t	length;
	t_list	*tmp;

	length = 0;
	tmp = *lst;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}

t_list	*lst_second_to_last(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (!(*lst) || !(*lst)->next)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!(lst))
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = lst_last(*lst);
		last->next = new;
	}
}

int	ft_strlen_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}