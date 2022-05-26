/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:37:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/26 15:48:54 by ppaulo-d         ###   ########.fr       */
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
	precision = check_precision(inputs);
	if ((precision == -1 || precision >= 6) && !str)
		output = ft_strdup("(null)");
	else if (!str)
		str = "";
	if (!output)
		output = ft_strdup(str);
	if ((int) ft_strlen(output) > precision && precision != -1)
	{
		free(output);
		output = ft_substr(str, 0, precision);
	}
	l_out = pad_output(inputs, output);
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
		output = ft_strdup("(nil)");
	else
	{
		output = ft_calloc(3, sizeof(char));
		output[0] = '0';
		output[1] = 'x';
		ft_putnbr_base_l(n, HEXADECIMAL_L, &output);
	}
	l_out = pad_output(inputs, output);
	free(output);
	return (l_out);
}

int	id_conv(va_list arg, char ***inputs)
{
	char	*output;
	int		l_out;
	int		flag;
	int		width;
	int		nbr;

	flag = -1;
	nbr = va_arg(arg, int);
	output = ft_itoa(nbr);
	l_out = ft_strlen(output);
	width = width_get(inputs);
	flag = check_zero(inputs);
	if (ft_strchr(**inputs, '+') && nbr >= 0)
		fill_plus(&output);
	if (flag == 0 && output[0] == '-' && width > l_out)
		fill_zero(&output, width, '-');
	if (flag == 0 && output[0] == '+' && width > l_out)
		fill_zero(&output, width, '+');
	output = number_precision(inputs, output);
	if (ft_strchr(**inputs, ' ') && nbr >= 0)
		fill_space(&output);
	l_out = pad_output(inputs, output);
	free(output);
	return (l_out);
}

int	u_conv(va_list arg, char ***inputs)
{
	char	*output;
	int		l_out;

	output = ft_utoa(va_arg(arg, unsigned int));
	output = number_precision(inputs, output);
	l_out = pad_output(inputs, output);
	free(output);
	return (l_out);
}
