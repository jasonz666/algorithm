// 对成绩进行排位
#include <stdio.h>
int main(void){
    int rank[100] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int score[100] = {40, 13, 89, 52, 7};
    int i, j;
    int len=5;

    for (i=0; i<len; i++){
        for (j=0; j<len; j++){
            if (score[i] < score[j]){
                rank[i] += 1;
            }
        }
    }
    
    // print two arrays
    for (i=0; i<len; i++){
        printf("%d  ", score[i]);
    }
    putchar('\n');
    for (i=0; i<len; i++){
        printf("%d  ", rank[i]);
    }
    putchar('\n');

    return 0;
}
