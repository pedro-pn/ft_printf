/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:28:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/21 00:50:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_TYPE "cspdiuxX%"
# define NUMERICAL "diu"
# define HEXADECIMAL_U "0123456789ABCDEF"
# define HEXADECIMAL_L "0123456789abcdef"
# define DECIMAL "0123456789"


# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int 	count_input(const char *f_string);
void	fill_inputs(char ***inputs, const char *format);
void	m_output(const char *format, char ***inputs, va_list args, int *l_out);
int		output(const char *format, int start, int end);
int		conv_args(va_list args, char ***inputs, int *i_format);
int		p_conv(va_list arg, char ***inputs);
int		c_conv(va_list arg, char ***inputs);
int		s_conv(va_list arg, char ***inputs);
int		id_conv(va_list arg, char ***inputs);
int		u_conv(va_list arg, char ***inputs);
int		x_conv(va_list arg, char ***inputs);
int		xu_conv(va_list arg, char ***inputs);
int		perc_conv(void);
char	*hex_concat(char *src, char c);
void	ft_putnbr_base(unsigned int nbr, char *base, char **output);
void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output);
int		check_base(char *base);
char	*ft_utoa(unsigned int n);
int	width_conv(char ***inputs, int l_out);
int	width_get(char ***inputs, int *flag);
int	conv_output(char ***inputs, char *output, char type);
int	check_zero(char ***inputs, char *nbr);
int	check_precision(char ***inputs);
char	*number_precision(char ***inputs, char *output);

#endif
