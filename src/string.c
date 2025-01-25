#include "../push_swap.h"

char	*ft_strncpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (NULL);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '\t'))
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
	}
	return (count);
}

void	check_string(char **new, char *str)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = -1;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		if (j < i)
		{
			new[++word] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!new[word])
			{
				ft_free_array(new);
				return ;
			}
			ft_strncpy(new[word], &str[j], i - j);
		}
	}
	new[word + 1] = NULL;
}

char	**ft_split_ps(char *str)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!new)
		return (NULL);
	check_string(new, str);
	return (new);
}