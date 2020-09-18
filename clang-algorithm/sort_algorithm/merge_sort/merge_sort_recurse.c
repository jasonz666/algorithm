// merge sort recursively
#include <stdio.h>
#define N 9

void pnt(const int *data, int len, char *str){
    int i;
    printf("%s\n", str);
    for (i=0; i<len; i++)
        printf("%d ", data[i]);
    putchar('\n');
}

// 合并函数
void merge(int data[], int start, int middle, int end){
    int left, right, tmp[N], i, j;
    
    // 复制待合并数据到临时数组
    i = j = start;
    while (i <= end)
        tmp[j++] = data[i++];
    // 合并数据
    left = start;
    right = middle + 1;
    while (left <= middle && right <= end)
        data[start++] = tmp[left] <= tmp[right]? tmp[left++]: tmp[right++];
    // 放入剩余数据
    while (left <= middle)
        data[start++] = tmp[left++];
    while (right <= end)
        data[start++] = tmp[right++];
}

// 归并排序
void mergeSort(int data[], int start, int end){
    int middle;

    if (start < end){
        middle = (start + end) / 2;
        mergeSort(data, start, middle);
        mergeSort(data, middle + 1, end);
        merge(data, start, middle, end);
    }
}

int main(void){
    int data[N] = {9,1,5,3,4,2,6,8,7};
    int tmp[N] = {0};
    int len = N;

    mergeSort(data, 0, N -1);
    pnt(data, len, "sorted");
    
    return 0;
}
