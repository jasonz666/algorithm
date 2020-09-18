// 水管工游戏
// dfs应用
// aha! algorithms, p124
#include <stdio.h>
int n = 5, m = 4, flag = 0;
// 地图下标从1开始
int a[50][50] = {{0},
    {0, 5, 3, 5, 3},
    {0, 1, 5, 3, 0},
    {0, 2, 3, 5, 1},
    {0, 6, 1, 1, 5},
    {0, 1, 5, 5, 4}
};
// 标记数组
int book[50][50];
// 路径存储栈
struct node {
    int x;
    int y;
} s[100];
int top = 0;

void dfs(int x, int y, int front){
    int i;
    // 判断是否到达出口
    if (x == n && y == m + 1){
        flag = 1;
        for (i = 0; i < top; i++)
            // 找到并打印水管通路
            printf("(%d,%d) ", s[i].x, s[i].y);
        putchar('\n');
        return;
    }
    // 判断是否越界
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    // 判断此水管是否使用过
    if (book[x][y] == 1)
        return;
    book[x][y] = 1;

    // 当前坐标入栈
    s[top].x = x;
    s[top].y = y;
    top++;

    // 遇到弯水管时情况
    if (a[x][y] >= 1 && a[x][y] <= 4){
        if (1 == front){ // 进水口在左边
            // 使用3号弯管,对于下一个点来说进水口在上
            // 假定进水口左上右下分别用1,2,3,4表示
            dfs(x + 1, y, 2); 
            dfs(x - 1, y, 4); // 使用4号弯管
        }
        if (2 == front){ // 进水口在上边
            dfs(x, y + 1, 1); // 1号弯管
            dfs(x, y - 1, 3); // 4号弯管
        }
        if (3 == front){ // 右边
            dfs(x - 1, y, 4);
            dfs(x + 1, y, 2);
        }
        if (4 == front){ // 下边
            dfs(x, y + 1, 1);
            dfs(x, y - 1, 3);
        }
    }
    // 遇到直水管时的情况
    if (a[x][y] >= 5 && a[x][y] <= 6){
        if (1 == front) // 进水口在左
            dfs(x, y + 1, 1); // 使用5号直管
        if (2 == front) // 在上
            dfs(x + 1, y, 2); // 使用6号直管
        if (3 == front) // 在右
            dfs(x, y - 1, 3); // 使用5号直管
        if (4 == front) // 在下
            dfs(x - 1, y, 4); // 6号
    }
    book[x][y] = 0; // 递归返回后取消该点标记
    top--; // 当前尝试的点出栈
    return;
}

int main(void){
    dfs(1, 1, 1);
    if (0 == flag)
        printf("impossible\n");
    return 0;
}
