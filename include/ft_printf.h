/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:28:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/19 18:20:38 by ppaulo-d         ###   ########.fr       */
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
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int 	count_input(const char *f_string);
void	fill_inputs(char ***inputs, const char *format);
char	*hex_concat(char *src, char c);
void	ft_putnbr_base(unsigned int nbr, char *base, char **output);
void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output);
int		check_base(char *base);
void	p_conv(va_list arg, int *l_out);
void	c_conv(va_list arg, int *l_out);
void	s_conv(va_list arg, int *l_out);
char	*ft_utoa(unsigned int n);
void	id_conv(va_list arg, int *l_out);
void	u_conv(va_list arg, int *l_out);
void	x_conv(va_list arg, int *l_out);
void	X_conv(va_list arg, int *l_out);
void	perc_conv(int *l_out);
void	m_output(const char *format, char ***inputs, va_list args, int *l_out);
void	conv_args(va_list args, char ***inputs, int *i_format, int *l_out);
void	output(const char *format, int start, int end, int *l_out);

#endif
