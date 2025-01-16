/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:41:09 by aadyan            #+#    #+#             */
/*   Updated: 2025/01/16 02:19:35 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data->index < a->next->data->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->next->next->data->index;
	b = stack->next->data->index;
	c = stack->data->index;
	// printf("\n%d %d %d\n", a, b, c);
	if (a > b && a < c)
		sa(&stack, 1);
	else if (a < b && a > c)
		rra(&stack, 1);
	else if (a > b && a > c && b < c)
		sa(&stack, 1); // ----------------
	else if (a > b && a > c && b > c)
	{
		sa(&stack, 1);
		rra(&stack, 1);
	}
	else if (a < b && a < c && b > c)
	{
		sa(&stack, 1);
		ra(&stack, 1);
	}
}
void	move_node_to_up(t_stack **stack, size_t index)
{
	size_t	size;
	size_t	i;
	t_stack	*tmp;

	size = ft_lstsize(*stack);
	i = 0;
	tmp = *stack;
	while (tmp && i != index)
	{
		tmp = tmp->next;
		++i;
	}
	if (i > size / 2)
		while ((*stack)->data->index != index)
			ra(stack, 1);
	else
		while ((*stack)->data->index != index)
			rra(stack, 1);
}

void	sort_under_12(t_stack *a, t_stack *b)
{
	size_t	i;
	int		size;

	size = ft_lstsize(a);
	i = 0;
	while (size > 3)
	{
		move_node_to_up(&a, i);
		pb(&a, &b, 1);
		--size;
		++i;
	}
	// print_stacks(a, b);
	sort_3(a);
	while (b)
		pa(&a, &b, 1);
}
