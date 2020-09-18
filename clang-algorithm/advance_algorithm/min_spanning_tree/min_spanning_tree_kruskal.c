// min_spanning_tree.c
// 图的最小生成树
// kruskal最小生成树算法针对边来处理
// 啊哈算法 p215
// 测试数据
// 6 9 2 4 11 3 5 13 4 6 3 5 6 4 2 3 6 4 5 7 1 2 1 3 4 9 1 3 2
#include <stdio.h>
#include <time.h>
struct edge{
    int u;
    int v;
    int w;
} e[10]; // 结构体数组用于存储边,数组的大小比m大1
int n, m; // n顶点数,m边数
int f[7], sum = 0, count = 0; // 并查集数组比n大1

// 对所有边升序快排
void quickSort(int left, int right){
    int i, j;
    struct edge t;
    if (left > right) // 单元素时即有序直接返回
        return;
    i = left;
    j = right;
    while (i != j){
        while (e[j].w >= e[left].w && i < j) // 基准数为左边首元素,先从右边开始找
            j--;
        while (e[i].w <= e[left].w && i < j)
            i++;
        if (i < j){
            t = e[i];
            e[i] = e[j];
            e[j] = t;
        }
    }
    t = e[left];
    e[left] = e[i];
    e[i] = t;
    quickSort(left, i - 1);
    quickSort(i + 1, right);
}

// 并查集查找祖先
int getf(int v){
    if (f[v] == v) // 如果自己是祖先立即返回
        return v;
    else {
        f[v] = getf(f[v]); // 路径压缩即找祖先
        return f[v];
    }
}

// 并查集合并子集
int merge(int v, int u){
    int t1, t2;
    t1 = getf(v);
    t2 = getf(u);
    if (t1 != t2){ // 判断两个点是否在同一集合中
        f[t2] = t1; // 靠左原则
        return 1;
    }
    return 0;
}

int main(void){
    int i;
    int start, end;
    // 读取顶点数和变数
    scanf("%d %d", &n, &m);
    // 读取每条边
    for (i = 1; i <= m; i++){
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    // start counting time
    start = clock();
    quickSort(1, m);
    // 初始化并查集
    for (i = 1; i <= n; i++){
        f[i] = i;
    }
    // kruskal核心算法
    for (i = 1; i <= m; i++){ // 开始升序遍历每条边
        if (merge(e[i].u, e[i].v)){ // 如果两点不连通即无共同祖先
            count++;
            sum += e[i].w;
            printf("%d->%d,", e[i].u, e[i].v);
        }
        if (count == n - 1)
            break;
    }
    // end counting time
    end = clock();
    printf("\n%d\n", sum);
    printf("time=%.6f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
