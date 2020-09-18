// adjacency_list.c
// 邻接表存储图使用数组实现
// 测试数据
// 4 5 1 4 9 4 3 8 1 2 5 2 4 6 1 3 7
#include <stdio.h>
int main(void){
    int n, m, i, k;
    // 3个数组大小比m大1
    int u[6], v[6], w[6];
    // first和next数组大小比n大1
    int first[5] = {0}, next[5] = {0};

    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d %d %d", &u[i], &v[i], &w[i]); // 读入每条边
        // first数组存储每个顶点第一条边的编号next数组存储顶点的下条边的编号
        // next[i]存储某个顶点的编号为i的边的下条边的编号
        next[i] = first[u[i]];
        // 顶点u[i]的第一条边是编号为i的边
        first[u[i]] = i;
    }

    // 遍历每个顶点
    for (i = 1; i <= n; i++){
        k = first[i];
        while (k != 0){
            printf("%d %d %d\n", u[k], v[k], w[k]);
            k = next[k];
        }
    }
    return 0;
}
