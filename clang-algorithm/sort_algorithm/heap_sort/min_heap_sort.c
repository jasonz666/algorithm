// min_heap_sort.c
// 使用最小堆排序
// 啊哈算法 p194
#include <stdio.h>
int h[100];
int n;

void swap(int x, int y){
    int t;

    t = h[x];
    h[x] = h[y];
    h[y]= t;
}

void siftDown(int i){ // 节点编号传入1表示从堆顶开始
    int t;

    // 当i节点至少有左子节点且需要往下调整时
    while (i * 2 <= n){
        // 如果节点i大于左子节点则记录较小节点编号
        if (h[i] > h[i * 2])
            t = i * 2;
        else
            t = i;
        // 如果存在右子节点也比较
        if (i * 2 + 1 <= n){
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

void createHeap(void){ // 创建堆
    int i;

    // 从最后一个非叶节点到顶点依次向下调整
    for (i = n/2; i >= 1; i--)
        siftDown(i);
}

int deleteMin(void){
    int t;
    t = h[1]; // 存储堆顶的目前最小值
    h[1] = h[n]; // 堆的最后一个数作为新顶点
    n--;
    siftDown(1); // 对新顶点向下调整
    return t;
}

int main(void){
    int i, num;
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
        scanf("%d", &h[i]);
    n = num;

    createHeap();

    // 依次输出堆顶元素即是排序后的数据
    for (i = 1; i <= num; i++)
        printf("%d ", deleteMin());
    putchar('\n');
    return 0;
}
