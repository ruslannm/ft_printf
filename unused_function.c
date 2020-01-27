/*
char	*ft_sum(char *s1, char *s2, int base)
{
	int 	carry;
	int		s_len[3];
	int		i;
	char	*s;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = 1 + (s_len[1] > s_len[2] ? s_len[1] : s_len[2]);
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (NULL);
	i = 1;
	while (i <= s_len[1] || i <= s_len[2])	
	{
		s[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) % base + '0';
		carry = (ft_get_digit(s1, s_len[1], i) + ft_get_digit(s2, s_len[2], i) + carry) / base;
		i++;
	}
	if (carry)
		s[s_len[0] - i] = carry + '0';
	else
	{
		ft_memmove(s, s + 1, s_len[0] - 1);
		s[s_len[0] - 1] = '\0';
	}
	return (s);
}
*/

char	*ft_pow(int base, int power)
{
	char	*ret;
	char	*tmp;

	if (power == 0)
	{
		if (!(ret = ft_strnew(2)))
			return (NULL);
		ret[0] = '1';
	}
	else
	{
		if (!(ret = ft_put_i_str(base)))
			return (NULL);
		while (--power)
		{
			tmp = ft_mul(ret, base);
			free(ret);
			ret = tmp;
		}
	}
	return (ret);
}

/*
void	ft_shift_int(char **s, int i)
{
	char *s_tmp;
	char *s_new;
	int *len;
	int len1_new;

	s_tmp = *s;
	len = ft_float_len(s_tmp);
	if (i > 0)
	{
		len[4] = len[0] + (i > len[3] ? i - len[3] : 0); 
		if (!(s_new = ft_strnew(len[4])))
			return (-1);
		if (1 == len[1] && '0' == s_tmp[0])
			len1_new = 0;
		else
			len1_new = len[1];		
		ft_strncpy(s_new, s_tmp, len1_new);
		if (i > len[3])
		{
			ft_strncpy(&s_new[len1_new], &s_tmp[1], len[3]);
			s_new[--len[4]] = '.';
//			while (i-- > len[3])
//				s_new[--len[4]] = '0';
			while (--i)
				s_new[len[4] - i] = '0';
		}
		else
		{
			ft_strncpy(&s_new[len1_new], &s_tmp[len[1] + 1], i);
//			s_new[i + len1_new] = '.';
//			ft_strncpy(&s_new[i + len1_new + 1], &s_tmp[i + len[1] + 1], len[3] - i);
		}
		free(*s);
		*s = s_new;
	}
	else if (i < 0)
	{
		len[4] = len[0] + (-i >= len[1]? - i - len[1] + 1 : 0) + (len[2] ? 0 : 1); 
		if (!(s_new = ft_strnew(len[4])))
			return (-1);
		//ft_strncpy(s_new, s_tmp, len[1]);
		if (-i >= len[1])
		{
			ft_strncpy(s_new, "0.", 2);
			ft_strncpy(&s_new[2 - i - len[1]], s_tmp, len[1]);
			ft_strncpy(&s_new[2 - i], &s_tmp[len[1] + 1], len[3]);
			while (len[1] < - i++)
				s_new[2 - i - len[1]] = '0';
		}
		else
		{
			ft_strncpy(s_new, s_tmp, len[1] + i);
			s_new[i + len[1]] = '.';
			ft_strncpy(&s_new[i + len[1] + 1], &s_tmp[i + len[1]], - i);  //Error
			ft_strncpy(&s_new[len[1] + 1], &s_tmp[len[1] + 1], len[3]);
		}
		free(*s);
		*s = s_new;
	}
	return (0);
}
*/
/*
void ft_div_2_dec(char *s)
{
	char tmp[5000];
	int	shift;

	if (ft_strcmp("1", s))
		shift = ft_max_power(s) - 1;
	else
		shift = 0;	
	//ft_shift_int(&s1, shift);
	ret = ft_div_2(s1);
	///ft_shift(&ret, - shift);
	return (ret);
}
*/

/*
int	ft_nbr_len(intmax_t n, int base)
{
	int i;

	i = 1;
	while (n / base > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
*/

