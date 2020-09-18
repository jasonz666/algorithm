// 最短路径算法
// 广度优先搜索
// 使用循环实现
// aha! algorithms, p92
#include <stdio.h>
struct node {
    int x; // 横坐标
    int y; // 纵坐标
    int f; // 当前路径点的父路径点的队列下标,为了输出完整路径
    int s; // 走过的步数
};

int main(void){
    struct node queue[26]; // 地图大小为5x5,数组从下标1开始
    int a[51][51] = {{0},  // 地图初始化,下标从1开始
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0}};
    int book[51][51] = {{0}}; // 路径点标记数组
    int next[4][2] = { // 方向计算数组
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};
    int head, tail; // 队列的头尾索引
    int idx, k, n, m, startx, starty, p, q, tx, ty, flag;
    int path[25];

    n = m = 5; // 地图的行列数为5
    startx = starty = 1;
    p = 4; q = 3;

    // 队列初始化
    head = tail = 1;
    // 迷宫入口坐标入队
    queue[tail].x = startx;
    queue[tail].y = starty;
    queue[tail].f = queue[tail].s = 0;
    tail++;
    // 标记起点表示已走过
    book[startx][starty] = 1;
    // 用于标记是否到终点
    flag = 0;

    // 队列不为空时循环
    // 当head==tail表示所有经过的点已扩展
    while (head < tail){
        // 枚举4个方向
        for (k = 0; k < 4; k++){
            tx = queue[head].x + next[k][0];
            ty = queue[head].y + next[k][1];
            // 判断是否越界
            if (tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            // 判断是否遇到障碍物或已经过该点
            if (a[tx][ty] == 0 && book[tx][ty] == 0){
                // 标记为已经过的点
                book[tx][ty] = 1;
                // 插入新点到队列
                queue[tail].x = tx;
                queue[tail].y = ty;
                // 记录上一个点的队列下标
                // 相当于反向链表用于输出整个路径点
                queue[tail].f = head;
                // 步数为父步数+1
                queue[tail].s = queue[head].s + 1;
                tail++;
            }
            // 判断下一个是否遇到终点
            if (tx == p && ty == q){
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            break;
        }
        head++; // 扩展完一个点后出队列才能对后面的点继续扩展下去
    }

    // 打印步数
    printf("%d\n", queue[tail-1].s);
    // 打印路径点
    for (idx = 0, k = tail - 1; k >= 1; ){ // 反向遍历路径点
        path[idx++] = k;
        k = queue[k].f;
    }
    for (k = idx - 1; k >= 0; k--){
        printf("(%d,%d) ", queue[path[k]].x, queue[path[k]].y);
    }
    putchar('\n');

    return 0;
}
