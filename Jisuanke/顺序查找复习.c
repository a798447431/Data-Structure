/*************************************************************************
	> File Name: 顺序查找复习.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月14日 星期三 09时26分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int search(int *data, int length, int value) {
    int time = 0;
    for (int i = 0; i < length; i++) {
        ++time;
        if (data[i] == value) {
            printf("%d %d\n", time, i);
            return i;
        } else if (data[i] > value) {
            printf("%d failed\n", time);
            return -1;
        }
    }
     printf("%d failed\n", time);
    return -1;
}

int main() {
    int n, m, ans;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ans);
        search(arr, n, ans);
    }
    return 0;
}
