/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:09:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/27 19:28:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	fill_zero(char **output, int width, char sign)
{
	char	*zero;
	int		l_out;

	l_out = ft_strlen(*output);
	(*output)[0] = '0';
	zero = ft_calloc(width - l_out + 1, sizeof(char));
	ft_memset(zero, '0', width - l_out);
	zero[0] = sign;
	*output = ft_strjoin(zero, *output);
}

void	fill_sharp(char **output, char x)
{
	char	*zerox;

	zerox = ft_calloc(3, sizeof(char));
	zerox[0] = '0';
	zerox[1] = x;
	*output = ft_strjoin(zerox, *output);
}

void	fill_space(char **output)
{
	char	*space;

	if (!ft_strchr(*output, '+'))
	{
		space = ft_calloc(2, sizeof(char));
		space[0] = ' ';
		*output = ft_strjoin(space, *output);
	}
}

void	fill_plus(char **output)
{
	char	*plus;

	plus = ft_calloc(2, sizeof(char));
	plus[0] = '+';
	*output = ft_strjoin(plus, *output);
}

void	fill_zero_x(char **output, int width)
{
	char	*s_zero;
	int		l_out;

	l_out = ft_strlen(*output) + 2;
	s_zero = ft_calloc(width - l_out + 1, sizeof(char));
	ft_memset(s_zero, '0', width - l_out);
	*output = ft_strjoin(s_zero, *output);
}
