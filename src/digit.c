#include "../push_swap.h"

int	check_is_digit(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[0] == '-' && str[1] >= '0' && str[1] <= '9')))
			return (-1);
		i++;
	}
	return (0);
}

int	check_digit_size(long long digit)
{
	if (digit > INT_MAX || digit < INT_MIN)
		return (-1);
	return (0);
}

long long	str_conversion(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i + 1] == 43 || str[i + 1] == 45)
			return (-1);
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_atoi_ps(char *str)
{
	long long	result;
	int			digit;
	long long	digit_size;

	result = 0;
	digit = check_is_digit(str);
	if (digit == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	result = str_conversion(str);
	digit_size = check_digit_size(result);
	if (digit_size == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return ((int)result);
}
