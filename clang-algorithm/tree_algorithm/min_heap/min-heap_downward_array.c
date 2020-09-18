// min-heap_downward.c
// 最小堆新增数值从堆顶向下调整使用数组实现
// 啊哈算法 p188
#include <stdio.h>
#define TOTAL 14
int h[100] = {0,
    1,2,5,12,7,17,25,19,36,99,22,28,46,92
};

void goDown(int i);
void swap(int x, int y);

void goDown(int i){ // 节点编号传入1表示从堆顶开始
    int t;

    // 当i节点至少有左子节点且需要往下调整时
    while (i * 2 <= TOTAL){
        // 如果节点i大于左子节点则记录较小节点编号
        if (h[i] > h[i * 2])
            t = i * 2;
        else
            t = i;
        // 如果存在右子节点也比较
        if (i * 2 + 1 <= TOTAL){
            if (h[t] > h[i * 2 + 1])
                t = i * 2 + 1;
        }
        // 如果最小节点编号不是自己则需要向下调整
        if (t != i){
            swap(t, i);
            i = t; // 更新节点编号以便继续向下调整
        }
        else
            break;
    }
}

void swap(int x, int y){
    int t;

    t = h[x];
    h[x] = h[y];
    h[y] = t;
}

int main(void){
    int num = 23;
    int i;

    for (i = 1; i <= TOTAL; i++)
        printf("%d, ", h[i]);
    putchar('\n');
    h[1] = num;
    goDown(1);
    for (i = 1; i <= TOTAL; i++)
        printf("%d, ", h[i]);
    putchar('\n');

    return 0;
}
