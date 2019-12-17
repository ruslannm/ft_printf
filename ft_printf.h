/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2019/12/17 16:25:40 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define THOUSAND_SEP ","
# define THOUSAND_SEP_LEN 1
typedef struct s_spec
{
	int		position;
	char	flags[6];  //012345  #0- +'
	int		width;
	int		width_ini; //0 - new struct, 1 - exists in format string, -1 * look in args
	int		precision;
	int		precision_ini; //0 - new struct, 1 - exists in format string, -1 * look in args
	char	*modifier;
	char	conversion;
	int		start;
	int		len;
	char	*type;
	char	*output_raw;
	char	*output;
	int		output_len[6];
	char	sign;
	char	*before;
	char	*after;
	char	*thousand_sep;
	
}				t_spec;
 

typedef struct		s_stack
{
	struct s_link	*link;
	struct s_stack	*next;
}					t_stack;

union u_double 
{	
	float f; 
	struct 
	{ 
		unsigned int m : 23; 
		unsigned int e : 8;
		unsigned int s : 1; 
	} 		f_parts; 
};

int		ft_printf(const char * restrict format, ...);
void	ft_parse(int *i, const char *str, va_list args, int *p);
void	ft_flag_int(va_list args, int *p);
void	ft_flag_char(va_list args, int *p);
void	ft_flag_str(va_list args, int *p);

t_spec	**ft_read_format(char *s);
int		ft_read_args(t_spec **s_args, va_list args);
int		ft_parse_position(char *s, t_spec *s_args, int *i);
int		ft_parse_flags(char *s, t_spec *s_args, int *i);
int		ft_parse_width(char *s, t_spec *s_args, int *i);
int		ft_parse_precision(char *s, t_spec *s_args, int *i);
int		ft_parse_modifier(char *s, t_spec *s_args, int *i);
int		ft_parse_conversion(char *s, t_spec *s_args, int *i);
int		ft_check_format(t_spec *s_args);
int		ft_check_position(t_spec **s_args);
int		ft_put_di_str(intmax_t n, t_spec *s_args);
int		ft_get_arg_d(t_spec *s_args, va_list args);
int		ft_get_arg_u(t_spec *s_args, va_list args);
int		ft_get_arg_oxX(t_spec *s_args, va_list args);
int		ft_get_arg_c(t_spec *s_args, va_list args);
int		ft_get_arg_s(t_spec *s_args, va_list args);
int		ft_get_arg_p(t_spec *s_args, va_list args);
int		ft_printf_len(char *format, t_spec **s_args);
void	ft_putsign(t_spec *s_args);
int		ft_putoutput(t_spec *s_args);
int		ft_putoutput_xX(t_spec *s_args);
int		ft_put_u_str(uintmax_t n, t_spec *s_args);
int		ft_put_oxX_str(uintmax_t n, t_spec *s_args);
int		ft_put_c_str(unsigned char n, t_spec *s_args);
int		ft_put_s_str(char *s, t_spec *s_args);
int		ft_put_p_str(char *s, t_spec *s_args);
void	ft_get_len_output(t_spec *s_args);
int		ft_nbr_len(intmax_t n, int base);
int		ft_put_f_str(float n, t_spec *s_args);
int		ft_get_arg_f(t_spec *s_args, va_list args);

#endif
