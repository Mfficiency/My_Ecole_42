/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:11:39 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/10 16:29:40 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_u(unsigned int num)
{
	char	*str;
	int		char_count;

	char_count = 0;
	str = ft_unsigned_itoa(num);
	char_count = ft_putstr_count(str);
	free(str);
	return (char_count);
}
