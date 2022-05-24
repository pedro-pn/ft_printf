/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:28:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/24 21:32:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define CONV_TYPE "cspdiuxX%"
# define HEXADECIMAL_U "0123456789ABCDEF"
# define HEXADECIMAL_L "0123456789abcdef"
# define DECIMAL_0 "0123456789"
# define DECIMAL "1234546789"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

int		ft_printf(const char *format, ...);
// get conversion specification functions
int		count_input(const char *f_string);
void	fill_inputs(char ***inputs, const char *format);
// format and output string functions
void	m_output(const char *format, char ***inputs, va_list args, int *l_out);
int		output(const char *format, int start, int end);
int		conv_args(va_list args, char ***inputs, int *i_format);
// conv_type functions
int		p_conv(va_list arg, char ***inputs);
int		c_conv(va_list arg, char ***inputs);
int		s_conv(va_list arg, char ***inputs);
int		id_conv(va_list arg, char ***inputs);
int		u_conv(va_list arg, char ***inputs);
int		x_conv(va_list arg, char ***inputs);
int		xu_conv(va_list arg, char ***inputs);
int		perc_conv(void);
// hexadecimal convert functions
char	*hex_concat(char *src, char c);
void	ft_putnbr_base(unsigned int nbr, char *base, char **output);
void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output);
int		check_base(char *base);
// unsigned int conversion to string
char	*ft_utoa(unsigned int n);
// [width field] and [flags: '-0']
int		width_conv(char ***inputs, int l_out);
int		width_get(char ***inputs);
int		pad_output(char ***inputs, char *output);
int		check_zero(char ***inputs);
void	fill_zero(char **output, int width, char sign);
void	fill_zero_x(char **output, int width, char x);
// [.precision]
int		check_precision(char ***inputs);
char	*number_precision(char ***inputs, char *output);
// [flags: '# +']
void	fill_sharp(char **output, char x);
void	fill_space(char **output);
void	fill_plus(char **output);

#endif
