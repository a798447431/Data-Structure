/*************************************************************************
	> File Name: 蒜头君筛选用户名.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月20日 星期二 11时26分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *strlwr(char *str) {
    if(str == NULL) return NULL;         
    char *p = str;
    while (*p != '\0'){
        if(*p >= 'A' && *p <= 'Z')
        *p = (*p) + 0x20;
        p++;
    }
    return str;
}

int search_string(char **arr, int l, int r, char *str) {
    for (int i = r; i > l; i--) {
        if (strcmp(arr[i], str) == 0) return 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    char **arr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        char temp[105] = {0};
        scanf("%s", temp);
        arr[i] = strlwr(temp);
    }
    


    return 0;
}
