#include <stdio.h>
int main(void){
    int a=1;
    int b=3;
    
    a = a^b;
    b = a^b;
    a = a^b;

    printf("the old a=%d, b=%d\n", 1, 3);
    printf("now the a=%d, b=%d\n", a, b);

    return 0;
}
