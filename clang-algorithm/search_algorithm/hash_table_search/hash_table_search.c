// 利用哈希表结构搜索数据
// 将数据散列后存入哈希表
// 写给大家看的算法书 p138
#include <stdio.h>
#include <stdlib.h>
#define D 5

struct dt{
    int x;
    struct dt * next;
};

// 建立哈希表
void hashCreate(struct dt * data[], int num){
    // 取余数法求哈希值,此法数值不能为负数
    // 被除数D要小于数据总个数N
    int h = num % D;
    struct dt * p, * n = NULL;

    // 用链表存储哈希值一致但数值不同的数据
    p = (struct dt *)malloc(sizeof(struct dt));

    // 哈希值h作为数组的下标
    if ((n = data[h]) == NULL){
        data[h] = p;
        p->x = num; // 存储新值
        p->next = NULL;
    } else{
        data[h] = p;
        p->x = num;
        p->next = n;
    }
}

// 哈希表搜索数据
int hashFind(struct dt * data[], int num){
    int h = num % D;
    struct dt * n;

    n = data[h];
    while (n != NULL){
        if (n->x == num)
            return h; // 找到数据则返回下标
        n = n->next;
    }
    return -1;
}

int main(void){
    int data[10] = {1, 3, 5, 4, 2, 7, 9, 0, 9, 6};
    // 哈希表长度为被除数D的值
    struct dt * ht[D] = {NULL}; // 这里必须初始化指针为NULL
    int i, num, idx;

    for (i = 0; i < 10; i++){
        hashCreate(ht, data[i]);
    }

    puts("input an integer to search");
    scanf("%d", &num);
    idx = hashFind(ht, num);
    if (idx != -1)
        printf("%d,index=%d\n", num, idx);
    else
        printf("can't find %d\n", num);

    return 0;
}
