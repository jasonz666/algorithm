// dijkstra_algorithm.c
// 单源最短路径算法
// 啊哈算法 p158
#include <stdio.h>
#include <time.h>
#define M 9999
int start, end;
int main(void){
    int e[10][10] = {{0}, // 图存储
        {0, 0, 1, 12, M, M, M},
        {0, M, 0, 9, 3, M, M},
        {0, M, M, 0, M, 5, M},
        {0, M, M, 4, 0, 13, 15},
        {0, M, M, M, M, 0, 4},
        {0, M, M, M, M, M, 0}
    };
    int book[10] = {0}; // 标记已扩展过的点
    int n = 6; // 顶点数
    int dist[10]; // 存储1号源点到其余顶点的初始路程
    int i, j, u, v, min;
    int path[7] = {0}; // 存储路径

    // 初始化dist数组
    for (i = 1; i <= n; i++)
        dist[i ] = e[1][i];

    // start counting time
    start = clock();
    // dijkstra核心算法
    book[1] = 1;
    for (i = 1; i <= n-1 ; i++){
        min = M;
        // 找到离1号顶点最近的顶点
        for (j = 1; j <= n; j++){
            if (book[j] == 0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }
        book[u] = 1; // 标记该点
        // 对顶点u的所有出边进行松弛操作
        for (v = 1; v <= n; v++){
            if (book[v] == 0 && dist[v] > dist[u] + e[u][v]){
            // 等价于: if (e[u][v] < M && dist[v] > dist[u] + e[u][v]){
            // 因为这里是有向图,当无向图时则用: book[v] == 0 排除已扩展过的顶点
                dist[v] = dist[u] + e[u][v];
                // 终点v的上一个点是u
                // 如果某点的上一点是0表示上一点是源点
                path[v] = u; 
            }
        }
    }
    // end counting time
    end = clock();

    // 输出结果
    for (i = 1; i <= n; i++)
        printf("%d ", dist[i]);
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
