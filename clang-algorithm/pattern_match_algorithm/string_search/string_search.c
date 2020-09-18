// 字符串搜索简单算法
// 写给大家看的算法书 p140
#include <stdio.h>
#include <string.h>

// 参数为字符串,字符串长度,子串,子串长度
int strFind(const char str[], int strlen, const char sub[], int sublen){
    int i, j;

    i = 0; // 字符串比较的起始位置
    j = 0; // 子字符串的起始位置
    while (i + sublen <= strlen){
        while (j < sublen){
            if (str[i] != sub[j]){
                i = i - j + 1; // 字符串比较位置往后移动1位
                j = 0; // 子字符串比较位置重置为开头
                break;
            }
            if (str[i] == sub[j]){
                i++;
                j++;
            }
        }
        if (j == sublen)
            return i - j; // 返回子字符串的位置
    }
    return -1; // 没有找到位置
}

int main(void){
    char str[100] = "ABBBACCDFFE";
    char sub[10] = "BBA";
    int pos, len1, len2;

    len1 = strlen(str);
    printf("%s\n", str);
    puts("input a sub-string:");
    scanf("%s", sub);
    len2 = strlen(sub);
    pos = strFind(str, len1, sub, len2);
    printf("%d\n", pos);

    return 0;
}
