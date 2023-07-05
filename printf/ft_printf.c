/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:08:11 by zgulal            #+#    #+#             */
/*   Updated: 2023/01/13 13:08:25 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_print(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += print_chr(va_arg(arg, int));
	else if (c == 's')
		i += print_str(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		i += print_base(va_arg(arg, int), 10, "0123456789");
	else if (c == 'u')
		i += print_base(va_arg(arg, unsigned int), 10, "0123456789");
	else if (c == 'x')
		i += print_base(va_arg(arg, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		i += print_base(va_arg(arg, unsigned int), 16, "0123456789ABCDEF");
	else if (c == 'p')
	{
		i += print_str("0x");
		i += p_flag(va_arg(arg, unsigned long));
	}
	else if (c == '%')
		i += print_chr('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			print_chr(s[i]);
			len++;
		}
		if (s[i] == '%')
		{
			i++;
			len += to_print(s[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
