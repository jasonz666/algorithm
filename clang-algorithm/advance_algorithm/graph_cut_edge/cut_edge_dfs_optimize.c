// 图的割边
// 使用优化的dfs算法
// 啊哈算法 p235
// 测试数据 其中第1和2两值为顶点数和边数
// 接下来每两值为一对表示这两顶点之间有边
// 6 6 1 4 1 3 4 2 3 2 2 5 5 6
#include <stdio.h>
int n, m, e[9][9], root;
int num[9], low[9], flag[9], idx; 

void dfs(int cur, int father){ 
    int i; 

    idx++; 
    num[cur] = idx; 
    low[cur] = idx; 
    for (i = 1; i <= n; i++){ 
        if (e[cur][i] == 1){ 
            if (num[i] == 0){ 
                // 这里不需要计算儿子节点个数
                // child++;
                dfs(i, cur); 
                low[cur] = low[cur] < low[i]? low[cur]: low[i];
                // 与割点不同的是不需要判断=
                if (low[i] > num[cur])
                    printf("%d->%d\n", cur, i);
            } else if (i != father)
                low[cur] = low[cur] < num[i]? low[cur]: num[i];
        }
    }
}

int main(void){
    int i, x, y;
    
    // 读入顶点和边数
    scanf("%d %d", &n, &m);

    /* for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            e[i][j] = 0; */
    
    for (i = 1; i <= m; i++){
        scanf("%d %d", &x, &y);
        e[x][y] = 1; // 可以使用邻接表优化
        e[y][x] = 1;
    }

    root = 1; 
    dfs(1, root); 
    return 0;
}
