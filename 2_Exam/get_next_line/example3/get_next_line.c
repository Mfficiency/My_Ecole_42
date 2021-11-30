/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:08:55 by mm          #+#    #+#             */
/*   Updated: 2021/11/05 12:50:13 by mm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*ft_send_line(char **str, int check)
{
	char		*line;
	int			len;

	line = ft_substr(*str, 0, check + 1, 0);
	len = (ft_strlen(*str) - ft_strlen(line));
	*str = ft_substr(*str, check + 1, len, 1);
	return (line);
}

static char	*ft_send_last_line(char *str, int str_count, int buf_pos, int count)
{
	static int	i = 0;

	if ((buf_pos == 0 && (ft_strcmp(str, "") == 0)) || buf_pos == -1
		|| (count++ == 1 && buf_pos == 0))
	{
		i = 1;
		free(str);
	}
	if (i == 1)
	{
		str_count = 1;
		buf_pos = 1;
		count = 1;
		i = 0;
		return (NULL);
	}
	i = 1;
	str_count = 1;
	buf_pos = 1;
	count = 1;
	return (str);
}

// duplicate 
static char	*ft_str_loader(char **str, int str_count)
{
	if (str_count == 1)
	{
		*str = ft_strdup("", 0);
		str_count = 0;
	}
	else
	{
		*str = ft_strdup(*str, 1);
	}
	return (*str);
}

/*
char	*get_next_line(int fd)
{	
	static char	*str;
	char		buf[BUFFER_SIZE + 1];	// +1 for '\0'
	static int	ints[] = {1, 1, 1};		// 0 = str, 1 = check buffer, 2 = count
	int			check;					

	if (fd < 0 || BUFFER_SIZE <= 0) 	// check if fd is valid
		return (NULL);
	str = ft_str_loader(&str, ints);
	while (buf_pos > 0)
	{
		buf_pos = read(fd, buf, BUFFER_SIZE);
		if (buf_pos == -1 || (count++ == 1 && buf_pos == 0))
			return (ft_send_last_line(str, ints));
		buf[buf_pos] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_check_newline(buf) != -1)	// are we at the end of a line?
		{
			check = ft_check_newline(str);	// get the index of the newline
			return (ft_send_line(&str, check)); // return the line at the index
		}
	}
	check = ft_check_newline(str);
	if (check != -1)
		return (ft_send_line(&str, check));
	return (ft_send_last_line(str, ints));
}
*/

char	*get_next_line(int fd)
{	
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	static int  str_count; // points to the position of the output string
    static int  buf_pos; // points to position of the buffer string
    static int  count;
    int         check;

    str_count = 1;
    buf_pos = 1;
    count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_str_loader(&str, str_count);
	while (buf_pos > 0)
	{
		buf_pos = read(fd, buf, BUFFER_SIZE);
		if (buf_pos == -1 || (count++ == 1 && buf_pos == 0))
			return (ft_send_last_line(str, str_count, buf_pos, count));
		buf[buf_pos] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_check_newline(buf) != -1)
		{
			check = ft_check_newline(str);
			return (ft_send_line(&str, check));
		}
	}
	check = ft_check_newline(str);
	if (check != -1)
		return (ft_send_line(&str, check));
	return (ft_send_last_line(str, str_count, buf_pos, count));
}
