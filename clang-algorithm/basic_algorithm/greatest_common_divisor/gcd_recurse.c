#include <stdio.h>
int count;
int gcd(x, y){
    count++;
    if (x % y == 0){
        return y;
    } else {
        gcd(y, x % y);
    }
}

int main(void){
    int x=126, y=90;

    printf("gcd is %d\n", gcd(x, y));
    printf("count=%d\n", count);
    return 0;
}
