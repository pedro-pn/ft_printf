/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:28:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/13 22:41:54 by ppaulo-d         ###   ########.fr       */
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
# include "./Libft/libft.h"

int	ft_printf(const char *format);
int count_input(char *f_string);
void	fill_inputs(char ***inputs, char *f_string);
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

#endif
