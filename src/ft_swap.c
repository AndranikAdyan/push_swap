/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:12:09 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 11:50:47 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sa(t_stack **a)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		return (1);
	}
	return (0);
}

int	sb(t_stack **b)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
		return (1);
	}
	return (0);
}

int	ss(t_stack **a, t_stack **b)
{
	if (sa(a) && sb(b))
		return (1);
	return (0);
}
