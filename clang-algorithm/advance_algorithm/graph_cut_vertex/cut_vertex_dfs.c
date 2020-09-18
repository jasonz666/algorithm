// 图的割点
// 深度优先搜索算法实现
// 使用邻接矩阵存储图
// 测试数据 其中第1和2两值为顶点数和边数
// 接下来每两值为一对表示这两顶点之间有边
// 6 7 1 4 1 3 4 2 3 2 2 5 2 6 5 6
#include <stdio.h>
int e[7][7];    // 存储图的矩阵
int vertex[7];  // 标记被删除的顶点
int book[7];    // 标记遍历过的顶点
int sum;
int n, m;            // n为顶点数,m为边数

void dfs(int cur){   // 参数为顶点编号
    int i;

    sum++;
    book[cur] = 1;
    if (sum == n - 1)
        return; // 当遍历n-1个顶点时返回即除被删除点以外的其他顶点
    for (i = 1; i <= n; i++){
        // cur到i顶点存在边且此点未曾遍历且该点不是被删除的顶点
        if (e[cur][i] == 1 && book[i] == 0 && vertex[i] == 0){
            dfs(i);
        }
    }
}

int main(void){
    int i, j, k;
    int t1, t2;

    // 读入顶点和边数
    scanf("%d %d", &n, &m);
    // 初始化矩阵
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j)
                e[i][j] = 0;
        }
    }
    // 读入每条边
    for (i = 1; i <= m; i++){
        scanf("%d %d", &t1, &t2);
        e[t1][t2] = 1;
        e[t2][t1] = 1; // 无向图需要反向存储
    }
    // 尝试删除每个顶点来找出割点
    for (i = 1; i <= n; i++){
        for (k = 1; k <= n; k++)
            book[k] = 0; // 重置
        vertex[i] = 1;   // 标记删除的顶点
        sum = 0;
        if ( 1 == i)
            dfs(2);
        else
            dfs(i - 1);
        if (sum < n - 1) // 图被分割成至少两部分即找到割点
            printf("%d\n", i);
        vertex[i] = 0;  // 重置为0
    }

    return 0;
}
