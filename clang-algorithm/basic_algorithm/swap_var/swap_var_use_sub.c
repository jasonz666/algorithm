// swap_var_use_subtract.c
#include <stdio.h>
int main(void){
    int a=1;
    int b=3;
    
    a = b - a;
    b = b - a;
    a = b + a;

    printf("the old a=%d, b=%d\n", 1, 3);
    printf("now the a=%d, b=%d\n", a, b);

    return 0;
}
