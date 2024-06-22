/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:15:25 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 12:00:49 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

int	rra(t_stack **a)
{
	t_stack	*first;
	t_stack	*tmp;
	int		data_tmp;

	if (*a)
	{
		first = *a;
		tmp = *a;
	}
	else
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		data_tmp = first->data;
		first->data = tmp->data;
		tmp->data = data_tmp;
		tmp = tmp->next;
	}
	return (1);
}

int	rrb(t_stack **b)
{
	t_stack	*first;
	t_stack	*tmp;
	int		data_tmp;

	if (*b)
	{
		first = *b;
		tmp = *b;
	}
	else
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		data_tmp = first->data;
		first->data = tmp->data;
		tmp->data = data_tmp;
		tmp = tmp->next;
	}
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	if (rra(a) && rrb(b))
		return (1);
	return (0);
}
