// 最少转机(飞机转机)
// 无权图最短路径
// 广度优先搜索
// aha! algorithms, p144
#include <stdio.h>
#define M 999999
struct node {
    int x;
    int s;
};
int count = 0;
int main(void){
    struct node que[100];
    int e[50][50] = {{0}}, book[100] = {0};
    int head, tail, i, j, n, m, a, b;
    int cur, start, end, flag = 0;

    scanf("%d %d %d %d", &n, &m, &start, &end);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = M;
        }
    }

    for (i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    head = tail = 1;
    que[tail].x = start;
    que[tail++].s = 0;
    book[start] = 1;

    while (head < tail){
        cur = que[head].x;
        for (i = 1; i <= n; i++){
            if (e[cur][i] != M && book[i] == 0){
                que[tail].x = i;
                que[tail++].s = que[head].s + 1;
                book[i] = 1;
            }
            count++;
            if (que[tail - 1].x == end){
                flag = 1;
                break;
            }
        }
        if (1 == flag)
            break;
        head++;
    }

    printf("%d, count=%d\n", que[tail - 1].s, count);
    return 0;
}
