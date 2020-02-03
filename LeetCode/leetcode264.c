/*************************************************************************
	> File Name: leetcode264.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月11日 星期日 17时00分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

typedef struct priority_queue {
    long long *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->size = n + 1;
    q->data = (long long *)malloc(sizeof(long long) * q->size);
    q->cnt = 0;
    return q;  
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

long long top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, long long val) {
    if (q->size == q->cnt) return 0;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind != 1 && q->data[ind] < q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[l] < q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] < q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int nthUglyNumber(int n) {
    priority_queue *q = init(3 * n);
    push(q, 1);
    long long ans = 0;
    while (n--) {
        ans = top(q);
        pop(q);
        if (ans % 5 == 0) {
            push(q, 5 * ans);
        } else if (ans % 3 == 0) {
            push(q, 3 * ans);
            push(q, 5 * ans);
        } else {
            push(q, 2 * ans);
            push(q, 3 * ans);
            push(q, 5 * ans);
        }
    }
    clear(q);
    return ans;
}

int main() {
    int n;
    long long num = 0;
    scanf("%d", &n);
    num = nthUglyNumber(n);
    printf("%lld\n", num);
    return 0;
}
