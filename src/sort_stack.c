/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:58:25 by aadyan            #+#    #+#             */
/*   Updated: 2025/01/16 02:11:20 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sa(a, 1);
	else if (size <= 12)
		sort_under_12(*a, *b);
	else
		butterfly(a, b);
}
