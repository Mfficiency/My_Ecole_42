/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:09:05 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/08 12:03:35 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include "testlib.h"

char	*ft_chk_rslt(int expected, int result)
{
	if (expected == result)
		return ("OK");
	return ("NOT OK");
}

void	ft_show(char input, int lib_result, int ft_result)
{
	printf("test: %c, ", input);
	printf("result: %d, ", ft_result);
	printf("%s\n", ft_chk_rslt(lib_result, ft_result));
}

int	ft_test(int show, char *test_arr, int (*ft_cmp)(int), int (*lib_cmp)(int))
{
	int		lib_result;
	int		ft_result;

	while (*test_arr)
	{
		lib_result = (*lib_cmp)(*test_arr); 
		ft_result = (*ft_cmp)(*test_arr); 
		if (show)
			ft_show(*test_arr, lib_result, ft_result);
		if (lib_result != ft_result)
			return (0);
		test_arr++;
	}
	return (1);
}

void	red(void)
{
	printf("\033[1;31m");
}

void	reset(void)
{
	printf("\033[0m");
}

int	printf_test(void)
{
	char	c;
	char	*str;
	int		d;

	c = 'a';
	str = "Hello";
	d = 1;
	printf("og: %c - ft: ", c);
	ft_printf(c);
}

//*
int	main(void)
{
	red();
	printf("\nvvv--------------vvv\n");
	reset();
	ft_printf("test %d\n", 2);
	//printf("output: %d\n", printf("xxxa\n"));
	red();
	printf("^^^--------------^^^\n\n");
	reset();
	return (0);
}
//*/