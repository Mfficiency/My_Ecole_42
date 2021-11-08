/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:14:09 by mm          #+#    #+#             */
/*   Updated: 2021/11/08 12:25:49 by mm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/* 
TODO: - use putchar  ,fix makefile
TODO: - count input
TODO: - return count
TODO: - make extensive test
TODO: - makefile should still be working
*/

int	ft_handle_str(const char *format, va_list args)
{
	
	return (0);
}

/* Core function
	str = ft_strdup(format);				// create copy of string
	char_count = 0; 						// setting the count to 0
	va_start(args, format);					// setting pointer to 
												position on the call stack
	char_count += ft_handle_str(str, args);	// handeling of the string 
												with the arguments
	va_end(args);							// ending the va
	free((char *)str);						// freeing the copy of the string
	return (char_count);					// returning the amount of characters
*/
int	ft_printf(const char *format, ...)
{
	const char	*str;
	va_list		args;
	int			char_count;

	str = ft_strdup(format);
	char_count = 0;
	va_start(args, format);
	char_count += ft_handle_str(str, args);
	va_end(args);
	free((char *)str);
	return (char_count);
}

/*
int	main(void)
{
	const char	*c;

	c = "x";
	ft_printf("test");
	return (0);
}
//*/