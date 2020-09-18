// 所有8种排序算法时间比较
// 对3万个随机数据进行排序
// 除堆排序之外的其他排序算法数组下标从0开始
// 堆排序中数组下标从1开始
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 30000

// 随机数生成
void randArray(int arr[], int n){
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % n;
}

// 冒泡排序
void bubbleSort(int data[], int n){
    int i, j, t;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (data[j] > data[j+1]){
                t = data[j];
                data[j] = data[j+1];
                data[j+1] = t;
            }
        }
    }
}

// 简单桶排序
void bucketSort(int data[], int n){
    int bucket[MAX+1] = {0};
    int i, j, k = 0;
    for (i = 0; i < n; i++)
        bucket[data[i]] += 1;
    for (i = 0; i < n + 1; i++){
        for (j = 0; j < bucket[i]; j++)
            data[k++] = i;
    }
}

// 选择排序
void selectionSort(int data[], int n){
    int i, j, t;
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (data[j] < data[i]){
                t = data[j];
                data[j] = data[i];
                data[i] = t;
            }
        }
    }
}

// 插入排序
void insertionSort(int data[], int n){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > key){
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// 希尔排序
void shellSort(int data[], int n){
    int step, i, j, k, key;
    for (step = n / 2; step > 0; step /= 2){
        for (i = 0; i < step; i++){
            for (j = i + step; j < n; j += step){
                key = data[j];
                k = j - step;
                while (k >= 0 && data[k] > key){
                    data[k + step] = data[k];
                    k -= step;
                }
                data[k + step] = key;
            }
        }
    }
}

// 快速排序
void quickSort(int data[], int left, int right){
    int i, j, base, tmp;
    if (left > right)
        return;
    base = data[left];
    i = left;
    j = right;
    while (i != j){
        while (data[j] >= base && i < j)
            j--;
        while (data[i] <= base && i < j)
            i++;
        if (i < j){
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    data[left] = data[i];
    data[i] = base;
    quickSort(data, left, i - 1);
    quickSort(data, i + 1, right);
}

// 归并排序使用循环
void mergeCircle(int data[], int n){
    int tmp[MAX], idx, i, k, p1, p2, max1, max2;
    for (i = 1; i < n; i *= 2){
        idx = 0;
        for (k = 0; k < n; k += i * 2){
            p1 = k;
            p2 = p1 + i;
            max1 = p2 >= n? n: p2;
            max2 = p2 + i >= n? n: p2 + i;
            while (p1 < max1 && p2 < max2)
                tmp[idx++] = data[p1] > data[p2]? data[p2++]: data[p1++];
            while (p1 < max1)
                tmp[idx++] = data[p1++];
            while (p2 < max2)
                tmp[idx++] = data[p2++];
        }
        for (k = 0; k < n; k++)
            data[k] = tmp[k];
    }
}

// 归并排序使用递归 合并函数
void merge(int data[], int start, int middle, int end){
    int left, right, tmp[MAX], i, j;
    i = j = start;
    while (i <= end)
        tmp[j++] = data[i++];
    left = start;
    right = middle + 1;
    while (left <= middle && right <= end)
        data[start++] = tmp[left] <= tmp[right]? tmp[left++]: tmp[right++];
    while (left <= middle)
        data[start++] = tmp[left++];
    while (right <= end)
        data[start++] = tmp[right++];
}

// 归并排序使用递归 归并排序
void mergeSort(int data[], int start, int end){
    int middle;
    if (start < end){
        middle = (start + end) / 2;
        mergeSort(data, start, middle);
        mergeSort(data, middle + 1, end);
        merge(data, start, middle, end);
    }
}

// 堆排序 数值向下调整
void siftDown(int h[], int n, int i){
    int t, tmp;
    while (i * 2 <= n){
        if (h[i] < h[i * 2])
            t = i * 2;
        else
            t = i;
        if (i * 2 + 1 <= n){
            if (h[t] < h[i * 2 + 1])
                t = i * 2 + 1;
        }
        if (t != i){
            tmp = h[t];
            h[t] = h[i];
            h[i] = tmp;
            i = t;
        }
        else
            break;
    }
}

// 堆排序 创建堆函数
void createHeap(int h[]){
    int i;
    for (i = MAX / 2; i >= 1; i--)
        siftDown(h, MAX, i);
}

// 堆排序
void heapSort(int h[], int n){
    int tmp;
    while (n > 1){
        tmp = h[1];
        h[1] = h[n];
        h[n] = tmp;
        n--;
        siftDown(h, n, 1);
    }
}

// 主函数
int main(void){
    int tmp[MAX];
    int d1[MAX], d2[MAX], d3[MAX], d4[MAX], d5[MAX];
    int d6[MAX], d7[MAX], d8[MAX], d9[MAX + 1];
    int s, e;

    randArray(tmp, MAX);
    printf("sorting for %d random numbers:\n", MAX);

    memmove(d1, tmp, sizeof(int) * MAX);
    memmove(d2, tmp, sizeof(int) * MAX);
    memmove(d3, tmp, sizeof(int) * MAX);
    memmove(d4, tmp, sizeof(int) * MAX);
    memmove(d5, tmp, sizeof(int) * MAX);
    memmove(d6, tmp, sizeof(int) * MAX);
    memmove(d7, tmp, sizeof(int) * MAX);
    memmove(d8, tmp, sizeof(int) * MAX);
    memmove(&d9[1], tmp, sizeof(int) * MAX);

    s = clock();
    bubbleSort(d1, MAX);
    e = clock();
    printf("bubbleSort Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    bucketSort(d2, MAX);
    e = clock();
    printf("bucketSort Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    selectionSort(d3, MAX);
    e = clock();
    printf("selectionSort Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    insertionSort(d4, MAX);
    e = clock();
    printf("insertionSort Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    shellSort(d5, MAX);
    e = clock();
    printf("shellSort Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    quickSort(d6, 0, MAX - 1);
    e = clock();
    printf("quickSort Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    mergeCircle(d7, MAX);
    e = clock();
    printf("mergeCircle Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);
    
    s = clock();
    mergeSort(d8, 0, MAX - 1);
    e = clock();
    printf("mergeRecurse Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    s = clock();
    createHeap(d9);
    heapSort(d9, MAX);
    e = clock();
    printf("heapSort Time = %.6f S\n", (double)(e - s)/CLOCKS_PER_SEC);

    // 比较结果
    printf("\n########################################\n");
    printf("all sorted data is equal or not:\n");
    printf("result bubbleSort and bucketSort, %d\n", memcmp(d1, d2, sizeof(int) * MAX));
    printf("result bucketSort and selectionSort, %d\n", memcmp(d2, d3, sizeof(int) * MAX));
    printf("result bucketSort and insertionSort, %d\n", memcmp(d2, d4, sizeof(int) * MAX));
    printf("result bucketSort and shellSort, %d\n", memcmp(d2, d5, sizeof(int) * MAX));
    printf("result bucketSort and quickSort, %d\n", memcmp(d2, d6, sizeof(int) * MAX));
    printf("result bucketSort and mergeCircle, %d\n", memcmp(d2, d7, sizeof(int) * MAX));
    printf("result bucketSort and mergeRecurse, %d\n", memcmp(d2, d8, sizeof(int) * MAX));
    printf("result bucketSort and heapSort, %d\n", memcmp(d2, &d9[1], sizeof(int) * MAX));
    printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
    
    return 0;
}
