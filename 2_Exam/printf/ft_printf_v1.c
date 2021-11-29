/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:16:23 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/29 15:44:41 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_handle_input(const char *format, va_list args)
{
	int type;
	int i;
	int char_count;

	i = 0;												// setting vars to 0
	char_count = 0;
	while (format[i])									// go over string
	{
		if (format[i] != '%')							// if it's just a character, just print it and add to the count
			char_count += ft_putchar_count(format[i]);
		else if (format[i] == '%' && format)
	}
	
}

int ft_printf(const char *format, ... )
{
	const char *str;
	va_list	args;
	int char_count;

	str = ft_strdup(format); 					// create a copy of the string
	char_count = 0;								// setting the count to 0
	va_start(args, format);						// setting the pointer to the position on the call stack
	char_count += ft_handle_input(str, args);	// handeling of the string with the arguments
	va_end(args);								// ending the va
	free((char *)str);							// freeing the copy of the string
	return (char_count);						// returning he amount of characters
}

//*
int main ()
{
	ft_printf("test");
	return (0);
}
//*/