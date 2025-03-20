/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:13:45 by andranik          #+#    #+#             */
/*   Updated: 2025/03/21 00:05:15 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_stack(t_stack **stack, int num, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(12);
	new_node->data = (t_data *)malloc(sizeof(t_data));
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
	t_stack	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		ft_lstadd_front(a, tmp);
		if (mess)
			ft_putstr_fd("pa\n", 1);
		return (1);
	}
	return (0);
}

int	pb(t_stack **a, t_stack **b, int mess)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_front(b, tmp);
		if (mess)
			ft_putstr_fd("pb\n", 1);
		return (1);
	}
	return (0);
}
