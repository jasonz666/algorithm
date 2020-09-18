// min_spanning_tree.c
// 图的最小生成树
// prim最小生成树算法针对顶点来处理
// 啊哈算法 p222
// 测试数据
// 6 9 2 4 11 3 5 13 4 6 3 5 6 4 2 3 6 4 5 7 1 2 1 3 4 9 1 3 2
#include <stdio.h>
#include <time.h>
int main(void){
    int n, m, i, j, k, min, t1, t2, t3;
    int e[7][7], dis[7], book[7] = {0}; // 初始化book数组,3个数组大小比n大1
    int count = 0, sum = 0; // 分别表示顶点计数,路径和
    int inf = 999999;
    int start, end;

    // 读入顶点数和边数
    scanf("%d %d", &n, &m);

    // 初始化
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
        }
    }

    // 读入边
    for (i = 1; i <= m; i++){
        scanf("%d %d %d", &t1, &t2, &t3);
        // 无向图需要反向再存储一遍权值
        e[t1][t2] = t3;
        e[t2][t1] = t3;
    }

    // 初始化dis数组,表示1号顶点到其他顶点的距离,开始时生成树只有1号顶点
    for (i = 1; i <= n; i++)
        dis[i] = e[1][i];

    printf("1"); // 打印起始顶点1
    // prim算法核心部分
    // start counting time
    start = clock();
    book[1] = 1; // 表示1号顶点已经加入生成树
    count++;
    while (count < n){
        min = inf;
        for (i = 1; i <= n; i++){ // 找出dis数组中离生成树最短的路径
            if (book[i] == 0 && dis[i] < min){
                min = dis[i];
                j = i; // 记录此时的顶点
            }
        }
        book[j] = 1; count++; sum += dis[j]; // 标记该顶点且总路径增加
        printf("->%d", j); // 打印该顶点
        // 扫描当前顶点j的所有边,以j为中心点更新生成树到其他非树顶点的距离
        for (k = 1; k <= n; k++){
            // dis[k]>e[j][k] 表示通过j->k边的松弛使顶点k到生成树的距离变近
            if (book[k] == 0 && dis[k] > e[j][k])
                dis[k] = e[j][k];
        }
    }
    // end counting time
    end = clock();
    printf("\n%d\n", sum);
    printf("time=%.6f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
