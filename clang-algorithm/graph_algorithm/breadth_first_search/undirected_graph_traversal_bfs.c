// 邻接矩阵存储法图的遍历
// 广度优先搜索
// 啊哈算法，p134
#include <stdio.h>
int book[100], n = 5, e[100][100] = {{0}, // 9表示无穷大即这两点间不通
    {0, 0, 1, 1, 9, 1},
    {0, 1, 0, 9, 1, 9},
    {0, 1, 9, 0, 9, 1},
    {0, 9, 1, 9, 0, 9},
    {0, 1, 9, 1, 9, 0}
};
int count = 0;

int main(void){
    int que[100], head, tail, cur;
    int i;

    head = tail = 1;
    que[tail++] = 1;
    book[1] = 1;

    while (head < tail && tail <= n){
        cur = que[head];
        for (i = 1; i <= n; i++){
            if (e[cur][i] == 1 && book[i] == 0){
                que[tail++] = i;
                book[i] = 1;
            }
            count++;
            if (tail > n)
                break;
        }
        head++;
    }

    for (i = 1; i < tail; i++)
        printf("%d ", que[i]);
    putchar('\n');
    printf("count = %d\n", count);

    return 0;
}
