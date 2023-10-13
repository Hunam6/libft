/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:38:51 by etattevi          #+#    #+#             */
/*   Updated: 2023/10/13 20:52:06 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

int		ft_printf(const char *str, ...);
void	write_arg(int *printed, va_list *args, char specifier);
void	puthex(int *printed, unsigned long n, bool upper, bool is_long);
void	puthexnbr(int *printed, unsigned long n, bool upper);
void	putstr(int *printed, char *str);
void	putchr(int *printed, char chr);
void	putnb(int *printed, long nb);

#endif