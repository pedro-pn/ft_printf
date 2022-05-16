/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:03:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/13 22:44:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putnbr_base(long long int nbr, char *base, char **output) //%X or %x
{
	int							mod;
	long long int				quotient;
	int							base_num;

	base_num = check_base(base);
	if (base_num > 1)
	{
		if (nbr < 0)
		{
			*output = ft_strdup("-");
			nbr *= -1;
		}
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

char	*x_conv(va_list arg)
{
	char	*output;

	output = NULL;	
	ft_putnbr_base(va_arg(arg, int), HEXADECIMAL_x, &output);
	return (output);
}

char	*X_conv(va_list arg)
{
	char	*output;
	
	output = NULL;
	ft_putnbr_base(va_arg(arg, int), HEXADECIMAL_X, &output);
	return (output);
}