/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:37:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/21 03:01:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	c_conv(va_list arg, char ***inputs)
{
	unsigned char	c;
	int				l_out;

	c = (unsigned char) va_arg(arg, int);
	l_out = 1;
	if (ft_strchr((**inputs), '-'))
	{
		ft_putchar_fd(c, 1);
		l_out += width_conv(inputs, l_out);
	}
	else
	{
		l_out += width_conv(inputs, l_out);
		ft_putchar_fd(c, 1);
	}
	return (l_out);
}

int	s_conv(va_list arg, char ***inputs)
{
	char	*str;
	char	*output;
	int		l_out;
	int		precision;

	output = NULL;
	str = va_arg(arg, char *);
	precision = -1;
	if (!str)
	{
		output = ft_strdup("(null)");
		ft_putstr_fd(output, 1);
		l_out = ft_strlen(output);
		free(output);
		return (l_out);
	}
	if (ft_strchr(**inputs, '.'))
		precision = check_precision(inputs);
	if ((int) ft_strlen(str) > precision && precision != -1)
		output = ft_substr(str, 0, precision);
	else
		output = ft_strdup(str);
	l_out = conv_output(inputs, output, 's');
	free(output);
	return (l_out);
}

int	p_conv(va_list arg, char ***inputs)
{
	unsigned long int	n;
	char				*output;
	int					l_out;

	n = (unsigned long int) va_arg(arg, void *);
	if (!n)
	{
		output = ft_strdup("(nil)");
		ft_putstr_fd(output, 1);
		l_out = ft_strlen(output);
		free(output);
		return (l_out);
	}
	output = ft_calloc(3, sizeof(char));
	output[0] = '0';
	output[1] = 'x';
	ft_putnbr_base_l(n, HEXADECIMAL_L, &output);
	l_out = conv_output(inputs, output, 'p');
	free(output);
	return (l_out);
}

int	id_conv(va_list arg, char ***inputs)
{
	char	*output;
	int		l_out;
	int 	flag;
	int		width;
	char	*zero;
	
	flag = -1;
	output = ft_itoa(va_arg(arg, int));
	l_out = ft_strlen(output);
	width = width_get(inputs, &flag);
	if (flag == 0 && output[0] == '-' && width > l_out)
	{
		output[0] = '0';
		zero = ft_calloc(width - l_out + 1, sizeof(char));
		ft_memset(zero, '0', width - l_out);
		zero[0] = '-';
		output = ft_strjoin(zero, output);
	}
	else // checar sem o else
		output = number_precision(inputs, output);
	l_out = conv_output(inputs, output, 'd');
	free(output);
	return (l_out);
}

int	u_conv(va_list arg, char ***inputs)
{
	char	*output;
	int		l_out;

	output = ft_utoa(va_arg(arg, unsigned int));
	output = number_precision(inputs, output);
	l_out = conv_output(inputs, output, 'u');
	free(output);
	return (l_out);
}
