// 二分图最大匹配
// 匈牙利算法实现
// 啊哈算法 p240
// 测试数据 前两个为顶点数和边数
// 后面两个数为一对表示二分图的边
// 顶点1 2 3为女生 顶点4 5 6为男生
// 6 5 1 4 1 5 2 5 2 6 3 4
#include <stdio.h>
int e[100][100]; // 存储图
int match[100];  // 记录配对关系
int book[100];  // 记录访问过的顶点
int n, m;  // 顶点数和边数

int dfs(int u){
    int i;

    for (i = 1; i <= n; i++){
        if (book[i] == 0 && e[u][i] == 1){ // 顶点u的配对顶点i需满足的条件
            book[i] = 1; // 标记i已被访问以免递归时此顶点被重复访问
            // 如果i顶点未配对或i顶点的配对顶点找到了新配对
            if (match[i] == 0 || dfs(match[i])){
                // 更新配对关系
                match[u] = i;
                match[i] = u;
                printf("%d->%d\n", u, i);
                return 1; // 成功找到一个配对
            }
        }
    }
    return 0;
}

int main(void){
    int i, j, t1, t2, sum = 0;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= m; i++){
        scanf("%d %d", &t1, &t2);
        e[t1][t2] = 1;
        e[t2][t1] = 1;
    }

    for (i = 1; i <= n; i++)
        match[i] = 0;

    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++)
            book[j] = 0; // 清空上次搜索时的标记
        if (dfs(i))
            sum++;  // 寻找增广路如果找到则配对数+1
    }

    printf("%d\n", sum);
    return 0;
}
