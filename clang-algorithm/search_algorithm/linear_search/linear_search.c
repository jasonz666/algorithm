// 写给大家看的算法书 p134
#include <stdio.h>
int main(void){
	int i;
	int num = 3;
	int data[10] = {0, 1, 3, 2, 5, 4, 7, 6, 8, 9};

	for (i = 0; i < 10; i++)
		if (data[i] == num)
			break;
	if (i < 10)
		printf("%d,index=%d\n", data[i], i);
	else
		printf("can't find %d\n", num);

	return 0;
}
