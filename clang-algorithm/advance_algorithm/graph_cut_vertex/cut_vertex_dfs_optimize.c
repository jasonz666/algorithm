// 图的割点
// 使用优化的dfs算法
// 啊哈算法 p232
// 测试数据 其中第1和2两值为顶点数和边数
// 接下来每两值为一对表示这两顶点之间有边
// 6 7 1 4 1 3 4 2 3 2 2 5 2 6 5 6
#include <stdio.h>
int n, m, e[9][9], root;
int num[9], low[9], flag[9], idx; // idx记录时间戳的递增

// 割点核心算法
void dfs(int cur, int father){ // 参数为顶点编号和父顶点编号
    int child = 0, i; // child记录当前顶点cur的儿子个数

    idx++; // 时间戳+1
    num[cur] = idx; // 当前顶点cur被访问时的时间戳
    low[cur] = idx; // cur能访问的最早的时间戳起初是自己
    for (i = 1; i <= n; i++){ // 枚举cur顶点的所有出边
        if (e[cur][i] == 1){ // cur->i有边存在
            if (num[i] == 0){ // 顶点i还未被访问过
                // dfs遍历图会得到生成树此时i为cur的儿子
                child++;
                dfs(i, cur); // i为新节点cur为父节点然后继续遍历
                // 更新当前顶点cur不经过父节点能到达的最早时间戳
                // 不经过父节点即cur经过子节点能到达的最小时间戳
                low[cur] = low[cur] < low[i]? low[cur]: low[i];
                if (cur != root && low[i] >= num[cur])
                    flag[cur] = 1; // 找到割点
                // 如果cur是根节点则它至少有两个儿子才是割点
                if (cur == root && child == 2)
                    flag[cur] = 1;
                // 如果i被访问过但不是cur的父亲则i为cur的祖先
                // 所以更新cur节点能到达的最早的时间戳
            } else if (i != father)
                low[cur] = low[cur] < num[i]? low[cur]: num[i];
        }
    }
}

int main(void){
    int i, x, y;
    //int j;

    // 读取顶点和边数
    scanf("%d %d", &n, &m);

    // 以下3句可以省略因为全局变量e初始为0
    /* for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            e[i][j] = 0; */

    // 读取每条边
    for (i = 1; i <= m; i++){
        scanf("%d %d", &x, &y);
        e[x][y] = 1; // 可以使用邻接表来优化
        e[y][x] = 1;
    }

    root = 1; // 根节点为1号节点
    dfs(1, root); // 从1号顶点开始

    for (i = 1; i <= n; i++)
        if (flag[i] == 1)
            printf("%d\n", i); // 输出割点编号
    return 0;
}
