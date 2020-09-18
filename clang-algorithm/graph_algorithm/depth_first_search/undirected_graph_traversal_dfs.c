// 邻接矩阵存储法图的遍历
// 深度优先搜索
// 啊哈算法，p131
#include <stdio.h>
int book[100], sum, n, e[100][100] = {{0},
    {0, 0, 1, 1, 9, 1},
    {0, 1, 0, 9, 1, 9},
    {0, 1, 9, 0, 9, 1},
    {0, 9, 1, 9, 0, 9},
    {0, 1, 9, 1, 9, 0}
};
int count = 0;

void dfs(int cur){
    int i;
    printf("%d ", cur);
    sum++;
    if (sum == n)
        return;
    for (i = 1; i <= n; i++){
        if (e[cur][i] == 1 && book[i] == 0){
            book[i] = 1;
            dfs(i);
        }
        count++;
    }
}

int main(void){
    n = 5;
    book[1] = 1;
    dfs(1);
    putchar('\n');
    printf("count = %d\n", count);
    return 0;
}
