// 使用循环实现
// 先把数列看成是n个长度为1的有序序列
// 然后相邻的有序序列成对归并得到n/2个长度为2的有序序列
// 再次归并得到n/4个长度为4的有序序列
// 如此反复执行直到一个长度为n的有序序列
#include <stdio.h>

void pnt(const int *data, int len){
    int i;
    for (i=0; i<len; i++)
        printf("%d ", data[i]);
    putchar('\n');
}

int main(void){
    int data[9] = {9, 1, 5, 3, 4, 2, 6, 8, 7};
    int sort[9] = {0};
    int len = 9;
    int idx, i, k, p1, p2, max1, max2;

    for (i = 1; i < len; i *= 2){
        idx = 0;
        for (k = 0; k < len; k += i * 2){
            p1 = k;
            p2 = p1 + i;
            max1 = p2 >= len? len: p2;
            max2 = p2 + i >= len? len: p2 + i;
            while (p1 < max1 && p2 < max2)
                sort[idx++] = data[p1] > data[p2]? data[p2++]: data[p1++];
            while (p1 < max1)
                sort[idx++] = data[p1++];
            while (p2 < max2)
                sort[idx++] = data[p2++];
        }
        for (k = 0; k < len; k++)
            data[k] = sort[k];
    }

    pnt(data, len);
    return 0;
}
