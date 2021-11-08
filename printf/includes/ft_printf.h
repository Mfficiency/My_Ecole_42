/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:14:13 by mm          #+#    #+#             */
/*   Updated: 2021/11/08 12:01:17 by mm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <stdarg.h>
// # include "./libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putstr(const char *str);

#endif