/*************************************************************************
	> File Name: 折半查找复习.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月14日 星期三 10时04分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int search(int *data, int length, int value) {
    int time = 0, left = 0, right = length - 1; 
    while (left <= right) {
        ++time;
        int mid = (left + right) / 2;
        if (data[mid] == value) {
            printf("%d success\n", time);
            return mid;
        } else if (data[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
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

