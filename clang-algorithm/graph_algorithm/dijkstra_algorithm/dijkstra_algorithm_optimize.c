// dijkstra_algorithm.c
// 单源最短路径算法
// 使用堆和邻接表优化
// 测试数据
// 6 9 1 2 1 1 3 12 2 3 9 2 4 3 3 5 5 4 3 4 4 5 13 4 6 15 5 6 4
#include <stdio.h>
#include <time.h>
int start, end;
// h保存堆,pos保存顶点在堆中位置
// dis保存生成树到非树顶点的距离
int h[7], pos[7], size, dis[7];

// 交换堆中两个元素的值同时更新pos数组
void swap(int x, int y){
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
    t = pos[h[x]];
    pos[h[x]] = pos[h[y]];
    pos[h[y]] = t;
}

// 向下调整元素以维持最小堆
void siftdown(int i){ // 参数为需要下调的节点编号
    int t;
    while (i * 2 <= size){
        // 比较i和左儿子i*2在dis中的值并记录较小的节点编号
        if (dis[h[i]] > dis[h[i * 2]])
            t = i * 2;
        else
            t = i;
        // 存在右儿子则比较
        if (i * 2 + 1 <= size){
            if (dis[h[t]] > dis[h[i * 2 + 1]])
                t = i * 2 + 1;
        }
        // 需要交换
        if (t != i){
            swap(t, i);
            i = t;
        }
        else
            break;
    }
}

// 上调元素以维持松弛成功的节点在最小堆中位置
void siftup(int i){ // 参数为需要上调的节点编号
    while (i != 1){ // 节点不在堆顶时判断是否要上调
        if (dis[h[i]] < dis[h[i / 2]])
            swap(i, i / 2);
        else
            break;
        i = i / 2;
    }
}

// 从堆顶取出元素,该元素为离源点最近的顶点
int pop(void){
    int t;
    t = h[1];
    h[1] = h[size]; // 堆中最后元素放到堆顶
    pos[h[1]] = 1;  // 更新最后元素此时在堆中位置
    size--;
    siftdown(1);   // 维持最小堆,此时离源点最近的顶点在堆顶
    return t;
}

int main(void){
    int n, m; // n为顶点数,m为边数
    int u[10], v[10], w[10], next[10], first[7]; // 保存每条边
    int book[10] = {0}; // 标记已扩展过的点
    int inf = 999999;
    int path[7] = {0}; // 存储路径
    int i, j, k;

    // 读入顶点和边数
    scanf("%d %d", &n, &m);

    // 读入边
    for (i = 1; i <= m; i++){
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    // 使用邻接表存储
    for (i = 1; i <= n; i++)
        first[i] = -1;
    for (i = 1; i <= m; i++){
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    // 初始化dis数组
    dis[1] = 0;
    for (i = 2; i <= n; i++)
        dis[i] = inf;
    k = first[1];
    while (k != -1){
        dis[v[k]] = w[k];
        k = next[k];
    }
    
    // 初始化堆
    size = n;
    for (i = 1; i <= size; i++){
        h[i] = i;
        pos[i] = i;
    }
    for (i = size / 2; i >= 1; i--)
        siftdown(i); // 根据dis中的值生成最小堆
    pop(); // 弹出源点即1号顶点

    // start counting time
    start = clock();
    // dijkstra核心算法
    book[1] = 1;
    for (i = 1; i <= n - 1; i++){
        j = pop(); // 弹出离1号顶点最近的顶点
        book[j] = 1;
        k = first[j];
        while (k != -1){ // 对j的所有出边使用邻接表松弛
            if (book[v[k]] == 0 && dis[v[k]] > dis[j] + w[k]){
                dis[v[k]] = dis[j] + w[k];
                // 对该顶点在堆中的位置进行上调
                // 使离源点最近的顶点在堆顶
                siftup(pos[v[k]]);
                // 终点v[k]的上一个点是j
                // 如果某点的上一点是0表示上一点是源点
                path[v[k]] = j; 
            }
            k = next[k];
        }
    }
    // end counting time
    end = clock();

    // 输出结果
    for (i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    putchar('\n');
    // 输出路径,逆向
    for (i = 2; i <= n; i++){
        printf("%d<-", i);
        for(j = path[i]; j != 0; ){
            printf("%d<-", j);
            j = path[j];
        }
        puts("1");
    }
    printf("time=%.6f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
