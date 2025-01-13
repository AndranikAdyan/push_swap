/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:14:28 by andranik          #+#    #+#             */
/*   Updated: 2025/01/13 19:51:13 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a, int mess)
{
	t_stack	*tmp;

	if (!(*a))
		return (0);
	tmp = *a;
	while (tmp && tmp->next)
	{
		swap_data(tmp->data, tmp->next->data);
		tmp = tmp->next;
	}
	if (mess)
		ft_putstr_fd("ra", 1);
	return (1);
}

int	rb(t_stack **b, int mess)
{
	t_stack	*tmp;

	if (!(*b))
		return (0);
	tmp = *b;
	while (tmp && tmp->next)
	{
		swap_data(tmp->data, tmp->next->data);
		tmp = tmp->next;
	}
	if (mess)
		ft_putstr_fd("ra", 1);
	return (1);
}

int	rr(t_stack **a, t_stack **b, int mess)
{
	if (ra(a, 0) && rb(b, 0))
	{
		if (mess)
			ft_putstr_fd("ra", 1);
		return (1);
	}
	return (0);
}
