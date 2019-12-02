/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2019/12/02 17:36:36 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

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
	char	*output;
	char	sign;
	char	*before;
	char	*after;
}				t_spec;
 

typedef struct		s_stack
{
	struct s_link	*link;
	struct s_stack	*next;
}					t_stack;

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
char	*ft_putnbr_str(intmax_t n, t_spec *s_args);
char	*ft_get_arg_d(t_spec *s_args, va_list args);
int		ft_printf_len(char *format, t_spec **s_args);
void	ft_putsign(t_spec *s_args);
char	*ft_putoutput(t_spec *s_args, char *s);
char	*ft_putunbr_str(uintmax_t n, t_spec *s_args);

#endif
