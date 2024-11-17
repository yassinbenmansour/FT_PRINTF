/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:42:17 by yabenman          #+#    #+#             */
/*   Updated: 2024/09/26 10:09:26 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_printed(const char fs, va_list arg)
{
	int	printed;

	printed = 0;
	if (fs == 'c')
		printed += ft_putchar(va_arg(arg, int));
	else if (fs == 's')
		printed += ft_putstr(va_arg(arg, char *));
	else if (fs == 'p')
	{
		printed += ft_putstr("0x");
		printed += ft_put_ptr(va_arg(arg, unsigned long long));
	}
	else if (fs == 'd' || fs == 'i')
		printed += ft_putnbr_base(va_arg(arg, int), DIGITS, fs);
	else if (fs == 'u')
		printed += ft_put_unsigned(va_arg(arg, unsigned int));
	else if (fs == 'x')
		printed += ft_putnbr_base(va_arg(arg, unsigned int), HEX_LOW, fs);
	else if (fs == 'X')
		printed += ft_putnbr_base(va_arg(arg, unsigned int), HEX_UPP, fs);
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	int		printed;
	int		i;
	va_list	arg;

	printed = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			printed += write(1, &str[i], 1);
		else if (str[i] == '%' && str[i + 1] == '%')
			printed += write(1, &str[i++], 1);
		else if (str[i] == '%' && str[i + 1] != '%')
			printed += get_printed(str[++i], arg);
		i++;
	}
	return (printed);
}
