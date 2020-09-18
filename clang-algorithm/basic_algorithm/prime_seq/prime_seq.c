// 埃拉托斯特尼筛法求质数序列
// 写给大家看的算法书 p154
#include <stdio.h>
#include <math.h>
#define N 1000000

int primeSeq(int data[], int n, int prime[]){
    int p; // p为当前质数的下标
    int e; // e为最后元素的下标
    int i, idx = 0;

    p = 2;
    e = n;
    while (p < e && p * p <= data[e]){
        // 当前质数的倍数从平方开始
        // 比如当前质数是5，5*2,5*3,5*4，就是2*5,3*5,4*5，前面已经由2,3,4剔除过5，
        // 不需要重复剔除，因此从5*5开始，但还是有重复剔除存在，
        // 比如 (2*2)+2+2+2+2=12，(3*3)+3=12，12剔除了2次，所以需要跳过被剔除的倍数
        for (i = p * p; i <= e; i += p)
            data[i] = 0; // 剔除当前质数的倍数
        while (data[e] == 0) e--; // 跳过被剔除的倍数
        p++; while (data[p] == 0) p++; // 下一个质数
    }
    for (i = 2; i <= n; i++){
        if (data[i] != 0)
            prime[idx++] = data[i];
    }
    return idx;
}

int isPrime(int n){
    int i;
    double sq;

    for (i = 2, sq = sqrt(n); i <= sq; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main(void){
    int data[N];
    int prime[N];
    int n, i, ret;

    printf("input a num as N (max = %d): ", N);
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
        data[i] = i;

    ret = primeSeq(data, n, prime);
    for (i = 0; i < ret; i++)
        printf("%d, ", prime[i]);
    putchar('\n');

    puts("--------> is not prime <--------");
    for (i = 0; i < ret; i++){ // 检查是不是质数
        if (isPrime(prime[i]))
            continue;
        else
            printf("%d\n", prime[i]);
    }

    return 0;
}
