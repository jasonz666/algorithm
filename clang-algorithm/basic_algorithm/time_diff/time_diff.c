// 求时分秒形式的时间差
// 先将时分秒形式转换为秒形式
// 然后求差后把秒形式转换为时分秒形式
#include <stdio.h>
#define H 3600
#define M 60
int main(void){
    int h1=6, m1=32, s1=12;
    int h2=9, m2=10, s2=52;
    int sec1, sec2, sec;
    int h, m, s, tmp;

    sec1 = h1*H + m1*M + s1;
    sec2 = h2*H + m2*M + s2;
    sec = sec2 - sec1;
    
    // convert sec to H:M:S
    h = sec / H;
    tmp = sec % H;
    m = tmp / M;
    s = tmp % M;

    printf("time1:\n\t%d:%d:%d\n", h1,m1,s1);
    printf("time2:\n\t%d:%d:%d\n", h2,m2,s2);
    printf("diff:\n\t%d:%d:%d\n", h,m,s);

    return 0;
} 
