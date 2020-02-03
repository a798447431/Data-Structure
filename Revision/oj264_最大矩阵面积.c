/*************************************************************************
	> File Name: oj264_最大矩阵面积.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月10日 星期二 19时44分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX_N 100000
long long arr[MAX_N + 5], top = -1;
long long s[MAX_N + 5];
long long l[MAX_N + 5], r[MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    arr[0] = arr[n + 1] = -1;
    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    s[++top] = 0;
    for (int i = 1; i <= n; i++) {
        while (arr[s[top]] >= arr[i]) s[top--] = 0;
        l[i] = i - s[top];
        s[++top] = i;
    }
    while (top != -1) s[top--] = 0;
    s[top++] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (arr[s[top]] >= arr[i]) s[top--] = 0;
        r[i] = s[top] - i;
        s[++top] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] * (r[i] + l[i] - 1));
    }
    printf("%lld\n", ans);
    return 0;
}

