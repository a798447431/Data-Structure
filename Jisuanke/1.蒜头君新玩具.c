/*************************************************************************
	> File Name: 1.蒜头君新玩具.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月13日 星期二 10时01分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define swap(a, b) { \
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

typedef struct priority_queue {
    double *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (double *)malloc(sizeof(double) * n + 1);
    q->cnt = 0, q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt = 0;
}

double top(priority_queue *q) {
    return q->data[1];
} 

/*
int push(priority_queue *q, double val) {
    if (q->cnt == q->size) return 0;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind != 1 && q->data[ind] < q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}
*/

void push(priority_queue *q, double val) {
    if (q->size == q->cnt) return ;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind != 1 && q->data[ind] < q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

/*
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
*/

void pop(priority_queue *q) {
    if (empty(q)) return ;
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
    return ;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(priority_queue *q) {
    for (int i = 0; i < q->size; i++) {
        printf("%lf ", q->data[i]);
    }
    printf("\n");
    return ;
}

double func(double a, double b) {
    return pow((a * pow(b, 2.0)), 1.0 / 3);
}

int main() {
    int n;
    double a;
    scanf("%d", &n);
    priority_queue *q = init(n - 1);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a);
        push(q, a);
        printf("%lf ", a);
    }
    printf("\n");
    output(q);
    printf("func(1.0, 2.0) = %lf\n", func(1.0, 2.0)); 
    return 0;
}
