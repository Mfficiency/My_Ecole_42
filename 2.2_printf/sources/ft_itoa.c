/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:55:56 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/11 13:31:06 by mmeersma         ###   ########.fr       */
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

static int	ft_intlen(int n, int base)
{
	unsigned int	len;

	if (n < 0)
		len = ft_nbdigits(n, base) + 1;
	else
		len = ft_nbdigits(n, base);
	return (len);
}

char	*ft_itoa(int num, int base)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = num;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr < 0)
		nbr *= -1;
	len = ft_intlen(num, base);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len--] = '\0';
	while (nbr > 0)
	{
		res[len--] = nbr % base + '0';
		nbr /= base;
	}
	if (len == 0 && res[1] == '\0')
		*(res + len) = '0';
	else if (len == 0 && res[1] != '\0')
		*(res + len) = '-';
	return (res);
}
