/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:42:06 by yabenman          #+#    #+#             */
/*   Updated: 2024/09/26 10:11:28 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr_base(long long data, char *base, char format_specifier)
{
	int	printed;
	int	base_len;

	printed = 0;
	if (format_specifier == 'd' || format_specifier == 'i')
	{
		base_len = 10;
	}
	else
	{
		base_len = 16;
	}
	if (data < 0)
	{
		printed += ft_putchar('-');
		data = -data;
	}
	if (data >= base_len)
		printed += ft_putnbr_base(data / base_len, base, format_specifier);
	return (printed + ft_putchar(base[data % base_len]));
}

int	ft_put_unsigned(unsigned int data)
{
	int	printed;

	printed = 0;
	if (data >= 10)
		printed += ft_put_unsigned(data / 10);
	return (printed + ft_putchar((data % 10) + '0'));
}

int	ft_put_ptr(unsigned long long data)
{
	int	printed;

	printed = 0;
	if (data >= 16)
		printed += ft_put_ptr(data / 16);
	return (printed + ft_putchar(HEX_LOW[data % 16]));
}
