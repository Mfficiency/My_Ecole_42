/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_v1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:51:15 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/29 14:49:45 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_iter(char *str1, char *str2)
{
	int	i;
	int	used[255];
	
	i = 0;
	while (i < 255) // make sure all values in array are set to 0
	{
		used[i++] = 0;
	}
	while (*str2) // add all characters from the second string to the array
	{
		if (!used[(unsigned char)*str2])
		{
			used[(unsigned char)*str2] = 1;
		}
		str2++;
	}
	while (*str1) // loop now over the characters of the first string and display if found
	{
		if (used[(unsigned char)*str1] == 1)
		{
			write(1, str1, 1);
			used[(unsigned char)*str1] = 2;
		}
		str1++;
	}	
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_iter(argv[1], argv[2]);
	}
	else
	{
		ft_iter("hello", "eh");
	}
	write(1, "\n", 1);
	return (0);
}
