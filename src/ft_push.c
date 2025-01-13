/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:13:45 by andranik          #+#    #+#             */
/*   Updated: 2025/01/13 19:31:39 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_stack(t_stack **stack, int num, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(12);
	new_node->data = (t_data*)malloc(sizeof(t_data));
	if (!new_node->data)
		exit(12);
	new_node->data->number = num;
	new_node->data->index = index;
	if (stack && *stack)
	{
		new_node->next = *stack;
		*stack = new_node;
	}
	else
	{
		new_node->next = NULL;
		*stack = new_node;
	}
}


int	pa(t_stack **a, t_stack **b, int mess)
{
	if (*b)
	{
		push_from_stack(a, (*b)->data->number, (*b)->data->index);
		pop(b);
		if (mess)
			ft_putstr_fd("pa", 1);
		return (1);
	}
	return (0);
}

int	pb(t_stack **a, t_stack **b, int mess)
{
	if (*a)
	{
		push_from_stack(b, (*a)->data->number, (*a)->data->index);
		pop(a);
		if (mess)
			ft_putstr_fd("pb", 1);
		return (1);
	}
	return (0);
}
