// bellman_ford_queue.c
// 单源最短路使用队列优化
// 啊哈算法 p174
#include <stdio.h>
int main(void){
    int n, m, i, k;
    int u[8], v[8], w[8]; // uvw数组大小比m值大1
    int first[6] = {0}, next[8]; // 同样first比n值大1,next比m值大1
    int dis[6] = {0}, book[6] = {0}; // book数组标记哪些点已在队列中
    int que[100] = {0}, head = 1, tail = 1; // 定义队列
    int inf = 999999;

    // 读入顶点数n边数m
    scanf("%d %d", &n, &m);

    // 初始化dis数组
    for (i = 1; i <= n; i++)
        dis[i] = inf;
    dis[1] = 0;

    // 这里用邻接表存储图详见p161
    for (i = 1; i <= m; i++){
        // 读取每一条边
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        // 建立邻接表
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    // 1号顶点入队
    que[tail++] = 1;
    book[1] = 1; // 标记1号顶点已经入队

    while (head < tail){
        // 当前需要处理的队首顶点
        k = first[que[head]];
        while (k != 0){ // 扫描当前顶点的所有边
            if (dis[v[k]] > dis[u[k]] + w[k]){ // 判断是否松弛成功
                dis[v[k]] = dis[u[k]] + w[k];
                if (book[v[k]] == 0){ // 表示该顶点不在队列中
                    que[tail++] = v[k];
                    book[v[k]] = 1;
                }
            }
            k = next[k];
        }
        // 出队
        book[que[head]] = 0; // 当前顶点最短路下次可能再次更新所以重置为0
        head++;
    }

    // 输出结果
    for (i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    putchar('\n');
    return 0;
}
