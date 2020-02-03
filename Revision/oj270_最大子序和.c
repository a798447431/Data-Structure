/*************************************************************************
	> File Name: oj270_最大子序和.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月10日 星期二 19时06分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300000
#define max(a, b) ((a) > (b) ? (a) : (b))

int q[MAX_N + 5], head, tail;
long long arr[MAX_N + 5];

int main() {
    long long n, m, ans;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0;
    ans = arr[1];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    printf("%lld\n", ans);
    return 0;
}
