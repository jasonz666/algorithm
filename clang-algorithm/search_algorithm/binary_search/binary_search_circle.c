// 二分搜索非递归
// 对数据排序后进行二分搜索
#include <stdio.h>

// 快速排序函数
void quickSort(int data[], int left, int right){
    int base, i, j, t;

    if (left > right) // 只有单个数据时即为有序
        return;

    base = data[left];
    i = left;
    j = right;
    while (i < j){
        // 基准数为左侧元素则先从右侧开始比较
        while (data[j] >= base && i < j)
            j--;
        while (data[i] <= base && i < j)
            i++;
        if (i < j){
            t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
    }
    data[left] = data[i];
    data[i] = base;

    quickSort(data, left, i - 1);
    quickSort(data, i + 1, right);
}

// 参数n为数组的大小
int binFind(int data[], int n, int num){
    int low = 0, high = n - 1;
    int mid = (low + high) / 2;

    while (low <= high){
        if (num == data[mid])
            return mid; // 找到则返回下标
        if (num < data[mid]){
            high = mid - 1;
            mid = (low + high) / 2;
        }
        if (num > data[mid]){
            low = mid + 1;
            mid = (low + high) / 2;
        }
        mid = (low + high) / 2;
    }
    return -1;
}

int main(void){
    int data[10] = {1, 3, 5, 4, 2, 7, 9, 0, 9, 6};
    int num;
    int idx;

    puts("input an integer to search");
    scanf("%d", &num);

    quickSort(data, 0, 9);
    idx = binFind(data, 10, num);
    if (idx != -1)
        printf("%d,index=%d,data[%d]=%d\n", num, idx, idx, data[idx]);
    else
        printf("can't find %d\n", num);
    return 0;
}
