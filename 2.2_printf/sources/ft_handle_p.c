/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:11:39 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/10 16:56:25 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_p(size_t num)
{
	char	*hex;
	int		char_count;

	char_count = 0;
	hex = ft_itoa_base(num, 16);
	hex = ft_str_tolower(hex);
	char_count += ft_putstr_count("0x");
	char_count += ft_putstr_count(hex);
	free(hex);
	return (char_count);
}