char *ft_div(char *s1, char *s2, int digit)
{
	char *ret;
	int i;
	int d;
	char	*tmp;

	if (!(ret = ft_strnew(digit)))
		return (NULL);
	i = 0;
	d = ft_div_int(s1, s2); //0;
	while (i < digit)
	{
		ret[i] = d + '0';
		tmp = ft_mul(s2, d);
		s1 = ft_sub(s1, tmp);
		if (!ft_strcmp(s1, "0"))
			break;
		s1 = ft_mul(s1, 10);
		d = ft_div_int(s1, s2);
		if (i == 0)
			ret[++i] = '.';
		i++;
	}
	return (ret);
}

int 	ft_div_int(char *s1, char *s2)
{
	int		ret;
	char	*s;
	
	ret = 1;
	while (ret <= 10)
	{
		s = ft_mul(s2, ret);
		if (ft_strcmp_nb(s, s1) > 0)
		{
			ret = ret - 1;
			free(s);
			break;
		}
		else if (ft_strcmp_nb(s, s1) == 0)
		{
			free(s);
			break;
		}
		ret++;
		free(s);
	}
	return (ret);
}

char	*ft_mul_str(char *s1, char *s2)
{
	char	*s;
	char	*tmp;
	char	*tmp2;
	int		s_len[3];
	int		i;

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	i = 0;
	tmp2 = ft_strdup("0");
	while (i < s_len[2])	
	{
		tmp = ft_mul(s1, s2[i] - '0');
		ft_shift_int(&tmp, s_len[2] - i);
		s = ft_sum_int(tmp2, tmp, 10);
		free(tmp);
		free(tmp2);
		tmp2 = s;
		i++;
	}
	return (s);
}

char	*ft_mul(char *s1, int y)
{
	char	*s;
	int		s_len[2];
	int		carry;
	int		i;

	s_len[1] = ft_strlen(s1);
	s_len[0] = 1 + s_len[1];
	s = ft_strnew(s_len[0] + 1);
	if (!y)
		s[0] = '0';
	else if	(y == 10)
	{
		s = ft_strcpy(s, s1);
		s[s_len[0] - 1] = '0';
	}
	else
	{
		carry = 0;
		i = 1;
		while (i < s_len[0])	
		{
			s[s_len[0] - i]  = (ft_get_digit(s1, s_len[1], i) * y + carry) % 10 + '0';
			carry = (ft_get_digit(s1, s_len[1], i) * y + carry) / 10;
			i++;
		}
		if (carry)
			s[s_len[0] - i] = carry + '0';
		else
		{
			ft_memmove(s, s + 1, s_len[0] - 1);
			s[s_len[0] - 1] = '\0';
		}
	}
	return (s);
}

char	*ft_put_i_str(int n)
{
	int 	i;
	char	*ret;

	i = ft_nbr_len(n, 10);
	if (!(ret = ft_strnew(i + 1)))
		return (NULL);
	ret[i] = '\0';
	while (--i >= 0)
	{
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}

char	*ft_sub(char *s1, char *s2)
{
	int 	carry;
	int		s_len[3];
	int		i;
	char	*s;
	int		nb[3];

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	s_len[0] = s_len[1];
	carry = 0;
	if (!(s = ft_strnew(s_len[0] + 1)))
		return (NULL);
	i = 1;
	while (i <= s_len[1])	
	{
		nb[1] = ft_get_digit(s1, s_len[1], i);
		nb[2] = ft_get_digit(s2, s_len[2], i);
		nb[0] = ((nb[1] - carry) < nb[2] ? 10 : 0);
		s[s_len[0] - i]  = (nb[0] + nb[1] - nb[2] - carry) % 10 + '0';
		carry = (nb[0] ? 1 : 0);
		i++;
	}
	i = 0;
	while (s[i] == '0' && i < s_len[0] - 1)
		i++;
	if (i)
	{
		ft_memmove(s, s + i, s_len[0] - i);
		s[s_len[0] - i] = '\0';
	}
	return (s);
}
int	ft_strcmp_nb(const char *s1, const char *s2)
{
	int	s_len[3];

	s_len[1] = ft_strlen(s1);
	s_len[2] = ft_strlen(s2);
	if (s_len[1] > s_len[2])
		return (1);
	else if (s_len[1] < s_len[2])
		return (-1);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}

