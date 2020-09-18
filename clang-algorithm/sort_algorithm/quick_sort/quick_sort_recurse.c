//quick_sort_recurse.c
#include <stdio.h>

void quick(int data[], int left, int right){
    int i, j, base, tmp;

    //只有一个数据时即为有序的
    if (left > right)
        return;

    base = data[left];
    i = left; //这里是left+1将会导致单元素数组越界
    j = right;

    while (i != j){
        //首元素作为基准时先从右往左遍历
        while (data[j] >= base && i < j)
            j--;
        //然后从左往右遍历
        while (data[i] <= base && i < j)
            i++;
        //仅在左右遍历指针不相遇时交换值
        if (i < j){
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }

    //遍历指针相遇时交换该值和基准值
    //此时基准值的位置已确定
    data[left] = data[i];
    data[i] = base;
    
    //递归的处理左右子序列
    quick(data, left, i - 1);
    //只有一个数据时子序列会出现left>right
    quick(data, i + 1, right);
}

void pnt(const int *data, int len){
    int i;
    for (i=0; i<len; i++)
        printf("%d ", data[i]);
    putchar('\n');
}

int main(void){
    int data[10] = {6, 1, 2, 7, 9, 10, 4, 5, 3, 8};

    quick(&data[0], 0, 9);
    pnt(data, 10);
    return 0;
}
