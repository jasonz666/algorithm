// floyd_warshall.c
// 多源最短路径算法
// 基本思想是中转
// 啊哈算法 p152
#include <stdio.h>
// 用无穷大值M表示路不通
// M值计算依据：最大边的值(12) * 所有边数(顶点数的平方即4*4)
#define M 192

// 输出任意两点之间的路径
void pntPath(int p[][5][5], int start, int end){
    int k;
    if ((k = p[start][end][start]) == 0){ // 起点到终点之间的中转点赋值为k
        printf("%d->", end); // 等于0时表示无中转点
        return;
    } else {
        pntPath(p, start, k); // 找出起点与中转点之间的中转点
        pntPath(p, k, end); // 找出中转点与终点之间的中转点
    }
}

int main(void){
    int e[10][10] = {{0},
        {0, 0, 2, 6, 4},
        {0, M, 0, 3, M},
        {0, 7, M, 0, 1},
        {0, 5, M, 12, 0}
    };
    int k, i, j, n;
    // 路径存储
    int p[5][5][5] = {{{0}}};

    n = 4; // 顶点数为4
    // floyd_warshall核心算法
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                // i到k和k到j都小于M防止i到k到j的距离都为M时相加的值溢出
                if (e[i][k] < M && e[k][j] < M && e[i][j] > e[i][k] + e[k][j]){
                    e[i][j] = e[i][k] + e[k][j];
                    p[i][j][i] = k; // 起点i的下个中转点是k
                }

    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++)
            printf("%4d", e[i][j]);
        putchar('\n');
    }

    // 输出路径
    putchar('\n');
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i != j){ // 排除顶点自己到自己
                printf("%d->", i); // 起点
                pntPath(p, i, j);
                putchar('\n');
            }
        }
    }
    return 0;
}
