/*************************************************************************
	> File Name: 哪位同学最优秀.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月06日 星期二 09时46分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int *data;
    int size;
    int length;
} Vector;

Vector *init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 1;
    if (vec->length == vec->size) return 1;
    if (ind < 0 || ind > vec->length) return 1;
    for (int i = vec->length - 1; i > ind; i++) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 0;
}

int erase(Vector *vec, int ind) {
    if (vec == NULL) return 1;
    if (vec->length == 0) return 1;
    if (ind < 0 || ind > vec->length - 1) return 1;
    for (int i = ind + 1; i < vec->length; i++) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 0;
}

void print(Vector *vec) {
    if (vec == NULL) return ;
    for (int i = 0; i < vec->length; i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
    return ;
}

void clear(Vector *vec) {
    if (vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}

int main() {
    int n, m, num, mid;
    scanf("%d%d", &n, &m);
    Vector *vec = init(n);
    for (int i = 0; i < n; i++) {
        insert(vec, i, i + 1);
    }
    print(vec);
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        erase(vec, num - 1);
    }
    print(vec);
    mid = vec->length / 2;
    printf("%d\n", vec->data[mid]);

    return 0;
}
