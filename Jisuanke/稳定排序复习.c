/*************************************************************************
	> File Name: 稳定排序复习.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月14日 星期三 14时04分44秒
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge_sort(int *data, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(data, l, mid);
    merge_sort(data, mid + 1, r);
    int temp[r - l + 1];
    int x = l, y = mid + 1, loc = 0;
    while (x <= mid || y <= r) {
        if (x <= mid && (y >r || data[x] <= data[y])) {
            temp[loc++] = data[x++];
        } else {
            temp[loc++] = data[y++];
        }
    }
    for (int i = l; i <= r; i++) {
        data[i] = temp[i - l];
    }
    return ;
}

void bubble_sort(int *data, int length) {
    for (int i = 0; i < length; i++) {
        int swappd = 0;
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
                printf("%d %d\n", j, j + 1);
                swappd = 1;
            }
        }
        if (swappd == 0) break;
    }
    return ;
}

void insert_sort(int *data, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
                printf("%d %d\n", j, j + 1);
            }
            else break;
        }
    }
    return ;
}

void print(int *data, int length) {
    for (int i = 0; i < length; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", data[i]);
    }
    printf("\n");
}


int main() {
    int m, n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    scanf("%d", &m);
    if (m == 1) {
        insert_sort(a, n);
    } else if (m == 2) {
        bubble_sort(a, n);
    } else if (m == 3) {
        merge_sort(a, 0, n - 1);
    }
    print(a, n);
    return 0;
}
