// 测试所有搜索算法的时间
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50000
#define D 30000

// 哈希表数值存储链
struct dt{
    int x;
    struct dt * next;
};

// 随机数生成
void randArray(int arr[], int n){
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % n;
}

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

// 线性搜索
int linFind(int data[], int n, int num){
    int i;
    for (i = 0; i < n; i++)
        if (data[i] == num)
            return i;
    return -1;
}

// 二分搜索 快速排序
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

// 二分搜索函数
int binFind(int data[], int start, int end, int num){
    int mid = (start + end) / 2;
    int ret;

    if (start > end)
        return -1;

    if (data[mid] == num)
        return mid; // 找到则返回下标

    if (num < data[mid])
        ret = binFind(data, start, mid - 1, num);
    if (num > data[mid])
        ret = binFind(data, mid + 1, end, num);
    return ret;
}

// 二分搜索函数非递归 参数n为数组的大小
int binFind2(int data[], int n, int num){
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
    int s, e, num, idx, i;
    int tmp[MAX];
    int d1[MAX], d2[MAX], d3[MAX];
    struct dt * ht[D] = {NULL};

    randArray(tmp, MAX);
    printf("search a num in %d random numbers:\n", MAX);

    memmove(d1, tmp, sizeof(int) * MAX);
    memmove(d2, tmp, sizeof(int) * MAX);
    memmove(d3, tmp, sizeof(int) * MAX);

    puts("input a num to search:");
    scanf("%d", &num);

    for (i = 0; i < MAX; i++) hashCreate(ht, d1[i]);
    s = clock();
    if ((idx = hashFind(ht, num)) != -1) printf("index=%d, ", idx);
    else printf("%d, ", idx);
    e = clock();
    printf("hashFind Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    if ((idx = linFind(d1, MAX, num)) != -1) printf("data[%d]=%d, ", idx, d1[idx]);
    else printf("%d, ", idx);
    e = clock();
    printf("linFind Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    quickSort(d2, 0, MAX - 1);
    s = clock();
    if ((idx = binFind(d2, 0, MAX - 1, num)) != -1) printf("data[%d]=%d, ", idx, d2[idx]);
    else printf("%d, ", idx);
    e = clock();
    printf("binFind Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    quickSort(d3, 0, MAX - 1);
    s = clock();
    if ((idx = binFind2(d3, MAX, num)) != -1) printf("data[%d]=%d, ", idx, d3[idx]);
    else printf("%d, ", idx);
    e = clock();
    printf("binFindCircle Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);
    return 0;
}
