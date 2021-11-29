/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:16:23 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/29 16:29:54 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s d x

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_handle_s(char *str) // write char and return amount of chars
{
	int i;
	
	i = 0;
	if (!str)
		str = ("(null)");
	while (*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

int ft_handle_d(int num)
{
	char *str;
	int i;
	
	i = 0;
	str = ft_itoa(num, 10);
	i = ft_handle_s(str);
	free(str);
	return (i);
}

int ft_handle_x(unsigned int num)
{
	char *str;
	int i;
	
	i = 0;
	str = ft_itoa_base(num, 16);
	str = ft_str_tolower(str);
	i = ft_handle_s(str);
	free(str);
	return (i);
}

int ft_putchar_count(char c) // write char and return 1
{
	write(1, &c, 1); 
	return (1);
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *ft_strdup(const char *s)
{
	char *ret;
	int i;
	int len;

	i = 0;											// set zero
	len = ft_strlen(s);								// get the length of the string
	ret = (char *)malloc((len + 1) * sizeof(char));	// allocate space to the returning string
	if (ret == NULL)								// if allocating didnt work, return zero
		return (NULL);
	while (s[i])									// go over the original string
	{
		ret[i] = s[i];								// copy the characters
		i++;										// go to the next position
	}
	ret[i] = '\0';									// add the ending character
	return (ret);									// return the duplicate string
}

int ft_is_conv(char c)
{
	return (c == 's' || c == 'd' || c == 'x');
}

int ft_handle_conv(int type, va_list args)
{
	int i;

	i = 0;
	if(type == 's')									// is string
		i = ft_handle_s(va_arg(args, char *));
	else if(type == 'd')							// is digit
		i = ft_handle_d(va_arg(args, int));
	else if(type == 'x')							// is hexadecimal
		i = ft_handle_x(va_arg(args, unsigned int));
	return (i);
}

int ft_handle_input(const char *format, va_list args)
{
	int type;
	int i;
	int char_count;

	i = 0;													// setting vars to 0
	char_count = 0;
	while (format[i])										// go over string
	{
		if (format[i] != '%')								// if it's just a character, just print it and add to the count
			char_count += ft_putchar_count(format[i]);
		else if (format[i] == '%' && format[i + 1])			// if it is the modifier and there is a char behind it
		{
			i++;											// add one for the %
			type = format[i];								// get the type
			if (ft_is_conv(format[i]))						// is it a modifier
				char_count += ft_handle_conv(type, args);	// handle the conversion
			else
				char_count += ft_putchar_count(format[i]);	// just put the character
		}
		i++;
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
	ft_printf("%d", 5);
	ft_printf("%s", "hello");
	ft_printf("%x", 8);
	return (0);
}
//*/