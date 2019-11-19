#include <stdio.h>
#include <stdarg.h>
 
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
    display("Age:%d \t Weight:%f\n", 24, 68.4);
    printf("Age:%2$i  Weight:%1$i\n", 24, 68);
    printf("Age:%d  Weight:%d\n", 24, 68);
     printf("%lu %lu %lu %lu\n", sizeof(double), sizeof(double *), sizeof(char), sizeof(char *));
    printf("test %*.*i, %*i", 5, 2, 1, 2, 3);
    printf("test %1$*.*i, %*i", 5, 2, 1, 2, 3);
    return 0;

}