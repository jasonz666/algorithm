// simple bucket sort
#include <stdio.h>
int main(void){
    int bucket[100] = {0};
    int data[9] = {8, 2, 1, 5, 5, 9, 5, 9, 7};
    int len = 9, max = 100;
    int i, j;

    for (i = 0; i < len; i++){
        bucket[data[i]] += 1;
    }

    // display
    for (i = 0; i < max; i++)
        for (j = 0; j < bucket[i]; j++)
            printf("%d ", i);
    putchar('\n');

    return 0;
}
