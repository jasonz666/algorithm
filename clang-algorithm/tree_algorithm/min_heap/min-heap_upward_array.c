// min-heap_upward_array.c
// 最小堆数据上调使用数组实现
// 啊哈算法 p190
#include <stdio.h>
#define N 14
int h[100] = {0,2,7,5,12,22,17,25,19,36,99,23,28,46,92};

void goUp(int i);
void swap(int x, int y);

void goUp(int i){
    while (i != 1){
        if (h[i] < h[i/2])
            swap(i, i/2);
        else
            break;
        i /= 2;
    }
}

void swap(int x, int y){
    int t;

    t = h[x];
    h[x] = h[y];
    h[y] = t;
}

int main(void){
    int num = 3;
    int i;

    for (i = 1; i <= N; i++){
        printf("%d, ", h[i]);
    }
    putchar('\n');

    // 添加新值到树的最后即在数组末尾增加值
    h[N+1] = num;
    goUp(N+1);
    for (i = 1; i <= N + 1; i++){
        printf("%d, ", h[i]);
    }
    putchar('\n');

    return 0;
}
