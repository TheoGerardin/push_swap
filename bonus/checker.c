#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_sorted(t_list *lsta, t_list *lstb)
{
	while (lstb)
		return (1);
	while (lsta && lsta->next)
	{
		if (lsta->content > lsta->next->content)
			return (1);
		lsta = lsta->next;
	}
	return (0);
}

void	check_instructions(char *str, t_list **lsta, t_list **lstb)
{
	if (!str)
		return (del_nodes(lsta), del_nodes(lstb));
	if (!ft_strcmp(str, "pa\n"))
		bonus_pa(lsta, lstb);
	else if (!ft_strcmp(str, "pb\n"))
		bonus_pb(lsta, lstb);
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate_a(lsta, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate_b(lstb, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		bonus_rrr(lsta, lstb);
	else if (!ft_strcmp(str, "sa\n"))
		swap_a(lsta, 0);
	else if (!ft_strcmp(str, "sb\n"))
		swap_b(lstb, 0);
	else if (!ft_strcmp(str, "ss\n"))
		bonus_ss(lsta, lstb);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a(lsta, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_b(lstb, 0);
	else if (!ft_strcmp(str, "rr\n"))
		bonus_rr(lstb, lsta);
}

void	check_final_stack(t_list **lsta, t_list **lstb, int i, char *str)
{
	if (i == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (str)
		free(str);
	del_nodes(lsta);
	del_nodes(lstb);
}

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	char	*result;

	lsta = NULL;
	lstb = NULL;
	if (argc < 2 || !argv[1][0])
		return (-1);
	if (argc == 2)
	{
		argv = ft_split_ps(argv[1]);
		argc = array_len(argv);
	}
	else
		argv = ft_convert_format(argc, argv);
	if (!fill_lst(&lsta, argc, argv))
		return (-1);
	result = get_next_line(0);
	while ((result == get_next_line(0)))
	{
		check_instructions(result, &lsta, &lstb);
		free(result);
	}
	argc = is_sorted(lsta, lstb);
	return (check_final_stack(&lsta, &lstb, argc, result), 0);
}
