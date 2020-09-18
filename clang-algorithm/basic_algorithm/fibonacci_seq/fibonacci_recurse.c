#include <stdio.h>
int count;
int fibonacci(int f[], int idx);

int fibonacci(int f[], int idx){
    count++;
    if (idx < 2){
        return idx;
    } else {
        f[idx] = fibonacci(f, idx-1) + fibonacci(f, idx-2);
    }
}

int main(void){
    int fib[100] = {0, 1};
    int len=7;
    int i;

    fibonacci(fib, len);
    for (i=0; i<len; i++){
        printf("%d  ", fib[i]);
    }
    putchar('\n');
    printf("counts=%d\n", count);
    return 0;
}
