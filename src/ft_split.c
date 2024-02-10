/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:23:02 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 11:58:19 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	words_count(char *str, char sign)
{
	int		i ;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sign)
			++i;
		if (str[i] && str[i] != sign)
			++count;
		while (str[i] && str[i] != sign)
			++i;
	}
	return (count);
}

static char	**fill_str(char *str, char sign)
{
	int		start;
	int		index;
	char	**arr;
	int		i;
	int		count;

	count = words_count(str, sign);
	arr = malloc ((count + 1) * sizeof(char *));
	i = 0;
	index = 0;
	while (str[i])
	{
		while (str[i] == sign)
			++i;
		start = i;
		while (str[i] && str[i] != sign)
			++i;
		arr[index] = ft_substr(str, start, i - start);
		if (arr[index] && !arr[index][0])
			free(arr[index]);
		index++;
	}
	arr[count] = '\0';
	return (arr);
}

char	**ft_split(char *str, char sign)
{
	char	**arr;

	arr = fill_str(str, sign);
	return (arr);
}

void	free_split(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}
