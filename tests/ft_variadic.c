/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:48:30 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/08 11:48:48 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// youtube: https://www.youtube.com/watch?v=S-ak715zIIE

#include <stdio.h>
#include <stdarg.h>

void print_ints(int num, ...)
{
	va_list args;

	va_start(args, num);
	for (int i = 0; i < num; i++)
	{
		int value = va_arg(args, int);
		printf("%d: %d\n", i, value);
	}
	va_end(args);
}

int main(void)
{
	print_ints(2, 2, 1);
	print_ints(2, 45452, 991);
	print_ints(2, 72, 71);
}