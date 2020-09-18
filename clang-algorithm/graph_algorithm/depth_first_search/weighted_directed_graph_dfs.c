// 加权有向图最短路径
// 深度优先搜索
// aha! algorithms, p139
#include <stdio.h>
#define MAX 9999999 // 定义无穷大值来表示此路不通
// 最短路径min设为一个极大值
// 顶点为n,边为m,图存储数组e
int min = MAX, book[100], n = 5, m = 8, e[100][100] = {{0},
    {0, 0, 2, MAX, MAX, 10},
    {0, MAX, 0, 3, MAX, 7},
    {0, 4, MAX, 0, 4, MAX},
    {0, MAX, MAX, MAX, 0, 5},
    {0, MAX, MAX, 3, MAX, 0}
};

// 当前所在顶点cur,当前已走过的路程dis
void dfs(int cur, int dis){
    int i;
    // 当前路程大于最短路径则立即返回
    if (dis > min)
        return;
    // 到达目标城市即目标顶点
    if (cur == n){
        if (dis < min)
            min = dis;
        return;
    }
    // 依次遍历1~n号顶点
    for (i = 1; i <= n; i++){
        if (e[cur][i] != MAX && book[i] == 0){
            book[i] = 1;
            dfs(i, dis + e[cur][i]);
            book[i] = 0;
        }
    }
    return;
}

int main(void){
    book[1] = 1;
    dfs(1, 0);
    printf("%d\n", min);
    return 0;
}
