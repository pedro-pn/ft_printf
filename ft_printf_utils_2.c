/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:20:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/17 16:41:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	perc_conv(int *l_out) // %%
{
	ft_putchar_fd('%', 1);
	(*l_out)++;
}

void	output(const char *format, int start, int end, int *l_out)
{
	char	*s;
	
	s = ft_calloc(1, sizeof(char));
	s = ft_strjoin(s, ft_substr(format, start, end - start));
	(*l_out) += ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
}

void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output) //%X or %x
{
	int							mod;
	unsigned long int			quotient;
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
			ft_putnbr_base_l(quotient, base, output);
		if (*output == NULL)
		{
			(*output) = ft_calloc(2, sizeof(char));
			(*output)[0] = base[mod];
		}
		else
			(*output) = hex_concat(*output, base[mod]);
	}
}