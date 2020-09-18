// min_spanning_tree_prim_optimize.c
// 图的最小生成树
// prim最小生成树算法针对顶点来处理
// 使用堆和邻接表优化
// 啊哈算法 p224
// 测试数据
// 6 9 2 4 11 3 5 13 4 6 3 5 6 4 2 3 6 4 5 7 1 2 1 3 4 9 1 3 2
#include <stdio.h>
#include <time.h>
int dis[7], book[7] = {0}; // book数组记录已加入生成树的顶点
int h[7], pos[7], size; // h保存堆,pos保存每个顶点在堆中的位置,size为堆大小
int start, end;

// 交换堆中两个元素的值同时更新pos数组
void swap(int x, int y){
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
    t = pos[h[x]];
    pos[h[x]] = pos[h[y]];
    pos[h[y]] = t;
}

// 向下调整元素以维持最小堆
void siftdown(int i){ // 参数为需要下调的节点编号
    int t;
    while (i * 2 <= size){
        // 比较i和左儿子i*2在dis中的值并记录较小的节点编号
        if (dis[h[i]] > dis[h[i * 2]])
            t = i * 2;
        else
            t = i;
        // 存在右儿子则比较
        if (i * 2 + 1 <= size){
            if (dis[h[t]] > dis[h[i * 2 + 1]])
                t = i * 2 + 1;
        }
        // 需要交换
        if (t != i){
            swap(t, i);
            i = t;
        }
        else
            break;
    }
}

// 上调元素以维持松弛成功的节点在最小堆中位置
void siftup(int i){ // 参数为需要上调的节点编号
    while (i != 1){ // 节点不在堆顶时判断是否要上调
        if (dis[h[i]] < dis[h[i / 2]])
            swap(i, i / 2);
        else
            break;
        i = i / 2;
    }
}

// 从堆顶取出元素,该元素为离生成树最近的非树节点
int pop(void){
    int t;
    t = h[1];
    h[1] = h[size]; // 堆中最后元素放到堆顶
    pos[h[1]] = 1;  // 更新最后元素此时在堆中位置
    size--;
    siftdown(1);   // 维持最小堆,此时离生成树最近的非树顶点会在堆顶
    return t;
}

int main(void){
    int n, m, i, j, k;
    // uvw,next数组比2*m值大1,first比n值大1
    int u[19], v[19], w[19], next[19], first[7];
    int inf = 999999; // 定义一个无穷大值
    int count = 0, sum = 0; // 分别为顶点计数变量,路径之和

    // 读入顶点和边数
    scanf("%d %d", &n, &m);

    // 读入每个边
    for (i = 1; i <= m; i++){
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    // 无向图需要反向存储一次
    for (i = m + 1; i <= 2 * m; i++){
        u[i] = v[i - m];
        v[i] = u[i - m];
        w[i] = w[i - m];
    }

    // 使用邻接表存储边
    for (i = 1; i <= n; i++)
        first[i] = -1;
    for (i = 1; i <= 2 * m; i++){
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    printf("1"); // 打印起始顶点1
    // prim核心算法
    // start counting time
    start = clock();
    book[1] = 1;
    count++;
    // 初始化dis数组,这里是1号顶点到其他各顶点的初始距离
    dis[1] = 0;
    for(i = 2; i <= n; i++)
        dis[i] = inf; // 使用邻接表时初始化为无穷大
    k = first[1]; // 1号顶点第一条边的编号
    while (k != -1){
        dis[v[k]] = w[k]; // 1号顶点到邻接点的距离
        k = next[k]; // 1号顶点下个邻接点
    }
    // 初始化堆
    size = n;
    for (i = 1; i <= n; i++){
        h[i] = i;
        pos[i] = i;
    }
    for (i = size / 2; i >= 1; i--)
        siftdown(i); // 根据dis数组的值调整堆
    pop(); // 弹出1号顶点加入生成树即上面的count++
    while (count < n){
        j = pop(); // 堆顶的值是离生成树最近的顶点
        book[j] = 1; count++; sum += dis[j];
        printf("->%d", j); // 打印该顶点
        // 松弛操作
        k = first[j];
        while (k != -1){
            if (book[v[k]] == 0 && dis[v[k]] > w[k]){
                dis[v[k]] = w[k];
                siftup(pos[v[k]]); // 对松弛成功的顶点调整在堆中位置
            }
            k = next[k];
        }
    }
    // end counting time
    end = clock();
    printf("\n%d\n", sum);
    printf("time=%.6f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
