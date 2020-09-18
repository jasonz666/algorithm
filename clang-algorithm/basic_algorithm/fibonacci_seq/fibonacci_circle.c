#include <stdio.h>
int count;
int main(void)
{
    int f[100] = {0, 1};
    int i = 2;
    int len=7;
    
    for (i=2; i<len; i++){
        count++;
        f[i] = f[i-1] + f[i-2];
    }

    printf("the fibonacci list is:\n");
    for (i=0; i<len; i++){
        printf("%d  ", f[i]);
    }
    putchar('\n');
    printf("count=%d\n", count);
    return 0;
}
