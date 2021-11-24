/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:10:25 by mm          #+#    #+#             */
/*   Updated: 2021/11/05 11:31:18 by mm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	printf("--- hello ---\n");
	int	fda;
	fda = open("txt_files/hello.txt", O_RDONLY);
	test(fda);
	/* printf("--- nbr ---\n");
	int	fdf;
	fdf = open("txt_files/nbr.txt", O_RDONLY);
	test(fdf);
	printf("--- nbr2 ---\n");
	int	fdb;
	fdb = open("txt_files/nbr2.txt", O_RDONLY);
	test(fdb); */
}
