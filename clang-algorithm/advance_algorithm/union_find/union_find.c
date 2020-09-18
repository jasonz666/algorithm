// union_find.c
// 并查集,擒贼先擒王
// 啊哈算法 p208
// 测试数据
// 10 9 1 2 3 4 5 2 4 6 2 6 8 7 9 7 1 6 2 4
#include <stdio.h>
int f[100], n, m, k, sum = 0;

void init(void){
    int i;
    for (i = 1; i <= n; i++)
        f[i] = i;
}

int getFather(int v){
    if (f[v] == v)
        return v;
    else {
        f[v] = getFather(f[v]);
        return f[v];
    }
}

void merge(int v, int u){
    int t1, t2;
    t1 = getFather(v);
    t2 = getFather(u);
    if (t1 != t2)
        f[t2] = t1;
}

int main(void){
    int i, x, y;
    scanf("%d %d", &n, &m);
    init();
    for(i = 1; i <= m; i++){
        scanf("%d %d", &x, &y);
        merge(x, y);
    }
    for (i = 1; i <= n; i++){
        if (f[i] == i)
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}
