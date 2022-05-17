/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/17 19:23:27 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	**inputs;
	int		n_input;
	char	*output;
	int		len_out;
	int		index;

	va_start(args, format);
	index = 0;
	n_input = count_input(format); // contar numero de %
	inputs = malloc(sizeof(char *) * n_input); // alocar ponteiros para cada %
	fill_inputs(&inputs, format);
	output = ft_calloc(1, sizeof(char));
	fill_output(format, inputs, args, &output);
	len_out = ft_strlen(output);
	ft_putstr_fd(output, 1);
	free(output);
	n_input--;
	while (n_input >= 0)
	{
		free(inputs[n_input]);
		n_input--;
	}
	free(inputs);
	return (len_out);
}

int count_input(const char *f_string)
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	while (f_string[index])
	{
		if (f_string[index] == '%')
			counter++;
		index++;
	}
	return (counter);
}

void	fill_inputs(char ***inputs, const char *format)
{
	int	index;
	int	start;
	int end;
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

void	fill_output(const char *format, char **inputs, va_list args, char **s)
{
	int		i_format;
	int		start;
	int		end;

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
				*s = ft_strjoin(*s, ft_substr(format, start, end - start));
				start = -1;
			}
			if (format[i_format] == '%')
				*s = ft_strjoin(*s, conv_args(args, inputs, &i_format));
		}
		i_format++;
	}
}

char	*conv_args(va_list args, char **inputs, int *i_format)
{
	static int	index = 0;

	index++;
	*i_format += ft_strlen(inputs[index - 1] + 1);
	if (ft_strrchr(inputs[index - 1], 'c'))
		return (c_conv(args));
	else if (ft_strrchr(inputs[index - 1], 's'))
		return (s_conv(args));
	else if (ft_strrchr(inputs[index - 1], 'p'))
		return (p_conv(args));
	else if (ft_strrchr(inputs[index - 1], 'i') 
			|| ft_strrchr(inputs[index - 1], 'd'))
		return (id_conv(args));
	else if (ft_strrchr(inputs[index - 1], 'u'))
		return (u_conv(args));
	else if (ft_strrchr(inputs[index - 1], 'x'))
		return (x_conv(args));
	else if (ft_strrchr(inputs[index - 1], 'X'))
		return (X_conv(args));
	else if (ft_strrchr(inputs[index - 1], '%'))
		return (perc_conv());
	return (NULL);
}
