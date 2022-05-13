/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/12 20:08:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format)
{
	char	*f_string;
//	va_list	args;
	char	**inputs;
	int		n_input;

	f_string = ft_strdup(format); //copiar original que é constante
//	va_start(args, format);
	n_input = count_input(f_string); // contar numero de %
//	printf("%d\n", n_input);
	inputs = malloc(sizeof(char *) * n_input); // alocar ponteiros para cada %
///	printf("oi");
	fill_inputs(&inputs, f_string);
	printf("%s", inputs[1]);
	return (0);
}

int count_input(char *f_string)
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

void	fill_inputs(char ***inputs, char *f_string)
{
	int	index;
	int	start;
	int end;
	int	i_index;

	index = -1;
	start = -1;
	end = -1;
	i_index = 0;
	while (index++, f_string[index])
	{
		if (f_string[index] == '%' && start == -1)
			start = index;
		else if (start != -1 && ft_strchr(CONV_TYPE, f_string[index]))
			end = index;
		if (end != -1 && start != -1)
		{
			(*inputs)[i_index] = ft_substr(f_string, start, end - start + 1);
			end = -1;
			start = -1;
			i_index++;
		}
	}
}
