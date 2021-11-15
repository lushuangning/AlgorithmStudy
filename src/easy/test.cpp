#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define __va_rounded_size(TYPE) \
    (((sizeof(TYPE) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

void fixed_args_func(const char* fmt, ...);

void fixed_args_func(const char* fmt, ...)
{
    char* ap;

    ap = ((char*)&fmt) + sizeof(fmt);
    printf("%d\n", *(int*)ap);

    //ap = (char*)ap + sizeof(int) + __va_rounded_size(int);
    ap = ap + sizeof(int);
    printf("%d\n", *(int*)ap);

    //ap = ap + sizeof(int) + __va_rounded_size(int);
    ap = ap + sizeof(int);
    printf("%s\n", *((char**)ap));

}

void std_vararg_func(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    printf("%d\n", va_arg(ap, int));
    printf("%f\n", va_arg(ap, double));
    printf("%s\n", va_arg(ap, char*));

    va_end(ap);
}

int main()
{
    //fixed_args_func("%d %d %s\n", 4, 5, "hello world");
    std_vararg_func("%d %f %s\n", 4, 5.4, "hello world");
    return 0;
}