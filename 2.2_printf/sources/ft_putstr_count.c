/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:58:48 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/10 16:58:58 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_count(char *str)
{
	int		char_count;

	char_count = 0;
	if (!str)
		str = ("(null)");
	while (*str)
	{
		write(1, str, 1);
		str++;
		char_count++;
	}
	return (char_count);
}
