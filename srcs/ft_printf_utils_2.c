/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:20:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/19 21:51:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	perc_conv(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	output(const char *format, int start, int end)
{
	char	*s;
	int		l_out;

	s = ft_substr(format, start, end - start);
	l_out = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (l_out);
}

void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output)
{
	int							mod;
	unsigned long int			quotient;
	int							base_num;

	base_num = check_base(base);
	if (base_num > 1)
	{
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
