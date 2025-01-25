#include "../push_swap.h"

void	sort_stack_a_to_b(t_list **lsta, t_list **lstb, int *array,
			t_data *data)
{
	while (*lsta)
	{
		if (lst_size(lsta) == 1)
			push_b(lsta, lstb);
		while (lst_size(lstb) < data->end - data->start)
		{
			if (!((*lsta)->content < array[data->end]
					&& (*lsta)->content >= array[data->start]))
				rotate_a(lsta, 1);
			else
			{
				push_b(lsta, lstb);
				if ((*lstb)->content < array[data->median])
					rotate_b(lstb, 1);
			}
		}
		data->start -= data->size;
		if (data->start < 0)
			data->start = 0;
		data->end += data->size;
		if (data->end >= data->t_num)
			data->end = data->t_num - 1;
	}
}

void	sort_stack_b_to_a(t_list **lsta, t_list **lstb, int *array,
			t_data *data)
{
	data->unorder_num = 0;
	data->max = lst_size(lstb) - 1;
	while (*lstb)
	{
		if ((*lstb) && find_highest_nb(*lstb) == array[data->max])
			check_highest_nb(lsta, lstb, array, data);
		else
			check_unsorted_nb(lsta, data);
	}
	while (data->unorder_num != 0)
	{
		reverse_rotate_a(lsta, 1);
		data->unorder_num--;
	}
}

void	check_highest_nb(t_list **lsta, t_list **lstb, int *array, t_data *data)
{
	if ((*lstb)->content == array[data->max])
	{
		push_a(lsta, lstb);
		data->max--;
		if ((*lsta)->next && (*lsta)->content > (*lsta)->next->content)
		{
			swap_a(lsta, 1);
			data->max--;
		}
	}
	else if ((*lstb)->content == array[data->max - 1])
		push_a(lsta, lstb);
	else
		check_not_max_num(lsta, lstb, data);
}

void	check_unsorted_nb(t_list **lsta, t_data *data)
{
	if (data->unorder_num > 0)
	{
		reverse_rotate_a(lsta, 1);
		data->unorder_num--;
		data->max--;
	}
}

void	check_not_max_num(t_list **lsta, t_list **lstb, t_data *data)
{
	if (data->unorder_num == 0 || (*lstb)->content > lst_last(*lsta)->content)
	{
		push_a(lsta, lstb);
		rotate_a(lsta, 1);
		data->unorder_num++;
	}
	else
	{
		if (find_highest_index(*lstb, find_highest_nb(*lstb))
			< lst_size(lstb) / 2)
			rotate_b(lstb, 1);
		else
			reverse_rotate_b(lstb, 1);
	}
}
