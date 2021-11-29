/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:51:19 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/29 15:04:18 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_union(char *str1, char *str2)
{
	int used[255];
	int	i;

	i =0;
	while (i < 255) // make sure everything is set to 0
	{
		used[i++] = 0;
	}
	while (*str1) // add all characters to
	{
		if (!used[(unsigned char)*str1])
		{
			used[(unsigned char)*str1] = 1;
			write(1,str1,1);
		}
		str1++;
	}
	while (*str2)
	{
		if (!used[(unsigned char)*str2])
		{
			used[(unsigned char)*str2] = 1;
			write(1,str2,1);
		}
		str2++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	else
	{
		ft_union("hello", "exh");
	}
	write(1,"\n",1);
	return (0);
}
