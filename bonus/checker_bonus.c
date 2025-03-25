/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:51:55 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/25 16:47:06 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		return (sa(a, 0), 1);
	else if (ft_strcmp(op, "sb\n") == 0)
		return (sb(b, 0), 1);
	else if (ft_strcmp(op, "ss\n") == 0)
		return (ss(a, b, 0), 1);
	else if (ft_strcmp(op, "pa\n") == 0)
		return (pa(a, b, 0), 1);
	else if (ft_strcmp(op, "pb\n") == 0)
		return (pb(a, b, 0), 1);
	else if (ft_strcmp(op, "ra\n") == 0)
		return (ra(a, 0), 1);
	else if (ft_strcmp(op, "rb\n") == 0)
		return (rb(b, 0), 1);
	else if (ft_strcmp(op, "rr\n") == 0)
		return (rr(a, b, 0), 1);
	else if (ft_strcmp(op, "rra\n") == 0)
		return (rra(a, 0), 1);
	else if (ft_strcmp(op, "rrb\n") == 0)
		return (rrb(b, 0), 1);
	else if (ft_strcmp(op, "rrr\n") == 0)
		return (rrr(a, b, 0), 1);
	return (0);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		if (!do_op(a, b, op))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		free(op);
	}
}
