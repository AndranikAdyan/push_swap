/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:15:25 by andranik          #+#    #+#             */
/*   Updated: 2025/03/20 21:40:52 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rra(t_stack **a, int mess)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!(*a))
		return (0);
	first = *a;
	tmp = (*a)->next;
	while (tmp)
	{
		swap_data(first->data, tmp->data);
		tmp = tmp->next;
	}
	if (mess)
		ft_putstr_fd("rra\n", 1);
	return (1);
}

int	rrb(t_stack **b, int mess)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!(*b))
		return (0);
	first = *b;
	tmp = (*b)->next;
	while (tmp)
	{
		swap_data(first->data, tmp->data);
		tmp = tmp->next;
	}
	if (mess)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr(t_stack **a, t_stack **b, int mess)
{
	if (rra(a, 0) && rrb(b, 0))
	{
		if (mess)
			ft_putstr_fd("rrr\n", 1);
		return (1);
	}
	return (0);
}
