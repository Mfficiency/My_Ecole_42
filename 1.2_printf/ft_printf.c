/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:14:09 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/10 17:00:13 by mmeersma         ###   ########.fr       */
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

int	ft_is_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_handle_conv(int type, va_list args)
{
	int	i;

	i = 0;
	if (type == 'c')
		i = ft_handle_c(va_arg(args, int));
	else if (type == 's')
		i = ft_putstr_count(va_arg(args, char *));
	else if (type == 'p')
		i = ft_handle_p(va_arg(args, size_t));
	else if (type == 'd' || type == 'i')
		i = ft_handle_int(va_arg(args, int));
	else if (type == 'u')
		i = ft_handle_u(va_arg(args, unsigned int));
	else if (type == 'x')
		i = ft_handle_x(va_arg(args, unsigned int));
	else if (type == 'X')
		i = ft_handle_xc(va_arg(args, unsigned int));
	else if (type == '%')
		i = ft_putchar_count('%');
	return (i);
}

int	ft_handle_input(const char *format, va_list args)
{
	int	type;
	int	i;
	int	char_count;

	i = 0;
	char_count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			char_count += ft_putchar_count(format[i]);
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			type = format[i];
			if (ft_is_conv(format[i]))
				char_count += ft_handle_conv(type, args);
			else
				char_count += ft_putchar_count(format[i]);
		}
		i++;
	}
	return (char_count);
}

/* Core function
	str = ft_strdup(format);				// create copy of string
	char_count = 0; 						// setting the count to 0
	va_start(args, format);					// setting pointer to 
												position on the call stack
	char_count += ft_handle_input(str, args);	// handeling of the string 
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
	char_count += ft_handle_input(str, args);
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