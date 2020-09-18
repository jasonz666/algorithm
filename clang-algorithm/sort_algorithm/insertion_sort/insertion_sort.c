// insertion sort
#include <stdio.h>
int main(void){
    int data[6] = {77, 19, 80, 79, 20, 11};
    int i, j, key;
    int len = 6;

    for (i = 1; i < len; i++){
        // 保存待插入数据
        key = data[i];
        // 在有序序列中从右往左找插入位置
        j = i - 1;
        // 从右往左的好处是每次遇到比待插数据大的数时往右移动
        while (j >= 0 && data[j] > key){
            data[j + 1] = data[j];
            j--;
        }
        // 找到插入位置后放入带插数据
        data[j + 1] = key;
    }

    for (i = 0; i < len; i++){
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
