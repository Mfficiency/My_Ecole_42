/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:11:39 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/10 16:56:58 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_x(unsigned int num)
{
	char	*hex;
	int		char_count;

	char_count = 0;
	hex = ft_itoa_base(num, 16);
	hex = ft_str_tolower(hex);
	char_count += ft_putstr_count(hex);
	free(hex);
	return (char_count);
}
