/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/02/02 19:15:55 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>
# include <stdint.h>  // for debian

/*
** flags        #0- +
** width_diff   difference for c = 0
*/

typedef struct s_spec
{
	int		fd;
	char	*format;
	int		position;
	char	flags[5]; 
	int		width;
	int		width_ini; 
	int		width_diff;
	int		precision;
	int		precision_ini; 
	char	modifier;
	char	conversion;
	int		start;
	int		len;
//	char	*output_raw;
//	char	*output;
//	char	*output_dec;
	int		output_len[6];
	char	sign;
	char	print_char;
}				t_spec;
 

typedef struct		s_stack
{
	struct s_link	*link;
	struct s_stack	*next;
}					t_stack;

/*
**   23
**    8
**    1
*/

/*
union u_double 
{	
	double f; 
	struct 
	{ 
		unsigned long int m : 52; 
		unsigned int e : 11; 
		unsigned int s : 1; 
	} 		f_parts; 
};

*/
union u_long_double 
{	
	long double f; 
	struct 
	{ 
		unsigned long int m : 64; 
		unsigned int e : 15; 
		unsigned int s : 1; 
	} 		f_parts; 
};

int		ft_printf(const char * restrict format, ...);
/*
void	ft_parse(int *i, const char *str, va_list args, int *p);
*/
int		ft_parse(t_spec *s_args, va_list args);
int		ft_new_spec(t_spec **s_args, char *format, int start, int fd);
void	ft_flag_int(va_list args, int *p);
void	ft_flag_char(va_list args, int *p);
void	ft_flag_str(va_list args, int *p);
int		ft_parse_position(char *s, t_spec *s_args, int *i);
int		ft_parse_flags(char *s, t_spec *s_args, int i);
int		ft_parse_width(char *s, t_spec *s_args, int i);
int		ft_parse_precision(char *s, t_spec *s_args, int i);
int		ft_parse_modifier(char *s, t_spec *s_args, int i);
int		ft_parse_conversion(char *s, t_spec *s_args, int i);
int		ft_parse_percent(char *s, int i);
int		ft_check_format(t_spec *s_args);
int		ft_check_position(t_spec **s_args);
void	ft_get_di_str(intmax_t n, t_spec *s_args, char *str);
void	ft_get_args(t_spec *s_args, va_list args);
void	ft_get_arg_d(t_spec *s_args, va_list args);
void	ft_get_arg_u(t_spec *s_args, va_list args);
void	ft_get_arg_ox(t_spec *s_args, va_list args);
void	ft_get_arg_c(t_spec *s_args, va_list args);
void	ft_get_arg_s(t_spec *s_args, char *str);
void	ft_get_arg_s_va_list(t_spec *s_args, va_list args);
void	ft_get_arg_p(t_spec *s_args, va_list args);
void	ft_get_arg_f(t_spec *s_args, va_list args);
int		ft_printf_len(char *format, t_spec **s_args);
void	ft_set_sign(t_spec *s_args);
void	ft_put_output(t_spec *s_args, char *str, int i);
void	ft_put_output_f(t_spec *s_args, char *str, int i);
void	ft_get_str_di(intmax_t n, t_spec *s_args, char *str);
void	ft_get_str_u(uintmax_t n, t_spec *s_args, char *str);
void	ft_get_str_o(uintmax_t n, t_spec *s_args, char *str);
void	ft_get_str_x(uintmax_t n, t_spec *s_args, char *str);
void	ft_get_str_c(unsigned char n, char *str);
void	ft_get_str_p(char **s, char *str);
void	ft_get_str_f(long double n, t_spec *s_args, char *str);
//void	ft_get_len_output(t_spec *s_args, char *str);
//void	ft_get_len_output_f(t_spec *s_args, char *str);
int		ft_nbr_len(intmax_t n, int base);
void	ft_conv_bin2dec(char *str);
int		ft_get_width_diff(t_spec **s_args);
void		ft_shift(char *s, int i);
void	ft_sum_decimal(char *s1, char *s2, int base, char *s);
void	ft_get_str_binary(unsigned long int n, int power, char *s);
void	ft_sum_float(char *s1, char *s2, int base, char *s);
void	ft_float_len(const char *str, int *len);
int	ft_put_sign(t_spec *s_args, int i);
int	ft_putchar_s_fd(char c, int i, int j, int fd);
int	ft_max_power(const char *str);
void ft_mul_long(const char *a, const char *b, char *c);
void ft_div_by2_frac(char *str);
void	ft_conv_bin_fracpart(t_spec *s_args, const char *str, char *fracpart);
void	ft_conv_bin_intpart(const char *str, char *intpart);
void	ft_conv_bin_dec(t_spec *s_args, char *str);
void	ft_sum_fracpart(const char *s1, const char *s2, int base, char *s);
void	ft_sum_int(const char *s1, const char *s2, int base, char *s);
//void	ft_roundup_diff(char *str, int precision);
//int	ft_isodd(char c);
//int		ft_check_str_zero(char *str);
void	ft_roundup(char *str, t_spec *s_args);
int		ft_check_str_zero(char *str);
void	ft_get_str_f_null(t_spec *s_args, int sign, char *str);
void	ft_get_str_f_naninf(t_spec *s_args, unsigned long int mantissa,
		char *str);

#endif
