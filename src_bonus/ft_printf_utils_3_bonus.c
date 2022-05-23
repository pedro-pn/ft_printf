/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:35:04 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/23 20:30:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	width_conv(char ***inputs, int l_out)
{
	int	i;
	int	counter;
	int	flag;

	i = 0;
	flag = -1;
	counter = 0;
	i = width_get(inputs, &flag);
	while (counter < i - l_out && i > l_out)
	{
		if (flag == 0)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		counter++;
	}
	return (counter);
}

int	width_get(char ***inputs, int *flag)
{
	int		width;
	int		index;
	int		start;
	char	*nbr;

	index = 0;
	start = -1;
	width = 0;
	while ((**inputs)[index])
	{
		if (ft_strchr(DECIMAL, (**inputs)[index]) && start == -1)
			start = index;
		if ((!ft_strchr(DECIMAL, (**inputs)[index + 1])) && start != -1)
		{
			nbr = ft_substr(**inputs, start, index - start + 1);
			*flag = check_zero(inputs, nbr);
			width = ft_atoi(nbr);
			free(nbr);
			break ;
		}
		if ((**inputs)[index] == '.')
			break ;
		index++;
	}
	return (width);
}

int	check_zero(char ***inputs, char *nbr)
{
	if (nbr[0] == '0' && (!ft_strchr(**inputs, '-')
			|| !ft_strchr(**inputs, '.')))
		return (0);
	return (-1);
}

int	check_precision(char ***inputs)
{
	int		index;
	int		start;
	int		width;
	char	*nbr;

	index = 0;
	start = -1;
	width = 0;
	while ((**inputs)[index] != '.')
		index++;
	index++;
	while ((**inputs)[index])
	{
		if (ft_strchr(DECIMAL, (**inputs)[index]) && start == -1)
			start = index;
		if ((!ft_strchr(DECIMAL, (**inputs)[index + 1])) && start != -1)
		{
			nbr = ft_substr(**inputs, start, index - start + 1);
			width = ft_atoi(nbr);
			free(nbr);
			break ;
		}
		index++;
	}
	return (width);
}

char	*number_precision(char ***inputs, char *output)
{
	int		precision;
	char	*zero;
	int		l_out;

	precision = 0;
	if (ft_strchr(**inputs, '.'))
		precision = check_precision(inputs);
	l_out = ft_strlen(output);
	if (output[0] == '-')
		l_out--;
	if ((int) l_out < precision)
	{
		zero = ft_calloc(precision - l_out + 1, sizeof(char));
		ft_memset(zero, '0', precision - l_out);
		if (output[0] == '-')
		{
			output[0] = '0';
			zero[0] = '-';
		}
		output = ft_strjoin(zero, output);
	}
	return (output);
}
