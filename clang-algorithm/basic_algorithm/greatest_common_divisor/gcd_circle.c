// filename: greatest_common_divisor_circle.c
#include <stdio.h>
int count;
int main(void){
    int x=126, y=90;
    int ret;

    for (ret = x % y; ret != 0; ){
        count++;
        x = y;
        y = ret;
        ret = x % y;
    }
    printf("gcd is %d\n", y);
    printf("count=%d\n", count);
    return 0;
}
