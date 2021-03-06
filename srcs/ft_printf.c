/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/24 19:16:04 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	**inputs;
	int		n_input;
	int		len_out;

	len_out = 0;
	va_start(args, format);
	n_input = count_input(format);
	inputs = malloc(sizeof(char *) * (n_input + 1));
	inputs[n_input] = NULL;
	fill_inputs(&inputs, format);
	m_output(format, &inputs, args, &len_out);
	inputs = inputs - n_input;
	while (n_input >= 0)
	{
		free(inputs[n_input]);
		n_input--;
	}
	free(inputs);
	va_end(args);
	return (len_out);
}

int	count_input(const char *f_string)
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	while (f_string[index])
	{
		if (f_string[index] == '%')
			counter++;
		if (ft_strnstr(&f_string[index], "%%", 2))
			index++;
		index++;
	}
	return (counter);
}

void	fill_inputs(char ***inputs, const char *format)
{
	int	index;
	int	start;
	int	end;
	int	i_index;

	index = -1;
	start = -1;
	end = -1;
	i_index = 0;
	while (index++, format[index])
	{
		if (format[index] == '%' && start == -1)
			start = index;
		else if (start != -1 && ft_strchr(CONV_TYPE, format[index]))
			end = index;
		if (end != -1 && start != -1)
		{
			(*inputs)[i_index] = ft_substr(format, start, end - start + 1);
			end = -1;
			start = -1;
			i_index++;
		}
	}
}

void	m_output(const char *format, char ***inputs, va_list args, int *l_out)
{
	int	i_format;
	int	start;
	int	end;

	i_format = 0;
	start = -1;
	while (format[i_format])
	{
		if (start == -1 && format[i_format] != '%')
			start = i_format;
		if (format[i_format] == '%' || !format[i_format + 1])
		{
			if (start != -1)
			{
				end = i_format;
				if (!format[i_format + 1])
					end ++;
				(*l_out) += output(format, start, end);
				start = -1;
			}
			if (format[i_format] == '%')
				(*l_out) += conv_args(args, &*inputs, &i_format);
		}
		i_format++;
	}
}

int	conv_args(va_list args, char ***inputs, int *i_format)
{
	int	l_out;

	l_out = 0;
	*i_format += (ft_strlen(**inputs) - 1);
	if (ft_strrchr(**inputs, 'c'))
		l_out = c_conv(args);
	else if (ft_strrchr(**inputs, 's'))
		l_out = s_conv(args);
	else if (ft_strrchr(**inputs, 'p'))
		l_out = p_conv(args);
	else if (ft_strrchr(**inputs, 'i')
		|| ft_strrchr(**inputs, 'd'))
		l_out = id_conv(args);
	else if (ft_strrchr(**inputs, 'u'))
		l_out = u_conv(args);
	else if (ft_strrchr(**inputs, 'x'))
		l_out = x_conv(args);
	else if (ft_strrchr(**inputs, 'X'))
		l_out = xu_conv(args);
	else if (ft_strrchr(**inputs, '%'))
		l_out = perc_conv();
	(*inputs)++;
	return (l_out);
}
