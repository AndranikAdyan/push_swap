/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:37:21 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 12:04:57 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	n = strlen(s);
	if ((size_t)start >= n)
		return (strdup(""));
	if (len > n - (size_t)start)
		len = n - (size_t)start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		str[i] = s[(size_t)start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
