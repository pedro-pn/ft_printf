/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:28:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/27 23:18:40 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define CONV_TYPE "cspdiuxX%"
# define HEXADECIMAL_U "0123456789ABCDEF"
# define HEXADECIMAL_L "0123456789abcdef"
# define DECIMAL "1234546789"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

enum e_flags {minus = 1, zero = 2, dot = 4, sharp = 8, space = 16, plus = 32};

typedef struct s_conversions
{
	int		flags;
	int		width;
	int		precision;
}				t_flags;

int		ft_printf(const char *format, ...);
// get conversion specification functions
int		count_input(const char *f_string);
void	fill_inputs(char ***inputs, const char *format);
// format and output string functions
void	m_output(const char *format, char ***inputs, va_list args, int *l_out);
int		output(const char *format, int start, int end);
int		conv_args(va_list args, char ***inputs, int *i_format);
// get all flags
void	get_flags(char ***inputs, t_flags *flags);
// conv_type functions
int		p_conv(va_list arg, t_flags flags);
int		c_conv(va_list arg, t_flags flags);
int		s_conv(va_list arg, t_flags flags);
int		id_conv(va_list arg, t_flags flags);
int		u_conv(va_list arg, t_flags flags);
int		x_conv(va_list arg, t_flags flags);
int		xu_conv(va_list arg, t_flags flags);
int		perc_conv(void);
// hexadecimal convert functions
char	*hex_concat(char *src, char c);
void	ft_putnbr_base(unsigned int nbr, char *base, char **output);
void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output);
int		check_base(char *base);
// unsigned int conversion to string
char	*ft_utoa(unsigned int n);
// [width field] and [flags: '-0']
int		width_conv(t_flags flags, int l_out);
int		width_get(char ***inputs);
int		pad_output(t_flags flags, char *output);
int		check_zero(char ***inputs);
void	fill_zero(char **output, int width, char sign);
void	fill_zero_x(char **output, int width);
// [.precision]
int		check_precision(char ***inputs);
char	*number_precision(t_flags flags, char *output);
// [flags: '# +']
void	fill_sharp(char **output, char x);
void	fill_space(char **output);
void	fill_plus(char **output);

#endif
