/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_iota.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:55:56 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/10 16:38:55 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// returns amount of digits in a given number
static unsigned int	ft_nbdigits(unsigned int nb)
{
	unsigned int	unsigned_nb;
	unsigned int	res;

	if (nb < 0)
		unsigned_nb = nb * -1;
	else
		unsigned_nb = nb;
	res = 1;
	while (unsigned_nb >= 10)
	{
		res++;
		unsigned_nb /= 10;
	}
	return (res);
}

// returns amount of digits in a given number + negative
static int	ft_intlen(unsigned int n)
{
	unsigned int	len;

	if (n < 0)
		len = ft_nbdigits(n) + 1;
	else
		len = ft_nbdigits(n);
	return (len);
}

// same as itoa but for unsigned numbers
char	*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	len = ft_intlen(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	res[len--] = '\0';
	while (nbr > 0)
	{
		res[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (len == 0 && res[1] == '\0')
		*(res + len) = '0';
	else if (len == 0 && res[1] != '\0')
		*(res + len) = '-';
	return (res);
}
