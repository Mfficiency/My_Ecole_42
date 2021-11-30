/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:14:13 by mmeersma          #+#    #+#             */
/*   Updated: 2021/11/11 11:31:03 by mmeersma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

//
char	*ft_itoa_base(size_t num, int base);
char	*ft_itoa(int num, int base);
char	*ft_str_tolower(char *str);
char	*ft_strdup(const char *s);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_handle_c(char c);
int		ft_handle_i(int num);
int		ft_handle_p(size_t num);
int		ft_handle_u(unsigned int num);
int		ft_handle_x(unsigned int num);
int		ft_handle_xc(unsigned int num);
int		ft_putchar_count(char c);
int		ft_putstr_count(char *str);
int		ft_strlen(const char *str);

#endif