/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:54:12 by aadyan            #+#    #+#             */
/*   Updated: 2025/01/15 18:41:21 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly(t_stack **a, t_stack **b)
{
	size_t	n;
	size_t	counter;

	n = get_n(ft_lstsize(*a));
	// printf("n = %ld\n", n);
	n = 15;
	counter = 0;

	while ((*a))
	{
		if ((*a)->data->index <= counter)
		{
			pb(a, b, 1);
			rb(b, 1);
			counter++;
		}
		else if ((*a)->data->index <= counter + n)
		{
			pb(a, b, 1);
			counter++;
		}
		else
			ra(a, 1);
	}
}