/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:08:55 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/05 12:50:13 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// count the amount of characters before the newline
static int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_send_line(char *str, char **tmp)
{
	char		*line;
	int			check;
	int			len;

	check = ft_check_newline(str);
	len = 0;
	line = ft_substr(str, 0, check + 1);
	len = (ft_strlen(str) - ft_strlen(line));
	free(*tmp);
	*tmp = ft_substr(str, check + 1, len);
	free(str);
	return (line);
}

static char	*ft_send_last_line(char *str, char **tmp)
{
	static int	i = 0;

	if (i == 1)
	{
		free(*tmp);
		free(str);
		return (NULL);
	}
	i = 1;
	return (str);
}

static char	*ft_str_loader(char **tmp, char **str, int ints[])
{
	if (ints[0] == 1)
	{
		*str = ft_strdup("");
		ints[0] = 0;
	}
	else
		*str = ft_strdup(*tmp);
	return (*str);
}

char	*get_next_line(int fd)
{	
	static char	*tmp;
	char		*str;
	char		buf[BUFFER_SIZE + 1];
	static int	ints[] = {1, 1, 1};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_str_loader(&tmp, &str, ints);
	while (ints[1] > 0)
	{
		ints[1] = read(fd, buf, BUFFER_SIZE);
		if (ints[1] == -1 || (ints[2]++ == 1 && ints[1] == 0)
			|| (ints[1] == 0 && (ft_strcmp(str, "") == 0)))
		{
			free(str);
			return (NULL);
		}
		buf[ints[1]] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_check_newline(str) != -1)
			return (ft_send_line(str, &tmp));
	}
	if (ft_check_newline(str) != -1)
		return (ft_send_line(str, &tmp));
	return (ft_send_last_line(str, &tmp));
}