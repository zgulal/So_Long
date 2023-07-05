  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:08:06 by zgulal            #+#    #+#             */
/*   Updated: 2023/01/13 13:08:08 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	to_print(char c, va_list arg);
int	print_base(long int n, int len, char *base);
int	print_str(char *n);
int	print_chr(int n);
int	p_flag(unsigned long n);

#endif
