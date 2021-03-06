/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:37:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/24 16:23:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	c_conv(va_list arg)
{
	unsigned char	c;

	c = (unsigned char) va_arg(arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	s_conv(va_list arg)
{
	char	*str;
	int		l_out;

	str = va_arg(arg, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	l_out = ft_strlen(str);
	return (l_out);
}

int	p_conv(va_list arg)
{
	unsigned long int	n;
	char				*output;
	int					l_out;

	n = (unsigned long int) va_arg(arg, void *);
	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	output = ft_calloc(3, sizeof(char));
	output[0] = '0';
	output[1] = 'x';
	ft_putnbr_base_l(n, HEXADECIMAL_L, &output);
	ft_putstr_fd(output, 1);
	l_out = ft_strlen(output);
	free(output);
	return (l_out);
}

int	id_conv(va_list arg)
{
	char	*output;
	int		l_out;

	output = ft_itoa(va_arg(arg, int));
	ft_putstr_fd(output, 1);
	l_out = ft_strlen(output);
	free(output);
	return (l_out);
}

int	u_conv(va_list arg)
{
	char	*output;
	int		l_out;

	output = ft_utoa(va_arg(arg, unsigned int));
	ft_putstr_fd(output, 1);
	l_out = ft_strlen(output);
	free(output);
	return (l_out);
}
