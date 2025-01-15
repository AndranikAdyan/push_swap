/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:07:49 by aadyan            #+#    #+#             */
/*   Updated: 2025/01/14 21:29:20 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	num;

	if (nb == 0 || nb == 1)
		return (1);
	num = 1;
	while (num <= nb / 2)
	{
		if (num * num == nb)
			return (num);
		else if (num * num > nb)
			return (num - 1);
		++num;
	}
	return (-1);
}

int	ft_log2(int n)
{
	int	count;
	int	num;

	num = 1;
	count = 0;
	while (num < n)
	{
		++count;
		num *= 2;
	}
	return (count);
}

int	get_n(int n)
{
	return (ft_sqrt(n) + ft_log2(n) - 1);
}