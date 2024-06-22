/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:14:28 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 12:04:27 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

int	ra(t_stack **a)
{
	int		data_tmp;
	t_stack	*tmp;

	if (*a)
		tmp = *a;
	else
		return (0);
	while (tmp && tmp->next)
	{
		data_tmp = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = data_tmp;
		tmp = tmp->next;
	}
	return (1);
}

int	rb(t_stack **b)
{
	int		data_tmp;
	t_stack	*tmp;

	if (*b)
		tmp = *b;
	else
		return (0);
	while (tmp && tmp->next)
	{
		data_tmp = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = data_tmp;
		tmp = tmp->next;
	}
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	if (ra(a) && rb(b))
		return (1);
	return (0);
}
