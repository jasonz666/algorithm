// bomb_man_dfs.c
// 啊哈算法 p102
#include <stdio.h>
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
int book[20][20], max, mx, my;
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

void dfs(int x, int y){
    int k, sum, tx, ty;
    sum = getnum(x, y);
    if (sum > max){
        max = sum;
        mx = x;
        my = y;
    }

    for (k = 0; k < 4; k++){
        tx = x + next[k][0];
        ty = y + next[k][1];
        
        if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1)
            continue;
        if (a[tx][ty] == '.' && book[tx][ty] == 0){
            book[tx][ty] = 1;
            dfs(tx, ty);
            // don't need to reset book[tx][ty] = 0;
        }
    }
    return;
}

int main(void){
    book[startx][starty] = 1;
    max = getnum(startx, starty);
    mx = startx;
    my = starty;
    dfs(startx, starty);

    printf("bomb at (%d,%d), kill %d enemies\n", mx, my, max);
    return 0;
}
