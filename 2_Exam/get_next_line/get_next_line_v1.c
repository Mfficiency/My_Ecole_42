/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfficiency <mfficiency@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:04 by mfficiency        #+#    #+#             */
/*   Updated: 2021/11/30 13:25:23 by mfficiency       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v1.h"

char	*get_next_line(int fd)
{	
    static char *str;
    char        buf[BUFFER_SIZE + 1];
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
        }
    }
    
}