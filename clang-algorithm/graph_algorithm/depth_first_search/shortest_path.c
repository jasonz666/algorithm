// 最短路径算法
// 深度优先搜索
// 使用递归实现
// aha! algorithms, p85
#include <stdio.h>
int n = 5, m = 4, p = 4, q = 3, min, flag = 0;
int a[51][51] = {{0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}};
int book[51][51]; // 地图尺寸50x50
int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // 方向数组

// store path coordinates
struct path {
    int x;
    int y;
} path_arr[25], path_min[25];
// array of struct index
int idx = 0, idx_min;

void dfs(int x, int y, int step){
    int tx, ty, k;

    // 判断是否到达小哈的位置
    if (x == p && y == q){
        if (!flag){
            min = step; // 获得最短路径的初始值
            // copy a path to path_min
            for (k = 0; k < idx; k++)
                path_min[k] = path_arr[k];
            idx_min = idx;
            flag = 1;
        } else if (step < min){
            min = step;
            // copy a path to path_min
            for (k = 0; k < idx; k++)
                path_min[k] = path_arr[k];
            idx_min = idx;
        }
        return;
    }

    // 枚举4个方向
    for (k = 0; k < 4; k++){
        // 计算下一个点的坐标
        tx = x + next[k][0];
        ty = y + next[k][1];
        // 判断是否越界
        if (tx < 1 || tx > n || ty < 1 || ty > m)
            continue;
        // 判断该点是否为障碍物或已经在路径中
        if (a[tx][ty] == 0 && book[tx][ty] == 0){
            book[tx][ty] = 1; // 标记该点表示已走过
            // store this coordinate to struct
            path_arr[idx].x = tx;
            path_arr[idx++].y = ty;
            dfs(tx, ty, step + 1); // 尝试下一个点
            book[tx][ty] = 0; // 返回后取消该点的标记
            // cancel this coordinate
            idx--;
        }
    }
    return;
}

int main(void){
    int startx, starty, i;

    // 从起点开始搜索
    startx = starty = 1;
    book[startx][starty] = 1; // 标记起点防止重复经过
    dfs(startx, starty, 0);

    // 输出最短路径
    printf("%d\n", min);
    // print the shortest path
    printf("(%d,%d) ", startx, starty);
    for (i = 0; i<idx_min; i++)
        printf("(%d,%d) ", path_min[i].x, path_min[i].y);
    putchar('\n');

    return 0;
}
