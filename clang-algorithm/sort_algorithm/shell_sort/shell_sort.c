// shell_sort.c
#include <stdio.h>
#define N 12

void pnt(const int *data, int len, char *str){
    int i;
    printf("%s\n", str);
    for (i=0; i<len; i++)
        printf("%d ", data[i]);
    putchar('\n');
}

int main(void){
    int data[N] = {92, 80, 77, 67, 55, 35, 26, 20, 19, 11, 10, 2};
    int step; // 分组数量和步长均为step
    int i, j, k, key;

    for (step = N / 2; step > 0; step /= 2){
        // 对每个分组进行插入排序
        for (i = 0; i < step; i++){
            // 插入排序核心算法
            for (j = i + step; j < N; j++){
                key = data[j];
                k = j - 1;
                while (k >= 0 && data[k] > key){
                    data[k + 1] = data[k];
                    k--;
                }
                data[k + 1] = key;
            }
        }
    }

    pnt(data, N, "sorted:");
    return 0;
}
