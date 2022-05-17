/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:28:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/17 16:59:40 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_TYPE "cspdiuxX%"
# define HEXADECIMAL_X "0123456789ABCDEF"
# define HEXADECIMAL_x "0123456789abcdef"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int count_input(const char *f_string);
void	fill_inputs(char ***inputs, const char *format);
char	*hex_concat(char *src, char c);
void	ft_putnbr_base(long long int nbr, char *base, char **output);
int	check_base(char *base);
char	*p_conv(va_list arg);
char	*c_conv(va_list arg);
char	*s_conv(va_list arg);
char	*ft_utoa(unsigned int n);
char	*id_conv(va_list arg);
char	*u_conv(va_list arg);
char	*x_conv(va_list arg);
char	*X_conv(va_list arg);
char	*perc_conv(void);
void	fill_output(const char *format, char **inputs, va_list args, char **s);
char	*conv_args(va_list args, char **inputs, int *i_format);

#endif
