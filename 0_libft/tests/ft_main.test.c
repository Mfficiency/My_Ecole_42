/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:09:05 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/07 16:07:43 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
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

//TODO colored output

int	main(void)
{
	printf("isalpha: %s\n", ft_chk_rslt(1, ft_test(1, "azAZ0[", ft_isalpha, isalpha)));
	printf("isdigit: %s\n", ft_chk_rslt(1, ft_test(1, "09AZa[", ft_isdigit, isdigit)));
	printf("isalnum: %s\n", ft_chk_rslt(1, ft_test(1, "09AZa[", ft_isalnum, isalnum)));
	//printf("isalnum: %s\n", ft_chk_rslt(1, ft_test(1, "09AZa[", ft_atoi, atoi)));
	return (0);
}
