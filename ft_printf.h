/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:42:21 by yabenman          #+#    #+#             */
/*   Updated: 2024/09/26 10:12:32 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# define UNS_LL unsigned long long
# define BASE &"0123456789abcdef"
# define DIGITS "0123456789"

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);
int		get_printed(const char fs, va_list arg);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_put_ptr(UNS_LL data);
int		ft_putnbr_base(long long data, char *bs, char fs);
int		ft_put_unsigned(unsigned int data);

#endif
