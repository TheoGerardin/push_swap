#include "../push_swap.h"

void	add_node(t_list **lst, int content)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	sort_lst(t_list **lsta, t_list **lstb, int *array, t_data *data)
{
	if (is_sorted(*lsta, *lstb))
	{
		if (lst_size(lsta) == 2)
			sort_two_numbers(lsta);
		else if (lst_size(lsta) == 3)
			sort_three_numbers(lsta);
		else if (lst_size(lsta) <= 5)
			sort_five_numbers(lsta, lstb);
		else
		{
			data->t_num = lst_size(lsta);
			data->median = (data->t_num / 2);
			if (data->t_num <= 30)
				data->n = 5;
			else if (data->t_num <= 150)
				data->n = 8;
			else
				data->n = 18;
			data->size = (data->t_num / data->n);
			data->start = data->median - data->size;
			data->end = data->median + data->size;
			sort_stack_a_to_b(lsta, lstb, array, data);
			sort_stack_b_to_a(lsta, lstb, array, data);
		}
	}
}

void	bubble_sort(int *arr, int arr_len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{
			if ((j + 1 < arr_len) && arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*sort_array(t_list *lst)
{
	size_t	i;
	int		*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (lst_size(&lst)));
	while (lst)
	{
		arr[i] = lst->content;
		lst = lst->next;
		i++;
	}
	bubble_sort(arr, i);
	return (arr);
}
