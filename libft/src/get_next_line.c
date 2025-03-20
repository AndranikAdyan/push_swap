/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:19:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/20 20:01:41 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	read_line(int fd, char **str)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			break ;
		buf[bytes] = 0;
		if (bytes == 0)
			break ;
		*str = ft_strjoin_free(*str, buf);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buf);
}

static char	*ft_remainder(char *str)
{
	int		i;
	int		j;
	char	*remainder;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	remainder = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!remainder)
		return (NULL);
	j = -1;
	while (str[i] && str[++i])
		remainder[++j] = str[i];
	remainder[++j] = 0;
	free(str);
	return (remainder);
}

static char	*ft_cutstr(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		s[i] = str[i];
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str[65535];
	char		*s;

	if ((fd != 0 && fd < 2) || BUFFER_SIZE <= 0)
		return (0);
	read_line(fd, &str[fd]);
	s = ft_cutstr(str[fd]);
	if (s && !*s)
	{
		free(s);
		return (NULL);
	}
	str[fd] = ft_remainder(str[fd]);
	return (s);
}
