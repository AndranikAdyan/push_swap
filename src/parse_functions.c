/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:42:28 by andranik          #+#    #+#             */
/*   Updated: 2025/01/10 21:01:20 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_range(char *str)
{
	int		i;
	int		len;

	i = 0;
	while (str[i] == 0)
		i++;
	while (str[i++])
	{
		len++;
		if (len >= 11)
			return (1);
	}
	if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	return (0);
}

static int	check_sign(char *str, int j)
{
	if ((str[j] < '0' || str[j] > '9') && str[j] != '+' \
	&& str[j] != '-' && str[j] != ' ')
		return (0);
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j - 1] && str[j - 1] != ' ')
			return (0);
		if (!str[j + 1])
			return (0);
		if (str[j + 1] && (str[j + 1] < '0' || str[j + 1] > '9'))
			return (0);
	}
	return (1);
}

static int	check_symbols(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!check_sign(av[i], j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_dublicates(t_stack **a, int data)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (data == tmp->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_all(char **av, int ac)
{
	int		i;
	int		index;
	char	**arr;

	if (!check_symbols(av, ac))
		return (0);
	index = 1;
	while (index < ac)
	{
		i = 0;
		arr = ft_split(av[index], ' ');
		while (arr[i])
		{
			if (!int_range(arr[i++]))
			{
				free_split(arr);
				return (0);
			}
		}
		free_split(arr);
		++index;
	}
	return (1);
}
