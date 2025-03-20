/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:49:39 by aadyan            #+#    #+#             */
/*   Updated: 2025/01/17 23:19:46 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, char sign)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == sign)
			return (str);
		str++;
	}
	return (NULL);
}
