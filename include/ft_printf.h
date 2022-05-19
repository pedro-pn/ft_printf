/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:28:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/19 21:44:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_TYPE "cspdiuxX%"
# define HEXADECIMAL_U "0123456789ABCDEF"
# define HEXADECIMAL_L "0123456789abcdef"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int 	count_input(const char *f_string);
void	fill_inputs(char ***inputs, const char *format);
void	m_output(const char *format, char ***inputs, va_list args, int *l_out);
int		output(const char *format, int start, int end);
int		conv_args(va_list args, char ***inputs, int *i_format);
int		p_conv(va_list arg);
int		c_conv(va_list arg);
int		s_conv(va_list arg);
int		id_conv(va_list arg);
int		u_conv(va_list arg);
int		x_conv(va_list arg);
int		xu_conv(va_list arg);
int		perc_conv(void);
char	*hex_concat(char *src, char c);
void	ft_putnbr_base(unsigned int nbr, char *base, char **output);
void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output);
int		check_base(char *base);
char	*ft_utoa(unsigned int n);

#endif