#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <string.h>

int 	ft_div_int(char *s1, char *s2)
{
	int		ret;
	char	*s;
	
	ret = 1;
	while (ret < 10)
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

void display(char* format, ...)
{
    int d; 
    double f;
    va_list factor;         // указатель на необязательный параметр
    va_start(factor, format);   // устанавливаем указатель
     
    for(char *c = format;*c; c++)
    {
        if(*c!='%')
        {
            printf("%c", *c);
            continue;
        }
        switch(*++c)
        {
            case 'd': 
                d = va_arg(factor, int);
                printf("%d", d);
                break;
            case 'f': 
                f = va_arg(factor, double);
                printf("%.2lf", f);
                break;
            default:
                printf("%c", *c);
        }
    }
    va_end(factor);
}
 
int main(void)
{   
   int i;

   i = ft_div_int("2320", "256");
   printf("i=%i\n", i);
   
 
    display("Age:%d \t Weight:%f\n", 24, 68.4);
    printf("Age:%2$i  Weight:%1$i\n", 24, 68);
    printf("Age:%d  Weight:%d\n", 24, 68);
  /*  printf("%lu %lu %lu %lu\n", sizeof(double), sizeof(double *), sizeof(char), sizeof(char *));
    printf("test %*.*i, %*i", 5, 2, 1, 2, 3);
    printf("test %*i, %*i", 5, 2, 1, 3);*/
	struct lconv *lc;
    lc = localeconv();
	if (lc->thousands_sep)
        printf("thousand=%s=\n", lc->thousands_sep);


        
    return 0;

}