// bellman_ford.c
// 能处理负权边的单源最短路算法
// 对有所有边进行n-1次松弛操作其中n为顶点个数
// 啊哈算法 p168
#include <stdio.h>
int main(void){
    int dis[10], i, k, n, m, u[10], v[10], w[10];
    int inf = 9999, check, flag;

    // n表示顶点数,m表示边数
    scanf("%d %d", &n, &m);

    // 读入所有边
    for (i = 1; i <= m; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    // 初始化dis数组
    for (i = 1; i <= n; i++)
        dis[i] = inf;
    dis[1] = 0;

    // bellman_ford核心算法
    for (k = 1; k <= n - 1; k++){
        check = 0; // 松弛操作是否变化的标记
        for (i = 1; i <= m; i++){
            if (dis[v[i]] > dis[u[i]] + w[i]){
                dis[v[i]] = dis[u[i]] + w[i];
                check = 1; // 发生变化
            }
        }
        if (check == 0) // 如果没有变化即数组dis没有更新
            break;
    }

    // 检查负权回路即n-1次松弛操作后最短路还会变化
    flag = 0;
    for (i = 1; i <= m; i++)
        if (dis[v[i]] > dis[u[i]] + w[i])
            flag = 1;
    if (flag == 1)
        printf("有负权回路");
    else
        for (i = 1; i <= n; i++)
            printf("%d ",dis[i]);
    putchar('\n');
    return 0;
}
