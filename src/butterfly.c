/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:54:12 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/19 19:25:54 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node_to_up_for_b(t_stack **stack, size_t index)
{
	size_t	size;
	size_t	i;
	t_stack	*tmp;

	size = ft_lstsize(*stack);
	i = 0;
	tmp = *stack;
	while (tmp && tmp->data->index != index)
	{
		tmp = tmp->next;
		++i;
	}
	if (i > size / 2)
		while ((*stack)->data->index != index)
			rrb(stack, 1);
	else
		while ((*stack)->data->index != index)
			rb(stack, 1);
}

void	push_from_b(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*b);
	while (size > 0)
	{
		move_node_to_up_for_b(b, --size);
		pa(a, b, 1);
	}
}

void	butterfly(t_stack **a, t_stack **b)
{
	size_t	n;
	size_t	counter;

	n = get_n(ft_lstsize(*a));
	counter = 0;
	while ((*a))
	{
		if ((*a)->data->index <= counter)
		{
			pb(a, b, 1);
			rb(b, 1);
			counter++;
		}
		else if ((*a)->data->index > counter && \
			(*a)->data->index <= counter + n)
		{
			pb(a, b, 1);
			counter++;
		}
		else
			ra(a, 1);
	}
	push_from_b(a, b);
}
