#include "../push_swap.h"

int	is_sorted(t_list *lsta, t_list *lstb)
{
	t_list	*temp;

	if (lstb)
		return (1);
	if (!lsta)
		return (1);
	temp = lsta;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	char	**result;
	t_data	data;
	int		*tab;

	lsta = NULL;
	lstb = NULL;
	result = NULL;
	if (argc < 2 || !argv[1][0])
		return (-1);
	if (argc == 2)
	{
		result = ft_split_ps(argv[1]);
		argc = array_len(result);
	}
	else
		result = ft_convert_format(argc, argv);
	if (fill_lst(&lsta, argc, result) == NULL)
		return (-1);
	tab = sort_array(lsta);
	sort_lst(&lsta, &lstb, tab, &data);
	del_nodes(&lsta);
	free(tab);
	return (0);
}
