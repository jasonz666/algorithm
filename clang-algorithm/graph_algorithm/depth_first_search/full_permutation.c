// 数的全排列
// 深度优先搜索
// aha! algorithms, p78
#include <stdio.h>
#define N 10

int a[N], mark[N]; // 全排列最多9个数字即1~9

void dfs(int step, int n){ // step表示现在站在第几个盒子前面
    int i;
    // 如果在第n+1个盒子面前表示所有数已放进盒子里
    if (step == n + 1){
        // 输出一种排列即1~n号盒子里的数
        for (i = 1; i <= n; i++)
            printf("%d", a[i]);
        putchar('\n');
        // 输出完必须返回
        return;
    }

    // 依次尝试
    for (i = 1; i <= n; i++){
        // 数字是否还没放进盒子里
        if (mark[i] == 0){
            a[step] = i; // 将数字i放进第step个盒子里
            mark[i] = 1; // 此时数字i已经放进盒子了

            // 在下一个盒子继续放数字
            dfs(step + 1, n);
            // 放完后续盒子返回后回收刚才放的数字i才能继续深入
            mark[i] = 0;
        }
    }
    return;
}

int main(void){
    int n;
    puts("input a num(1~9, 0 to quit):");
    scanf("%d", &n);
    while (n != 0){
        dfs(1, n); // 第一次调用时在第1个盒子前面
        puts("input a num(1~9, 0 to quit):");
        scanf("%d", &n);
    }
    return 0;
}
