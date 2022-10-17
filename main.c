#include "main.h"
#include <stdio.h>
#include "_printf.c"
#include "handlers.c"
#include "convert_charactor.c"
#include "memory_manager.c"
#include "convert_strings.c"
#include "modifiers.c"

int main(void)
{
    int x = _printf("Hello %c\n", 'Z');
    int y = _printf("Hi Mr %s\n", "Tsohle");

    return 0;
}