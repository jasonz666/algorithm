// 水管工游戏
// bfs应用
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
// 坐标存储队列
struct node {
    int x;
    int y;
    int front;
    int prev;
} queue[100];

int main(void){
    int head, tail;
    int x, y, front;
    int i;

    head = tail = 1;
    // 起点坐标入队
    queue[tail].x = 1;
    queue[tail].y = 1;
    // 记录前一个点的队列编号为了输出完整通路
    queue[tail].prev = 0;
    queue[tail++].front = 1;
    // bfs core
    while (head < tail){
        x = queue[head].x;
        y = queue[head].y;
        front = queue[head].front;
        if (x == n && y == m + 1){
            flag = 1;
            break;
        }
        if ((x >= 1 && x <= n) && (y >= 1 && y <=m) && (book[x][y] == 0)){
            book[x][y] = 1;
            if (a[x][y] >= 5 && a[x][y] <= 6){
                if (1 == front){
                    queue[tail].x = x;
                    queue[tail].y = y + 1;
                    queue[tail].prev = head;
                    queue[tail++].front = 1;
                }
                if (2 == front){
                    queue[tail].x = x + 1;
                    queue[tail].y = y;
                    queue[tail].prev = head;
                    queue[tail++].front = 2;
                }
                if (3 == front){
                    queue[tail].x = x;
                    queue[tail].y = y - 1;
                    queue[tail].prev = head;
                    queue[tail++].front = 3;
                }
                if (4 == front){
                    queue[tail].x = x - 1;
                    queue[tail].y = y;
                    queue[tail].prev = head;
                    queue[tail++].front = 4;
                }
            }
            if (a[x][y] >= 1 && a[x][y] <= 4){
                if (1 == front){
                    queue[tail].x = x + 1;
                    queue[tail].y = y;
                    queue[tail].prev = head;
                    queue[tail++].front = 2;
                    queue[tail].x = x - 1;
                    queue[tail].y = y;
                    queue[tail].prev = head;
                    queue[tail++].front = 4;
                }
                if (2 == front){
                    queue[tail].x = x;
                    queue[tail].y = y + 1;
                    queue[tail].prev = head;
                    queue[tail++].front = 1;
                    queue[tail].x = x;
                    queue[tail].y = y - 1;
                    queue[tail].prev = head;
                    queue[tail++].front = 3;
                }
                if (3 == front){
                    queue[tail].x = x - 1;
                    queue[tail].y = y;
                    queue[tail].prev = head;
                    queue[tail++].front = 4;
                    queue[tail].x = x + 1;
                    queue[tail].y = y;
                    queue[tail].prev = head;
                    queue[tail++].front = 2;
                }
                if (4 == front){
                    queue[tail].x = x;
                    queue[tail].y = y + 1;
                    queue[tail].prev = head;
                    queue[tail++].front = 1;
                    queue[tail].x = x;
                    queue[tail].y = y - 1;
                    queue[tail].prev = head;
                    queue[tail++].front = 3;
                }
            }
        }
        head++;
    }
    if (flag == 0)
        printf("impossible\n");
    for (i = queue[head].prev; i >= 1; ){
        printf("(%d,%d) ", queue[i].x, queue[i].y);
        i = queue[i].prev;
    }
    putchar('\n');
    return 0;
}
