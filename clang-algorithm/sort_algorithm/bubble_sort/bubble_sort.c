// bubble sort
#include <stdio.h>
int main(void){
    int data[5] = {80, 77, 54, 19, 11};
    int i, j, t;
    int len = 5;

    // 排序前数据输出
    for (i=0; i<len; i++){
        printf("%d ", data[i]);
    }
    putchar('\n');

    // len个数据只需要len-1趟排序
    for (i = 0; i < len - 1; i++){
        // 每趟比较次数不断减少
        for (j = 0; j < len - i - 1; j++){
            if (data[j] > data[j+1]){
                // 交换两个变量的值
                t = data[j];
                data[j] = data[j+1];
                data[j+1] = t;
            }
       }
    }

    // 排序后输出
    for (i=0; i<len; i++){
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
} 
