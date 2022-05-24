/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:03:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/24 21:36:12 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	check_base(char *base)
{
	int	counter;
	int	counter_2;

	counter = 0;
	while (base[counter])
	{
		counter_2 = 0;
		if (base[counter] == '+' || base[counter] == '-')
			return (0);
		while (base[counter_2])
		{
			if (base[counter] == base[counter_2] && counter != counter_2)
				return (0);
			counter_2++;
		}
		counter++;
	}
	return (counter);
}

void	ft_putnbr_base(unsigned int nbr, char *base, char **output)
{
	int							mod;
	unsigned int				quotient;
	int							base_num;

	base_num = check_base(base);
	if (base_num > 1)
	{
		quotient = nbr / base_num;
		mod = nbr % base_num;
		if (quotient != 0)
			ft_putnbr_base(quotient, base, output);
		if (*output == NULL)
		{
			(*output) = ft_calloc(2, sizeof(char));
			(*output)[0] = base[mod];
		}
		else
			(*output) = hex_concat(*output, base[mod]);
	}
}

char	*hex_concat(char *src, char c)
{
	size_t	len;
	char	*out;

	len = ft_strlen(src);
	out = ft_calloc(len + 2, sizeof(char));
	ft_memcpy(out, src, len);
	free(src);
	out[len] = c;
	return (out);
}

int	x_conv(va_list arg, char ***inputs)
{
	char	*output;
	int		l_out;
	int		nbr;
	int		flag;
	int		width;

	output = NULL;
	flag = -1;
	nbr = va_arg(arg, int);
	ft_putnbr_base(nbr, HEXADECIMAL_L, &output);
	output = number_precision(inputs, output);
	if (ft_strchr(**inputs, '#') && nbr != 0)
		fill_sharp(&output, 'x');
	l_out = ft_strlen(output);
	flag = check_zero(inputs);
	width = width_get(inputs);
	if (flag == 0 && ft_strchr(**inputs, '#') && width > l_out)
		fill_zero_x(&output, width, 'x');
	l_out = pad_output(inputs, output);
	free(output);
	return (l_out);
}

int	xu_conv(va_list arg, char ***inputs)
{
	char	*output;
	int		l_out;
	int		nbr;
	int		flag;
	int		width;

	output = NULL;
	nbr = va_arg(arg, int);
	ft_putnbr_base(nbr, HEXADECIMAL_U, &output);
	output = number_precision(inputs, output);
	if (ft_strchr(**inputs, '#') && nbr != 0)
		fill_sharp(&output, 'X');
	l_out = ft_strlen(output);
	flag = check_zero(inputs);
	width = width_get(inputs);
	if (flag == 0 && ft_strchr(**inputs, '#') && width > l_out)
		fill_zero_x(&output, width, 'X');
	l_out = pad_output(inputs, output);
	free(output);
	return (l_out);
}
