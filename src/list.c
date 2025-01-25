#include "../push_swap.h"

int	check_doublons(t_list *lst)
{
	t_list	*current;
	t_list	*next_node;
	int		doubles;

	current = lst;
	doubles = 0;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (next_node->content == current->content)
				doubles = 1;
			next_node = next_node->next;
		}
		current = current->next;
	}
	if (doubles == 1)
	{
		del_nodes(&lst);
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}

char	*ft_strdup_ps(char *str)
{
	int		i;
	char	*dest;
	int		size;

	i = 0;
	size = ft_strlen_ps(str);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_list	*new_node(int content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->index = -1;
	lst->next = NULL;
	return (lst);
}

char	**ft_convert_format(int ac, char **av)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!result)
		return (NULL);
	result[ac - 1] = NULL;
	while (i < ac - 1)
	{
		result[i] = ft_strdup_ps(av[i + 1]);
		if (!result)
			return (ft_free_array(result), NULL);
		i++;
	}
	return (result);
}

t_list	*fill_lst(t_list **lst, int ac, char **av)
{
	int		i;
	t_list	*new;
	int		num;

	i = 0;
	while (ac > 1)
	{
		num = ft_atoi_ps(av[i]);
		if (num == -1)
			return (ft_free_array(av), del_nodes(lst), NULL);
		new = new_node(num);
		lst_add_back(lst, new);
		ac--;
		i++;
	}
	if (check_doublons(*lst) == -1)
		return (ft_free_array(av), NULL);
	i = 0;
	ft_free_array(av);
	return (*lst);
}
