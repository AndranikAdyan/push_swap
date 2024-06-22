/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:13:45 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 11:50:47 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

int	pa(t_stack **a, t_stack **b)
{
	int	data;

	if (*b)
	{
		data = (*b)->data;
		pop(b);
		push(a, data);
		return (1);
	}
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	int	data;

	if (*a)
	{
		data = (*a)->data;
		pop(a);
		push(b, data);
		return (1);
	}
	return (0);
}
