/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:11:39 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/10 14:59:38 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_int(int num)
{
	char	*str;
	int		char_count;

	char_count = 0;
	str = ft_itoa_base(num, 10);
	char_count = ft_putstr_count(str);
	free(str);
	return (char_count);
}
