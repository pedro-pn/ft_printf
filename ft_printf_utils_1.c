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

void	c_conv(va_list arg, int *l_out) // %c
{
	unsigned char	c;

	c = (unsigned char) va_arg(arg, int);
	(*l_out)++;
	ft_putchar_fd(c, 1);
}

void	s_conv(va_list arg, int *l_out) // %s
{
	char	*str;
	char	*output;

	output = NULL;
	str = va_arg(arg, char *);
	if (!str)
	{
		output = ft_strdup("(null)");
		ft_putstr_fd(output, 1);
		(*l_out) += ft_strlen(output);
		free(output);
		return ;
	}
	output = ft_strdup(str);
	ft_putstr_fd(output, 1);
	(*l_out) += ft_strlen(output);
	free(output);
}

void	p_conv(va_list arg, int *l_out) // %p
{
	unsigned long int	n;
	char				*output;

	n = (unsigned long int) va_arg(arg, void *);
	if (!n)
	{
		output = ft_strdup("(nil)");
		ft_putstr_fd(output, 1);
		(*l_out) += ft_strlen(output);
		free(output);
		return ;
	}
	output = ft_calloc(3, sizeof(char));
	output[0] = '0';
	output[1] = 'x';
	ft_putnbr_base_l(n, HEXADECIMAL_x, &output);
	ft_putstr_fd(output, 1);
	(*l_out) += ft_strlen(output);
	free(output);
}

void	id_conv(va_list arg, int *l_out) //%d or %i
{
	char	*output;

	output = ft_itoa(va_arg(arg, int));
	ft_putstr_fd(output, 1);
	(*l_out) += ft_strlen(output);
	free(output);
}

void	u_conv(va_list arg, int *l_out) // %u
{
	char	*output;

	output = ft_utoa(va_arg(arg, unsigned int));
	ft_putstr_fd(output, 1);
	(*l_out) += ft_strlen(output);
	free(output);
}
