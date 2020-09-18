// 递归求阶乘
// 写给大家看的算法书 p156
#include <stdio.h>

int fact(int n){
    if (1 == n)
        return 1;
    else
        return fact(n - 1) * n;
}

int main(void){
    int n;

    puts("input a num to compute factorial:");
    scanf("%d", &n);

    printf("%d\n", fact(n));
    return 0;
}
