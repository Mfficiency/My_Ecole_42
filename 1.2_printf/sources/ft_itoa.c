/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:55:56 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/11 11:31:31 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	ft_nbdigits(int nb, int base)
{
	unsigned int	res;

	res = 0;
	while (nb != 0)
	{
		nb /= base;
		res++;
	}
	return (res);
}

char	*ft_itoa(int num, int base)
{
	char	*res;
	int		len;
	int		nbr;

	nbr = num;
	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_nbdigits(num, base);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len--] = '\0';
	while (nbr != 0)
	{
		if ((nbr % base) < 10)
			res[len] = (nbr % base) + 48;
		else
			res[len] = (nbr % base) + 55;
		nbr /= base;
		len--;
	}	
	return (res);
}
