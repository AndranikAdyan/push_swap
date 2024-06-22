/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:21:37 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 11:58:09 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long int	ft_atol(char *num)
{
	long int	res;
	int			i;

	res = 0;
	i = 0;
	while (num[i])
		res = res * 10 + num[i++] - '0';
	return (res);
}
