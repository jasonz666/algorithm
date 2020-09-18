// selection sort
#include <stdio.h>
int main(void){
    int data[8] = {35, 80, 21, 54, 11, 45, 92, 39};
    int len = 8;
    int tmp;
    int i, j;

    // len个数据需要排序len-1趟
    for (i = 0; i < len - 1; i++){
        // 每趟排序的比较次数
        for (j = i + 1; j < len; j++){
            if (data[j] < data[i]){
                tmp = data[j];
                data[j] = data[i];
                data[i] = tmp;
            }
        }
    }
    
    // display
    for (i = 0; i < len; i++){
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
