/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:37:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/17 19:59:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_conv(va_list arg) // %c
{
	char	c;
	char	*out;

	c = va_arg(arg, int);
	out = ft_calloc(2, sizeof(char));
	out[0] = c;
	out [1] = 0;
	return (out);
}

char	*s_conv(va_list arg) // %s
{
	char	*str;
	
	str = va_arg(arg, char *);
	return (str);
}

char	*p_conv(va_list arg) // %p
{
	unsigned long int	n;
	char				*output;

	output = calloc(3, sizeof(char));
	output[0] = '0';
	output[1] = 'x';
	n = (unsigned long int) va_arg(arg, void *);
	ft_putnbr_base(n, HEXADECIMAL_x, &output);
	return (output);
}

char	*id_conv(va_list arg) //%d or %i
{
	return (ft_itoa(va_arg(arg, int)));
}

char	*u_conv(va_list arg) // %u
{
	return (ft_utoa(va_arg(arg, unsigned int)));
}
