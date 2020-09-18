// adjacency_list_linked.c
// 邻接表存储图使用链表实现
// 测试数据
// 4 5 1 4 9 4 3 8 1 2 5 2 4 6 1 3 7
#include <stdio.h>
#include <stdlib.h>
struct node {    // 边表节点,存储邻接点
    int adjvex;  // 邻接点
    int len;     // 权值
    struct node * next;
};

struct {         // 顶点表节点,存储每个顶点
    char vertex; // 顶点名
    struct node * first; // 第一个邻接点
} vertexList[10] = {'0', NULL};

int main(void){
    int n, m, i, j, k, l;
    struct node * s;

    scanf("%d %d", &n, &m); // 读入顶点和边数

    // 读入每条边
    for (i = 1; i <= m; i++){
        scanf("%d %d %d", &j, &k, &l);
        s = (struct node *)malloc(sizeof(struct node));
        s->adjvex = k; // 顶点的下个邻接点
        s->len = l;    // 权值
        s->next = vertexList[j].first;
        vertexList[j].first = s; // 下个邻接点插到顶点之后
    }

    // 遍历每个顶点
    for (i = 1; i <= n; i++){
        s = vertexList[i].first;
        while (s != NULL){
            printf("%d %d %d\n", i, s->adjvex, s->len);
            s = s->next;
        }
    }
    return 0;
}
