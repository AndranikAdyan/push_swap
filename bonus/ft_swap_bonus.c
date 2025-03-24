/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:43:26 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/24 19:43:28 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_data(t_data *data1, t_data *data2)
{
	int		tmp_number;
	size_t	tmp_index;

	tmp_number = data1->number;
	data1->number = data2->number;
	data2->number = tmp_number;
	tmp_index = data1->index;
	data1->index = data2->index;
	data2->index = tmp_index;
}

int	sa(t_stack **a, int mess)
{
	if (*a && (*a)->next)
	{
		swap_data((*a)->data, (*a)->next->data);
		if (mess)
			ft_putstr_fd("sa\n", 1);
		return (1);
	}
	return (0);
}

int	sb(t_stack **b, int mess)
{
	if (*b && (*b)->next)
	{
		swap_data((*b)->data, (*b)->next->data);
		if (mess)
			ft_putstr_fd("sb\n", 1);
		return (1);
	}
	return (0);
}

int	ss(t_stack **a, t_stack **b, int mess)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		swap_data((*a)->data, (*a)->next->data);
		swap_data((*b)->data, (*b)->next->data);
		if (mess)
			ft_putstr_fd("ss\n", 1);
		return (1);
	}
	return (0);
}
