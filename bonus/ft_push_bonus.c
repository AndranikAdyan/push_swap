/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:43:11 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/24 19:43:13 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
