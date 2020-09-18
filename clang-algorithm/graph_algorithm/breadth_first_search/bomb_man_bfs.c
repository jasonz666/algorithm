// bomb_man_main.c
// 啊哈算法 p98
#include <stdio.h>
struct node {
        int x;
        int y;
};
char a[20][21] = {
    "#############",
    "#GG.GGG#GGG.#",
    "###.#G#G#G#G#",
    "#.......#..G#",
    "#G#.###.#G#G#",
    "#GG.GGG.#.GG#",
    "#G#.#G#.#.#.#",
    "##G...G.....#",
    "#G#.#G###.#G#",
    "#...G#GGG.GG#",
    "#G#.#G#G#.#G#",
    "#GG.GGG#G.GG#",
    "#############"
};
int startx = 3, starty = 3;
int n = 13, m = 13;
int next[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

int getnum(int i, int j){
    int sum, x, y;
    sum = 0;

    x = i; y = j;
    while (a[x][y] != '#'){
        if (a[x][y] =='G')
            sum++;
        x--;
    }

    x = i; y = j;
    while (a[x][y] != '#'){
        if (a[x][y] =='G')
            sum++;
        x++;
    }

    x = i; y = j;
    while (a[x][y] != '#'){
        if (a[x][y] =='G')
            sum++;
        y--;
    }

    x = i; y = j;
    while (a[x][y] != '#'){
        if (a[x][y] =='G')
            sum++;
        y++;
    }

    return sum;
}

int main(void){
    struct node que[400];
    int head, tail;
    int book[20][20] = {{0}};
    int k, sum, max = 0, mx, my, tx, ty;

    // init queue
    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    max = getnum(startx, starty);
    mx = startx;
    my = starty;
    // bfs core code
    while (head < tail){
        for (k = 0; k < 4; k++){
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];

            if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1)
                continue;
            if (a[tx][ty] == '.' && book[tx][ty] == 0){
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;

                sum = getnum(tx, ty);
                if (sum > max){
                    max = sum;
                    mx = tx;
                    my= ty;
                }
            } // end if
        } // end for
        head++;
    }

    printf("bomb at (%d,%d), kill %d enemies\n", mx, my, max);
    return 0;
}
